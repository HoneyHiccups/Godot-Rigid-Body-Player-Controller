#include "rigidPlayer.hpp"
#include "godot_cpp/classes/input_event.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/math.hpp"
#include "godot_cpp/core/object.hpp"
#include "godot_cpp/core/print_string.hpp"
#include "godot_cpp/core/property_info.hpp"
#include "godot_cpp/variant/basis.hpp"
#include "godot_cpp/variant/transform3d.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "godot_cpp/variant/vector2.hpp"
#include "godot_cpp/variant/vector3.hpp"

using namespace godot;
void RigidPlayer::_bind_methods(){
    ClassDB::bind_method(D_METHOD("get_acceleration"), &RigidPlayer::get_acceleration);
    ClassDB::bind_method(D_METHOD("set_acceleration", "acceleration"), &RigidPlayer::set_acceleration);
    ClassDB::bind_method(D_METHOD("get_maxSpeed"), &RigidPlayer::get_maxSpeed);
    ClassDB::bind_method(D_METHOD("set_maxSpeed", "maxSpeed"), &RigidPlayer::set_maxSpeed);  
    ClassDB::bind_method(D_METHOD("get_aircontrol"), &RigidPlayer::get_aircontrol);
    ClassDB::bind_method(D_METHOD("set_aircontrol", "aircontrol"), &RigidPlayer::set_aircontrol);
    ClassDB::bind_method(D_METHOD("get_jumppower"), &RigidPlayer::get_jumppower);
    ClassDB::bind_method(D_METHOD("set_jumppower", "jumppower"), &RigidPlayer::set_jumppower);
    ClassDB::bind_method(D_METHOD("get_maxjumps"), &RigidPlayer::get_maxjumps);
    ClassDB::bind_method(D_METHOD("set_maxjumps", "maxjumps"), &RigidPlayer::set_maxjumps);
    ClassDB::bind_method(D_METHOD("get_friction"), &RigidPlayer::get_friction);
    ClassDB::bind_method(D_METHOD("set_friction", "friction"), &RigidPlayer::set_friction);
    ClassDB::bind_method(D_METHOD("get_sensitivity"), &RigidPlayer::get_sensitivity);
    ClassDB::bind_method(D_METHOD("set_sensitivity", "sensitivity"), &RigidPlayer::set_sensitivity);
    ClassDB::bind_method(D_METHOD("get_piv_body"), &RigidPlayer::get_piv_body);
    ClassDB::bind_method(D_METHOD("set_piv_body", "piv_body"), &RigidPlayer::set_piv_body);
    ClassDB::bind_method(D_METHOD("get_piv_head"), &RigidPlayer::get_piv_head);
    ClassDB::bind_method(D_METHOD("set_piv_head", "piv_head"), &RigidPlayer::set_piv_head);
    ClassDB::bind_method(D_METHOD("get_camrea_wrapper"), &RigidPlayer::get_camrea_wrapper);
    ClassDB::bind_method(D_METHOD("set_camrea_wrapper", "camrea_wrapper"), &RigidPlayer::set_camrea_wrapper);
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
    ClassDB::bind_method(D_METHOD("set_jump_action_map", "JumpActionMappping"), &RigidPlayer::set_jump_action_map);
    ClassDB::bind_method(D_METHOD("get_jump_action_map"), &RigidPlayer::get_jump_action_map);        
    ClassDB::bind_method(D_METHOD("set_duck_action_map", "DuckActionMappping"), &RigidPlayer::set_duck_action_map);
    ClassDB::bind_method(D_METHOD("get_duck_action_map"), &RigidPlayer::get_duck_action_map);


    //macro       //type       // type        //var name  //setter    //getter
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "acceleration"), "set_acceleration", "get_acceleration");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "maxSpeed"), "set_maxSpeed", "get_maxSpeed");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "aircontrol"), "set_aircontrol", "get_aircontrol");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "jumppower"), "set_jumppower", "get_jumppower");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "maxjumps"), "set_maxjumps", "get_maxjumps");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "friction"), "set_friction", "get_friction");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "sensitivity"), "set_sensitivity", "get_sensitivity");

    ADD_PROPERTY(PropertyInfo( Variant::STRING, "Forward Action Map"), "set_forward_action_map","get_forward_action_map");
    ADD_PROPERTY(PropertyInfo( Variant::STRING, "Back Action Map"), "set_backward_action_map","get_backward_action_map");
    ADD_PROPERTY(PropertyInfo( Variant::STRING, "Left Action Map"), "set_left_action_map","get_left_action_map");
    ADD_PROPERTY(PropertyInfo( Variant::STRING, "Right Action Map"), "set_right_action_map","get_right_action_map");
    ADD_PROPERTY(PropertyInfo( Variant::STRING, "Jump Action Map"), "set_jump_action_map","get_jump_action_map");
    ADD_PROPERTY(PropertyInfo( Variant::STRING, "Duck Action Map"), "set_duck_action_map","get_duck_action_map");

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "piv_body", PROPERTY_HINT_NODE_TYPE),"set_piv_body","get_piv_body" );
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "piv_head", PROPERTY_HINT_NODE_TYPE),"set_piv_head","get_piv_head" );
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "camrea_wrapper", PROPERTY_HINT_NODE_TYPE),"set_camrea_wrapper","get_camrea_wrapper" );

}


