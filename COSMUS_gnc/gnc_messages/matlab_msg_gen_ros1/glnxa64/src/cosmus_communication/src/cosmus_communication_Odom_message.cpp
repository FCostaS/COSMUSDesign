// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for cosmus_communication/Odom
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
#include "cosmus_communication/Odom.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class COSMUS_COMMUNICATION_EXPORT cosmus_communication_msg_Odom_common : public MATLABROSMsgInterface<cosmus_communication::Odom> {
  public:
    virtual ~cosmus_communication_msg_Odom_common(){}
    virtual void copy_from_struct(cosmus_communication::Odom* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const cosmus_communication::Odom* msg, MultiLibLoader loader, size_t size = 1);
};
  void cosmus_communication_msg_Odom_common::copy_from_struct(cosmus_communication::Odom* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //pitch
        const matlab::data::TypedArray<double> pitch_arr = arr["Pitch"];
        msg->pitch = pitch_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Pitch' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Pitch' is wrong type; expected a double.");
    }
    try {
        //roll
        const matlab::data::TypedArray<double> roll_arr = arr["Roll"];
        msg->roll = roll_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Roll' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Roll' is wrong type; expected a double.");
    }
    try {
        //yaw
        const matlab::data::TypedArray<double> yaw_arr = arr["Yaw"];
        msg->yaw = yaw_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Yaw' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Yaw' is wrong type; expected a double.");
    }
    try {
        //position_x
        const matlab::data::TypedArray<double> position_x_arr = arr["PositionX"];
        msg->position_x = position_x_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'PositionX' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'PositionX' is wrong type; expected a double.");
    }
    try {
        //position_y
        const matlab::data::TypedArray<double> position_y_arr = arr["PositionY"];
        msg->position_y = position_y_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'PositionY' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'PositionY' is wrong type; expected a double.");
    }
    try {
        //position_z
        const matlab::data::TypedArray<double> position_z_arr = arr["PositionZ"];
        msg->position_z = position_z_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'PositionZ' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'PositionZ' is wrong type; expected a double.");
    }
    try {
        //velocity
        const matlab::data::TypedArray<double> velocity_arr = arr["Velocity"];
        msg->velocity = velocity_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Velocity' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Velocity' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T cosmus_communication_msg_Odom_common::get_arr(MDFactory_T& factory, const cosmus_communication::Odom* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Pitch","Roll","Yaw","PositionX","PositionY","PositionZ","Velocity"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("cosmus_communication/Odom");
    // pitch
    auto currentElement_pitch = (msg + ctr)->pitch;
    outArray[ctr]["Pitch"] = factory.createScalar(currentElement_pitch);
    // roll
    auto currentElement_roll = (msg + ctr)->roll;
    outArray[ctr]["Roll"] = factory.createScalar(currentElement_roll);
    // yaw
    auto currentElement_yaw = (msg + ctr)->yaw;
    outArray[ctr]["Yaw"] = factory.createScalar(currentElement_yaw);
    // position_x
    auto currentElement_position_x = (msg + ctr)->position_x;
    outArray[ctr]["PositionX"] = factory.createScalar(currentElement_position_x);
    // position_y
    auto currentElement_position_y = (msg + ctr)->position_y;
    outArray[ctr]["PositionY"] = factory.createScalar(currentElement_position_y);
    // position_z
    auto currentElement_position_z = (msg + ctr)->position_z;
    outArray[ctr]["PositionZ"] = factory.createScalar(currentElement_position_z);
    // velocity
    auto currentElement_velocity = (msg + ctr)->velocity;
    outArray[ctr]["Velocity"] = factory.createScalar(currentElement_velocity);
    }
    return std::move(outArray);
  } 
class COSMUS_COMMUNICATION_EXPORT cosmus_communication_Odom_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~cosmus_communication_Odom_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          cosmus_communication_Odom_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<cosmus_communication::Odom,cosmus_communication_msg_Odom_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         cosmus_communication_Odom_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<cosmus_communication::Odom,cosmus_communication::Odom::ConstPtr,cosmus_communication_msg_Odom_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         cosmus_communication_Odom_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<cosmus_communication::Odom,cosmus_communication_msg_Odom_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(cosmus_communication_msg_Odom_common, MATLABROSMsgInterface<cosmus_communication::Odom>)
CLASS_LOADER_REGISTER_CLASS(cosmus_communication_Odom_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1