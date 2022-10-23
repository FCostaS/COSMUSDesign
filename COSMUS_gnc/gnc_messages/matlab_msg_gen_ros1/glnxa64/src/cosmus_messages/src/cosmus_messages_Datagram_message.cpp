// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for cosmus_messages/Datagram
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
#include "cosmus_messages/Datagram.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class COSMUS_MESSAGES_EXPORT cosmus_messages_msg_Datagram_common : public MATLABROSMsgInterface<cosmus_messages::Datagram> {
  public:
    virtual ~cosmus_messages_msg_Datagram_common(){}
    virtual void copy_from_struct(cosmus_messages::Datagram* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const cosmus_messages::Datagram* msg, MultiLibLoader loader, size_t size = 1);
};
  void cosmus_messages_msg_Datagram_common::copy_from_struct(cosmus_messages::Datagram* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //ssid
        const matlab::data::CharArray ssid_arr = arr["Ssid"];
        msg->ssid = ssid_arr.toAscii();
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Ssid' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Ssid' is wrong type; expected a string.");
    }
    try {
        //data
        const matlab::data::StructArray data_arr = arr["Data"];
        auto msgClassPtr_data = getCommonObject<cosmus_messages::Vector3D>("cosmus_messages_msg_Vector3D_common",loader);
        msgClassPtr_data->copy_from_struct(&msg->data,data_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Data' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Data' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T cosmus_messages_msg_Datagram_common::get_arr(MDFactory_T& factory, const cosmus_messages::Datagram* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Ssid","Data"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("cosmus_messages/Datagram");
    // ssid
    auto currentElement_ssid = (msg + ctr)->ssid;
    outArray[ctr]["Ssid"] = factory.createCharArray(currentElement_ssid);
    // data
    auto currentElement_data = (msg + ctr)->data;
    auto msgClassPtr_data = getCommonObject<cosmus_messages::Vector3D>("cosmus_messages_msg_Vector3D_common",loader);
    outArray[ctr]["Data"] = msgClassPtr_data->get_arr(factory, &currentElement_data, loader);
    }
    return std::move(outArray);
  } 
class COSMUS_MESSAGES_EXPORT cosmus_messages_Datagram_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~cosmus_messages_Datagram_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          cosmus_messages_Datagram_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<cosmus_messages::Datagram,cosmus_messages_msg_Datagram_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         cosmus_messages_Datagram_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<cosmus_messages::Datagram,cosmus_messages::Datagram::ConstPtr,cosmus_messages_msg_Datagram_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         cosmus_messages_Datagram_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<cosmus_messages::Datagram,cosmus_messages_msg_Datagram_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(cosmus_messages_msg_Datagram_common, MATLABROSMsgInterface<cosmus_messages::Datagram>)
CLASS_LOADER_REGISTER_CLASS(cosmus_messages_Datagram_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1