// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for cosmus_communication/NetworkComm
#include "boost/date_time.hpp"
#include "boost/shared_array.hpp"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4265)
#pragma warning(disable : 4458)
#pragma warning(disable : 4100)
#pragma warning(disable : 4127)
#pragma warning(disable : 4267)
#pragma warning(disable : 4068)
#pragma warning(disable : 4245)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#endif //_MSC_VER
#include "ros/ros.h"
#include "cosmus_communication/NetworkComm.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class COSMUS_COMMUNICATION_EXPORT cosmus_communication_msg_NetworkComm_common : public MATLABROSMsgInterface<cosmus_communication::NetworkComm> {
  public:
    virtual ~cosmus_communication_msg_NetworkComm_common(){}
    virtual void copy_from_struct(cosmus_communication::NetworkComm* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const cosmus_communication::NetworkComm* msg, MultiLibLoader loader, size_t size = 1);
};
  void cosmus_communication_msg_NetworkComm_common::copy_from_struct(cosmus_communication::NetworkComm* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //comms
        const matlab::data::StructArray comms_arr = arr["Comms"];
        for (auto _commsarr : comms_arr) {
        	cosmus_communication::Communication _val;
        auto msgClassPtr_comms = getCommonObject<cosmus_communication::Communication>("cosmus_communication_msg_Communication_common",loader);
        msgClassPtr_comms->copy_from_struct(&_val,_commsarr,loader);
        	msg->comms.push_back(_val);
        }
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Comms' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Comms' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T cosmus_communication_msg_NetworkComm_common::get_arr(MDFactory_T& factory, const cosmus_communication::NetworkComm* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Comms"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("cosmus_communication/NetworkComm");
    // comms
    auto currentElement_comms = (msg + ctr)->comms;
    auto msgClassPtr_comms = getCommonObject<cosmus_communication::Communication>("cosmus_communication_msg_Communication_common",loader);
    outArray[ctr]["Comms"] = msgClassPtr_comms->get_arr(factory,&currentElement_comms[0],loader,currentElement_comms.size());
    }
    return std::move(outArray);
  } 
class COSMUS_COMMUNICATION_EXPORT cosmus_communication_NetworkComm_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~cosmus_communication_NetworkComm_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          cosmus_communication_NetworkComm_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<cosmus_communication::NetworkComm,cosmus_communication_msg_NetworkComm_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         cosmus_communication_NetworkComm_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<cosmus_communication::NetworkComm,cosmus_communication::NetworkComm::ConstPtr,cosmus_communication_msg_NetworkComm_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         cosmus_communication_NetworkComm_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<cosmus_communication::NetworkComm,cosmus_communication_msg_NetworkComm_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(cosmus_communication_msg_NetworkComm_common, MATLABROSMsgInterface<cosmus_communication::NetworkComm>)
CLASS_LOADER_REGISTER_CLASS(cosmus_communication_NetworkComm_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1