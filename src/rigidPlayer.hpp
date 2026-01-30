#pragma once

#include "godot_cpp/classes/node3d.hpp"
#include "godot_cpp/classes/rigid_body3d.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/string.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "godot_cpp/classes/node3d.hpp"
#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/classes/input_event.hpp"
#include "godot_cpp/classes/input_event_mouse.hpp"
#include "godot_cpp/classes/input_event_mouse_button.hpp"
#include "godot_cpp/classes/input_event_mouse_motion.hpp"
#include "godot_cpp/core/math.hpp"

using namespace godot;

class RigidPlayer : public RigidBody3D{
    GDCLASS(RigidPlayer, RigidBody3D)

         enum InputStates{

        };

    
    protected:
        static void _bind_methods();
    

    private:

    
    public:
        void _ready() override;
        void _process(double delta) override;
        void _physics_process(double delta) override; 
	    void _input(const Ref<InputEvent> &event) override;

        void jump();

        void ToggleCursor();
        void UI_Mode();
        void Game_Mode();

        void debuginput();
        void orbitcamtoggle();

    RigidPlayer() = default;
	~RigidPlayer() override = default;


    protected:

    private:
        godot::Node3D* piv_body = nullptr;
        godot::Node3D* piv_head = nullptr;
        godot::Node3D* piv_camrea_shake = nullptr;

        Input* input = nullptr;

        bool allowDebugFeatuers = true;

        String MoveForwardActionMappping = "empty";
        String MoveBackWardActionMappping = "empty";
        String MoveLeftActionMappping = "empty";
        String MoveRightActionMappping = "empty";
        String JumpActionMappping = "empty";
        String DuckActionMappping = "empty";

        float Acceleration = 10;
        float MaxSpeed = 10;
        float friction = 10;
        float sensitivity = 1;
        float aircontrol = 0.f;
        float jumppower = 300;
        int maxjumps = 1;

        bool mousecursor_show = true;

        float CurrentHeadRot = 0;

        

    public:
        bool bisinputing = false;
        
    public: //setters and getters
        
        void set_maxjumps(int n){maxjumps = n;}
	    int get_maxjumps(){return maxjumps;}

        void set_jumppower(float n){jumppower = n;}
	    float get_jumppower(){return jumppower;}

        void set_aircontrol(float n){aircontrol = n;}
	    float get_aircontrol(){return aircontrol;}

        void  set_acceleration(float n){Acceleration = n;}
	    float get_acceleration(){return Acceleration;}

        void  set_maxSpeed(float n){MaxSpeed = n;}
	    float get_maxSpeed(){return MaxSpeed;}

	    void set_friction(float n){friction = n;}
	    float get_friction(){return friction;}

	    void set_sensitivity(float n){sensitivity = n;}
	    float get_sensitivity(){return sensitivity;}

	    void set_piv_body(Node3D* n){piv_body = n;}
	    Node3D* get_piv_body(){return piv_body;}

	    void set_piv_head(Node3D* n){piv_head = n;}
	    Node3D* get_piv_head(){return piv_head;}

        void set_forward_action_map(String n){MoveForwardActionMappping = n;}
        String get_forward_action_map(){return MoveForwardActionMappping;}

        void set_backward_action_map(String n) {MoveBackWardActionMappping = n;}
        String get_backward_action_map() {return MoveBackWardActionMappping;}

        void set_left_action_map(String n) {MoveLeftActionMappping = n;}
        String get_left_action_map() {return MoveLeftActionMappping;}

        void set_right_action_map(String n) {MoveRightActionMappping = n;}
        String get_right_action_map() {return MoveRightActionMappping;}

        void set_jump_action_map(String n) {JumpActionMappping = n;}
        String get_jump_action_map() {return JumpActionMappping;}

        void set_duck_action_map(String n) {DuckActionMappping = n;}
        String get_duck_action_map() {return DuckActionMappping;}
};
