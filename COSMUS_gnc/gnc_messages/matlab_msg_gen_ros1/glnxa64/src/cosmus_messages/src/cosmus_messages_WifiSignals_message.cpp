// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for cosmus_messages/WifiSignals
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
#include "cosmus_messages/WifiSignals.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class COSMUS_MESSAGES_EXPORT cosmus_messages_msg_WifiSignals_common : public MATLABROSMsgInterface<cosmus_messages::WifiSignals> {
  public:
    virtual ~cosmus_messages_msg_WifiSignals_common(){}
    virtual void copy_from_struct(cosmus_messages::WifiSignals* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const cosmus_messages::WifiSignals* msg, MultiLibLoader loader, size_t size = 1);
};
  void cosmus_messages_msg_WifiSignals_common::copy_from_struct(cosmus_messages::WifiSignals* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //signals
        const matlab::data::StructArray signals_arr = arr["Signals"];
        for (auto _signalsarr : signals_arr) {
        	cosmus_messages::WifiSignal _val;
        auto msgClassPtr_signals = getCommonObject<cosmus_messages::WifiSignal>("cosmus_messages_msg_WifiSignal_common",loader);
        msgClassPtr_signals->copy_from_struct(&_val,_signalsarr,loader);
        	msg->signals.push_back(_val);
        }
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Signals' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Signals' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T cosmus_messages_msg_WifiSignals_common::get_arr(MDFactory_T& factory, const cosmus_messages::WifiSignals* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Signals"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("cosmus_messages/WifiSignals");
    // signals
    auto currentElement_signals = (msg + ctr)->signals;
    auto msgClassPtr_signals = getCommonObject<cosmus_messages::WifiSignal>("cosmus_messages_msg_WifiSignal_common",loader);
    outArray[ctr]["Signals"] = msgClassPtr_signals->get_arr(factory,&currentElement_signals[0],loader,currentElement_signals.size());
    }
    return std::move(outArray);
  } 
class COSMUS_MESSAGES_EXPORT cosmus_messages_WifiSignals_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~cosmus_messages_WifiSignals_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          cosmus_messages_WifiSignals_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<cosmus_messages::WifiSignals,cosmus_messages_msg_WifiSignals_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         cosmus_messages_WifiSignals_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<cosmus_messages::WifiSignals,cosmus_messages::WifiSignals::ConstPtr,cosmus_messages_msg_WifiSignals_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         cosmus_messages_WifiSignals_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<cosmus_messages::WifiSignals,cosmus_messages_msg_WifiSignals_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(cosmus_messages_msg_WifiSignals_common, MATLABROSMsgInterface<cosmus_messages::WifiSignals>)
CLASS_LOADER_REGISTER_CLASS(cosmus_messages_WifiSignals_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1