void RigidPlayer::_ready(){
    input = Input::get_singleton();

    LastGravitydir = this->get_gravity().normalized();

    CurrentHeadRot = piv_head->get_rotation().y;

        Basis BodyBasis = this->get_basis();
        Vector3 Gravitydir = this->get_gravity();
        Gravitydir.normalize();
        LastGravitydir = Gravitydir;
        LastGravityRight = BodyBasis.get_column(2).normalized().cross(Gravitydir);
        LastGravityRight.normalize();
        LastGravityForward = LastGravityRight.cross(-Gravitydir);
        Basis NewBodyBasis = Basis(LastGravityRight,Gravitydir*-1.0f,LastGravityForward);
        NewBodyBasis.orthogonalize();
        this->set_basis(NewBodyBasis);

    this->set_process_input(true);


}


void RigidPlayer::_process(double delta){
    
    auto test = this->get_gravity();
    test.normalize();
    if(piv_body!=nullptr && test != LastGravitydir){
        
        Basis BodyBasis = this->get_basis();
        Vector3 Gravitydir = this->get_gravity();
        Gravitydir.normalize();
        LastGravitydir = Gravitydir;
        LastGravityRight = BodyBasis.get_column(2).normalized().cross(Gravitydir);
        LastGravityRight.normalize();
        LastGravityForward = LastGravityRight.cross(-Gravitydir);
        Basis NewBodyBasis = Basis(LastGravityRight,Gravitydir*-1.0f,LastGravityForward);
        NewBodyBasis.orthogonalize();
        this->set_basis(NewBodyBasis);
        //piv_body->set_basis(NewBodyBasis);



        
    }

    Vector3 Testing  = this->get_basis().get_column(1);
    test.normalize();


}

void RigidPlayer::_physics_process(double delta){
    if(input != nullptr && piv_body != nullptr){
        Vector2 InputDir = Vector2(
            input->get_action_raw_strength(MoveRightActionMappping) -input->get_action_raw_strength(MoveLeftActionMappping),
            //0.0f,
            input->get_action_raw_strength(MoveBackWardActionMappping) - input->get_action_raw_strength(MoveForwardActionMappping)
        );

        if(InputDir.is_zero_approx()== false){
            bisinputing = true;
            InputDir.normalize();
            Basis BodyBasis = piv_body->get_basis();
            Vector3 ForwardVec = BodyBasis.get_column(2);
            Vector3 RightVec = BodyBasis.get_column(0);
            Vector3 Wishdir = (RightVec*InputDir.x) + (ForwardVec*InputDir.y);
            Wishdir.normalize();
            // need to do planer rots
            apply_central_force(((Wishdir*this->get_mass())*Acceleration)*delta);

        }else{
            bisinputing = false;
        }

        if(input->is_action_just_pressed(JumpActionMappping)){
            jump();
        }
        debuginput();
    }
    
}

void RigidPlayer::_input(const Ref<InputEvent> &event){
    Ref<InputEventMouseMotion> MouseEvent = event;

    if(input->get_mouse_mode() == Input::MOUSE_MODE_CAPTURED){
        if(MouseEvent.is_valid()){
            Vector2 MouseDelta = MouseEvent->get_relative() *-0.001;
            if(MouseDelta != Vector2(0,0)){
                piv_body->rotate(piv_body->get_basis().get_column(1), MouseDelta.x*sensitivity);
                float min = Math::deg_to_rad(-89.0f);
                float max = Math::deg_to_rad(89.0f);
                CurrentHeadRot = Math::clamp(CurrentHeadRot + (MouseDelta.y*sensitivity), min,max);
                piv_head->set_rotation(Vector3(CurrentHeadRot,0.0f,0.0f));
            }
        }
    }
}

void RigidPlayer::jump(){
    Vector3 GravityDir = (this->get_gravity()*-1.0f);
    GravityDir.normalize();
    this->apply_central_impulse( (GravityDir*this->get_mass()) * jumppower );
}

void RigidPlayer::orbitcamtoggle(){

    if(camrea_wrapper!= nullptr){
        Vector3 camloc = camrea_wrapper->get_position();
        if(camloc == Vector3 (0.0f,0.0f,0.0f)){
            camrea_wrapper->set_position(Vector3(0,0,10));
        }else{
            camrea_wrapper->set_position(Vector3 (0.0f,0.0f,0.0f));
        }
    }
    return;
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

void RigidPlayer::debuginput(){

    if (allowDebugFeatuers != true)
        return;
    
    if (input->is_action_just_released("toggle_focus")){
        ToggleCursor();
    }

    if(input->is_action_just_released("toggle_orbit_cam")){
        orbitcamtoggle();
    }
    
}
