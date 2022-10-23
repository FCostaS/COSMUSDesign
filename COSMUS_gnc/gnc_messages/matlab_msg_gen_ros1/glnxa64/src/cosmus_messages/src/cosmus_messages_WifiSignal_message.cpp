// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for cosmus_messages/WifiSignal
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
#include "cosmus_messages/WifiSignal.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class COSMUS_MESSAGES_EXPORT cosmus_messages_msg_WifiSignal_common : public MATLABROSMsgInterface<cosmus_messages::WifiSignal> {
  public:
    virtual ~cosmus_messages_msg_WifiSignal_common(){}
    virtual void copy_from_struct(cosmus_messages::WifiSignal* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const cosmus_messages::WifiSignal* msg, MultiLibLoader loader, size_t size = 1);
};
  void cosmus_messages_msg_WifiSignal_common::copy_from_struct(cosmus_messages::WifiSignal* msg, const matlab::data::Struct& arr,
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
        //signal_dbm
        const matlab::data::TypedArray<float> signal_dbm_arr = arr["SignalDbm"];
        msg->signal_dbm = signal_dbm_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'SignalDbm' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'SignalDbm' is wrong type; expected a single.");
    }
    try {
        //frequency
        const matlab::data::TypedArray<float> frequency_arr = arr["Frequency"];
        msg->frequency = frequency_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Frequency' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Frequency' is wrong type; expected a single.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T cosmus_messages_msg_WifiSignal_common::get_arr(MDFactory_T& factory, const cosmus_messages::WifiSignal* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Ssid","SignalDbm","Frequency"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("cosmus_messages/WifiSignal");
    // ssid
    auto currentElement_ssid = (msg + ctr)->ssid;
    outArray[ctr]["Ssid"] = factory.createCharArray(currentElement_ssid);
    // signal_dbm
    auto currentElement_signal_dbm = (msg + ctr)->signal_dbm;
    outArray[ctr]["SignalDbm"] = factory.createScalar(currentElement_signal_dbm);
    // frequency
    auto currentElement_frequency = (msg + ctr)->frequency;
    outArray[ctr]["Frequency"] = factory.createScalar(currentElement_frequency);
    }
    return std::move(outArray);
  } 
class COSMUS_MESSAGES_EXPORT cosmus_messages_WifiSignal_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~cosmus_messages_WifiSignal_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          cosmus_messages_WifiSignal_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<cosmus_messages::WifiSignal,cosmus_messages_msg_WifiSignal_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         cosmus_messages_WifiSignal_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<cosmus_messages::WifiSignal,cosmus_messages::WifiSignal::ConstPtr,cosmus_messages_msg_WifiSignal_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         cosmus_messages_WifiSignal_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<cosmus_messages::WifiSignal,cosmus_messages_msg_WifiSignal_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(cosmus_messages_msg_WifiSignal_common, MATLABROSMsgInterface<cosmus_messages::WifiSignal>)
CLASS_LOADER_REGISTER_CLASS(cosmus_messages_WifiSignal_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1