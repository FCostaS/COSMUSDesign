// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for cosmus_messages/Odom
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
#include "cosmus_messages/Odom.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class COSMUS_MESSAGES_EXPORT cosmus_messages_msg_Odom_common : public MATLABROSMsgInterface<cosmus_messages::Odom> {
  public:
    virtual ~cosmus_messages_msg_Odom_common(){}
    virtual void copy_from_struct(cosmus_messages::Odom* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const cosmus_messages::Odom* msg, MultiLibLoader loader, size_t size = 1);
};
  void cosmus_messages_msg_Odom_common::copy_from_struct(cosmus_messages::Odom* msg, const matlab::data::Struct& arr,
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
        //accel_x
        const matlab::data::TypedArray<double> accel_x_arr = arr["AccelX"];
        msg->accel_x = accel_x_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'AccelX' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'AccelX' is wrong type; expected a double.");
    }
    try {
        //accel_y
        const matlab::data::TypedArray<double> accel_y_arr = arr["AccelY"];
        msg->accel_y = accel_y_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'AccelY' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'AccelY' is wrong type; expected a double.");
    }
    try {
        //accel_z
        const matlab::data::TypedArray<double> accel_z_arr = arr["AccelZ"];
        msg->accel_z = accel_z_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'AccelZ' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'AccelZ' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T cosmus_messages_msg_Odom_common::get_arr(MDFactory_T& factory, const cosmus_messages::Odom* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Pitch","Roll","Yaw","AccelX","AccelY","AccelZ"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("cosmus_messages/Odom");
    // pitch
    auto currentElement_pitch = (msg + ctr)->pitch;
    outArray[ctr]["Pitch"] = factory.createScalar(currentElement_pitch);
    // roll
    auto currentElement_roll = (msg + ctr)->roll;
    outArray[ctr]["Roll"] = factory.createScalar(currentElement_roll);
    // yaw
    auto currentElement_yaw = (msg + ctr)->yaw;
    outArray[ctr]["Yaw"] = factory.createScalar(currentElement_yaw);
    // accel_x
    auto currentElement_accel_x = (msg + ctr)->accel_x;
    outArray[ctr]["AccelX"] = factory.createScalar(currentElement_accel_x);
    // accel_y
    auto currentElement_accel_y = (msg + ctr)->accel_y;
    outArray[ctr]["AccelY"] = factory.createScalar(currentElement_accel_y);
    // accel_z
    auto currentElement_accel_z = (msg + ctr)->accel_z;
    outArray[ctr]["AccelZ"] = factory.createScalar(currentElement_accel_z);
    }
    return std::move(outArray);
  } 
class COSMUS_MESSAGES_EXPORT cosmus_messages_Odom_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~cosmus_messages_Odom_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          cosmus_messages_Odom_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<cosmus_messages::Odom,cosmus_messages_msg_Odom_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         cosmus_messages_Odom_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<cosmus_messages::Odom,cosmus_messages::Odom::ConstPtr,cosmus_messages_msg_Odom_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         cosmus_messages_Odom_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<cosmus_messages::Odom,cosmus_messages_msg_Odom_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(cosmus_messages_msg_Odom_common, MATLABROSMsgInterface<cosmus_messages::Odom>)
CLASS_LOADER_REGISTER_CLASS(cosmus_messages_Odom_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1