// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for cosmus_messages/Airspeed
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
#include "cosmus_messages/Airspeed.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class COSMUS_MESSAGES_EXPORT cosmus_messages_msg_Airspeed_common : public MATLABROSMsgInterface<cosmus_messages::Airspeed> {
  public:
    virtual ~cosmus_messages_msg_Airspeed_common(){}
    virtual void copy_from_struct(cosmus_messages::Airspeed* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const cosmus_messages::Airspeed* msg, MultiLibLoader loader, size_t size = 1);
};
  void cosmus_messages_msg_Airspeed_common::copy_from_struct(cosmus_messages::Airspeed* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //header
        const matlab::data::StructArray header_arr = arr["Header"];
        auto msgClassPtr_header = getCommonObject<std_msgs::Header>("std_msgs_msg_Header_common",loader);
        msgClassPtr_header->copy_from_struct(&msg->header,header_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Header' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Header' is wrong type; expected a struct.");
    }
    try {
        //differential_pressure
        const matlab::data::TypedArray<float> differential_pressure_arr = arr["DifferentialPressure"];
        msg->differential_pressure = differential_pressure_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'DifferentialPressure' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'DifferentialPressure' is wrong type; expected a single.");
    }
    try {
        //intensity
        const matlab::data::TypedArray<float> intensity_arr = arr["Intensity"];
        msg->intensity = intensity_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Intensity' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Intensity' is wrong type; expected a single.");
    }
    try {
        //velocity
        const matlab::data::StructArray velocity_arr = arr["Velocity"];
        auto msgClassPtr_velocity = getCommonObject<cosmus_messages::Vector3D>("cosmus_messages_msg_Vector3D_common",loader);
        msgClassPtr_velocity->copy_from_struct(&msg->velocity,velocity_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Velocity' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Velocity' is wrong type; expected a struct.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T cosmus_messages_msg_Airspeed_common::get_arr(MDFactory_T& factory, const cosmus_messages::Airspeed* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Header","DifferentialPressure","Intensity","Velocity"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("cosmus_messages/Airspeed");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::Header>("std_msgs_msg_Header_common",loader);
    outArray[ctr]["Header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // differential_pressure
    auto currentElement_differential_pressure = (msg + ctr)->differential_pressure;
    outArray[ctr]["DifferentialPressure"] = factory.createScalar(currentElement_differential_pressure);
    // intensity
    auto currentElement_intensity = (msg + ctr)->intensity;
    outArray[ctr]["Intensity"] = factory.createScalar(currentElement_intensity);
    // velocity
    auto currentElement_velocity = (msg + ctr)->velocity;
    auto msgClassPtr_velocity = getCommonObject<cosmus_messages::Vector3D>("cosmus_messages_msg_Vector3D_common",loader);
    outArray[ctr]["Velocity"] = msgClassPtr_velocity->get_arr(factory, &currentElement_velocity, loader);
    }
    return std::move(outArray);
  } 
class COSMUS_MESSAGES_EXPORT cosmus_messages_Airspeed_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~cosmus_messages_Airspeed_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          cosmus_messages_Airspeed_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<cosmus_messages::Airspeed,cosmus_messages_msg_Airspeed_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         cosmus_messages_Airspeed_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<cosmus_messages::Airspeed,cosmus_messages::Airspeed::ConstPtr,cosmus_messages_msg_Airspeed_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         cosmus_messages_Airspeed_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<cosmus_messages::Airspeed,cosmus_messages_msg_Airspeed_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(cosmus_messages_msg_Airspeed_common, MATLABROSMsgInterface<cosmus_messages::Airspeed>)
CLASS_LOADER_REGISTER_CLASS(cosmus_messages_Airspeed_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1