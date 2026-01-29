#include "rigidPlayer.hpp"
#include "godot_cpp/classes/input_event.hpp"
#include "godot_cpp/core/class_db.hpp"

using namespace godot;
void RigidPlayer::_bind_methods(){
    ClassDB::bind_method(D_METHOD("get_speed"), &RigidPlayer::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "speed"), &RigidPlayer::set_speed);
    ClassDB::bind_method(D_METHOD("get_mass"), &RigidPlayer::get_mass);
    ClassDB::bind_method(D_METHOD("set_mass", "mass"), &RigidPlayer::set_mass);
    ClassDB::bind_method(D_METHOD("get_friction"), &RigidPlayer::get_friction);
    ClassDB::bind_method(D_METHOD("set_friction", "friction"), &RigidPlayer::set_friction);
    ClassDB::bind_method(D_METHOD("get_sensitivity"), &RigidPlayer::get_sensitivity);
    ClassDB::bind_method(D_METHOD("set_sensitivity", "sensitivity"), &RigidPlayer::set_sensitivity);
    ClassDB::bind_method(D_METHOD("get_piv_body"), &RigidPlayer::get_piv_body);
    ClassDB::bind_method(D_METHOD("set_piv_body", "piv_body"), &RigidPlayer::set_piv_body);
    ClassDB::bind_method(D_METHOD("get_piv_head"), &RigidPlayer::get_piv_head);
    ClassDB::bind_method(D_METHOD("set_piv_head", "piv_head"), &RigidPlayer::set_piv_head);
    ClassDB::bind_method(D_METHOD("ToggleCursor"), &RigidPlayer::ToggleCursor);
    ClassDB::bind_method(D_METHOD("UI_Mode"), &RigidPlayer::UI_Mode);
    ClassDB::bind_method(D_METHOD("Game_Mode"), &RigidPlayer::Game_Mode);
    ClassDB::bind_method(D_METHOD("set_forward_action_map","MoveForwardActionMappping"), &RigidPlayer::set_forward_action_map);
    ClassDB::bind_method(D_METHOD("get_forward_action_map"), &RigidPlayer::get_forward_action_map);
    ClassDB::bind_method(D_METHOD("set_backward_action_map", "MoveBackWardActionMappping"), &RigidPlayer::set_backward_action_map);
    ClassDB::bind_method(D_METHOD("get_backward_action_map"), &RigidPlayer::get_backward_action_map);
    ClassDB::bind_method(D_METHOD("set_left_action_map", "MoveLeftActionMappping"), &RigidPlayer::set_left_action_map);
    ClassDB::bind_method(D_METHOD("get_left_action_map"), &RigidPlayer::get_left_action_map);
    ClassDB::bind_method(D_METHOD("set_right_action_map", "MoveRightActionMappping"), &RigidPlayer::set_right_action_map);
    ClassDB::bind_method(D_METHOD("get_right_action_map"), &RigidPlayer::get_right_action_map);


    //macro       //type       // type        //var name  //setter    //getter
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "mass"), "set_mass", "get_mass");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "friction"), "set_friction", "get_friction");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "sensitivity"), "set_sensitivity", "get_sensitivity");

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "piv_body", PROPERTY_HINT_NODE_TYPE),"set_piv_body","get_piv_body" );
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "piv_head", PROPERTY_HINT_NODE_TYPE),"set_piv_head","get_piv_head" );

}


void RigidPlayer::_ready(){
    input = Input::get_singleton();
    this->set_process_input(true);


    this->set_mass(mass);

}


void RigidPlayer::_process(double delta){

}

void RigidPlayer::_physics_process(double delta){

}

void RigidPlayer::_input(const Ref<InputEvent> &event){
    Ref<InputEventMouseMotion> MouseEvent = event;

    if(input->get_mouse_mode() == Input::MOUSE_MODE_CAPTURED){
        if(MouseEvent.is_valid()){

        }
    }
}


void RigidPlayer::ToggleCursor(){
    if( input->get_mouse_mode() == Input::MOUSE_MODE_CAPTURED ){
        input->set_mouse_mode(Input::MOUSE_MODE_VISIBLE);
        mousecursor_show = true;
    }else{
        input->set_mouse_mode(Input::MOUSE_MODE_CAPTURED);
        mousecursor_show = false; 
    }
}

void RigidPlayer::UI_Mode(){
    input->set_mouse_mode(Input::MOUSE_MODE_VISIBLE);
    mousecursor_show = true;
}

void RigidPlayer::Game_Mode(){
    input->set_mouse_mode(Input::MOUSE_MODE_CAPTURED);
    mousecursor_show = false; 
}
