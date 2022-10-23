// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for cosmus_messages/Control_Surfaces
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
#include "cosmus_messages/Control_Surfaces.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class COSMUS_MESSAGES_EXPORT cosmus_messages_msg_Control_Surfaces_common : public MATLABROSMsgInterface<cosmus_messages::Control_Surfaces> {
  public:
    virtual ~cosmus_messages_msg_Control_Surfaces_common(){}
    virtual void copy_from_struct(cosmus_messages::Control_Surfaces* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const cosmus_messages::Control_Surfaces* msg, MultiLibLoader loader, size_t size = 1);
};
  void cosmus_messages_msg_Control_Surfaces_common::copy_from_struct(cosmus_messages::Control_Surfaces* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //propeller
        const matlab::data::TypedArray<double> propeller_arr = arr["Propeller"];
        msg->propeller = propeller_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Propeller' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Propeller' is wrong type; expected a double.");
    }
    try {
        //right_aileron
        const matlab::data::TypedArray<double> right_aileron_arr = arr["RightAileron"];
        msg->right_aileron = right_aileron_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'RightAileron' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'RightAileron' is wrong type; expected a double.");
    }
    try {
        //right_flap
        const matlab::data::TypedArray<double> right_flap_arr = arr["RightFlap"];
        msg->right_flap = right_flap_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'RightFlap' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'RightFlap' is wrong type; expected a double.");
    }
    try {
        //elevators
        const matlab::data::TypedArray<double> elevators_arr = arr["Elevators"];
        msg->elevators = elevators_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Elevators' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Elevators' is wrong type; expected a double.");
    }
    try {
        //rudder
        const matlab::data::TypedArray<double> rudder_arr = arr["Rudder"];
        msg->rudder = rudder_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Rudder' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Rudder' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T cosmus_messages_msg_Control_Surfaces_common::get_arr(MDFactory_T& factory, const cosmus_messages::Control_Surfaces* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Propeller","RightAileron","RightFlap","Elevators","Rudder"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("cosmus_messages/Control_Surfaces");
    // propeller
    auto currentElement_propeller = (msg + ctr)->propeller;
    outArray[ctr]["Propeller"] = factory.createScalar(currentElement_propeller);
    // right_aileron
    auto currentElement_right_aileron = (msg + ctr)->right_aileron;
    outArray[ctr]["RightAileron"] = factory.createScalar(currentElement_right_aileron);
    // right_flap
    auto currentElement_right_flap = (msg + ctr)->right_flap;
    outArray[ctr]["RightFlap"] = factory.createScalar(currentElement_right_flap);
    // elevators
    auto currentElement_elevators = (msg + ctr)->elevators;
    outArray[ctr]["Elevators"] = factory.createScalar(currentElement_elevators);
    // rudder
    auto currentElement_rudder = (msg + ctr)->rudder;
    outArray[ctr]["Rudder"] = factory.createScalar(currentElement_rudder);
    }
    return std::move(outArray);
  } 
class COSMUS_MESSAGES_EXPORT cosmus_messages_Control_Surfaces_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~cosmus_messages_Control_Surfaces_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          cosmus_messages_Control_Surfaces_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<cosmus_messages::Control_Surfaces,cosmus_messages_msg_Control_Surfaces_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         cosmus_messages_Control_Surfaces_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<cosmus_messages::Control_Surfaces,cosmus_messages::Control_Surfaces::ConstPtr,cosmus_messages_msg_Control_Surfaces_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         cosmus_messages_Control_Surfaces_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<cosmus_messages::Control_Surfaces,cosmus_messages_msg_Control_Surfaces_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(cosmus_messages_msg_Control_Surfaces_common, MATLABROSMsgInterface<cosmus_messages::Control_Surfaces>)
CLASS_LOADER_REGISTER_CLASS(cosmus_messages_Control_Surfaces_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1