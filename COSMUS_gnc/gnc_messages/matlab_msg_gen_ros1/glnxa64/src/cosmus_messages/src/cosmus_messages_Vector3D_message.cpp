// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for cosmus_messages/Vector3D
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
#include "cosmus_messages/Vector3D.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class COSMUS_MESSAGES_EXPORT cosmus_messages_msg_Vector3D_common : public MATLABROSMsgInterface<cosmus_messages::Vector3D> {
  public:
    virtual ~cosmus_messages_msg_Vector3D_common(){}
    virtual void copy_from_struct(cosmus_messages::Vector3D* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const cosmus_messages::Vector3D* msg, MultiLibLoader loader, size_t size = 1);
};
  void cosmus_messages_msg_Vector3D_common::copy_from_struct(cosmus_messages::Vector3D* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //x
        const matlab::data::TypedArray<float> x_arr = arr["X"];
        msg->x = x_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'X' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'X' is wrong type; expected a single.");
    }
    try {
        //y
        const matlab::data::TypedArray<float> y_arr = arr["Y"];
        msg->y = y_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Y' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Y' is wrong type; expected a single.");
    }
    try {
        //z
        const matlab::data::TypedArray<float> z_arr = arr["Z"];
        msg->z = z_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Z' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Z' is wrong type; expected a single.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T cosmus_messages_msg_Vector3D_common::get_arr(MDFactory_T& factory, const cosmus_messages::Vector3D* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","X","Y","Z"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("cosmus_messages/Vector3D");
    // x
    auto currentElement_x = (msg + ctr)->x;
    outArray[ctr]["X"] = factory.createScalar(currentElement_x);
    // y
    auto currentElement_y = (msg + ctr)->y;
    outArray[ctr]["Y"] = factory.createScalar(currentElement_y);
    // z
    auto currentElement_z = (msg + ctr)->z;
    outArray[ctr]["Z"] = factory.createScalar(currentElement_z);
    }
    return std::move(outArray);
  } 
class COSMUS_MESSAGES_EXPORT cosmus_messages_Vector3D_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~cosmus_messages_Vector3D_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          cosmus_messages_Vector3D_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<cosmus_messages::Vector3D,cosmus_messages_msg_Vector3D_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         cosmus_messages_Vector3D_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<cosmus_messages::Vector3D,cosmus_messages::Vector3D::ConstPtr,cosmus_messages_msg_Vector3D_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         cosmus_messages_Vector3D_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<cosmus_messages::Vector3D,cosmus_messages_msg_Vector3D_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(cosmus_messages_msg_Vector3D_common, MATLABROSMsgInterface<cosmus_messages::Vector3D>)
CLASS_LOADER_REGISTER_CLASS(cosmus_messages_Vector3D_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1