// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for cosmus_messages/Wind
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
#include "cosmus_messages/Wind.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class COSMUS_MESSAGES_EXPORT cosmus_messages_msg_Wind_common : public MATLABROSMsgInterface<cosmus_messages::Wind> {
  public:
    virtual ~cosmus_messages_msg_Wind_common(){}
    virtual void copy_from_struct(cosmus_messages::Wind* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const cosmus_messages::Wind* msg, MultiLibLoader loader, size_t size = 1);
};
  void cosmus_messages_msg_Wind_common::copy_from_struct(cosmus_messages::Wind* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //frame_id
        const matlab::data::CharArray frame_id_arr = arr["FrameId"];
        msg->frame_id = frame_id_arr.toAscii();
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'FrameId' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'FrameId' is wrong type; expected a string.");
    }
    try {
        //time_usec
        const matlab::data::TypedArray<int64_t> time_usec_arr = arr["TimeUsec"];
        msg->time_usec = time_usec_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'TimeUsec' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'TimeUsec' is wrong type; expected a int64.");
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
  MDArray_T cosmus_messages_msg_Wind_common::get_arr(MDFactory_T& factory, const cosmus_messages::Wind* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","FrameId","TimeUsec","Velocity"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("cosmus_messages/Wind");
    // frame_id
    auto currentElement_frame_id = (msg + ctr)->frame_id;
    outArray[ctr]["FrameId"] = factory.createCharArray(currentElement_frame_id);
    // time_usec
    auto currentElement_time_usec = (msg + ctr)->time_usec;
    outArray[ctr]["TimeUsec"] = factory.createScalar(currentElement_time_usec);
    // velocity
    auto currentElement_velocity = (msg + ctr)->velocity;
    auto msgClassPtr_velocity = getCommonObject<cosmus_messages::Vector3D>("cosmus_messages_msg_Vector3D_common",loader);
    outArray[ctr]["Velocity"] = msgClassPtr_velocity->get_arr(factory, &currentElement_velocity, loader);
    }
    return std::move(outArray);
  } 
class COSMUS_MESSAGES_EXPORT cosmus_messages_Wind_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~cosmus_messages_Wind_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          cosmus_messages_Wind_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<cosmus_messages::Wind,cosmus_messages_msg_Wind_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         cosmus_messages_Wind_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<cosmus_messages::Wind,cosmus_messages::Wind::ConstPtr,cosmus_messages_msg_Wind_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         cosmus_messages_Wind_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<cosmus_messages::Wind,cosmus_messages_msg_Wind_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(cosmus_messages_msg_Wind_common, MATLABROSMsgInterface<cosmus_messages::Wind>)
CLASS_LOADER_REGISTER_CLASS(cosmus_messages_Wind_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1