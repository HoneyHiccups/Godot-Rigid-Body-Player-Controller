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

    
    protected:
        static void _bind_methods();
    

    private:

    
    public:
        void _ready() override;
        void _process(double delta) override;
        void _physics_process(double delta) override; 
	    void _input(const Ref<InputEvent> &event) override;

        void ToggleCursor();
        void UI_Mode();
        void Game_Mode();

    RigidPlayer() = default;
	~RigidPlayer() override = default;


    protected:

    private:
        godot::Node3D* piv_body = nullptr;
        godot::Node3D* piv_head = nullptr;
        godot::Node3D* piv_camrea_shake = nullptr;

        Input* input = nullptr;

        String MoveForwardActionMappping = "empty";
        String MoveBackWardActionMappping = "empty";
        String MoveLeftActionMappping = "empty";
        String MoveRightActionMappping = "empty";

        float speed = 10;
        float friction = 10;
        float sensitivity = 1;
        float mass = 100;

        bool mousecursor_show = true;

        

    public:
        
    public: //setters and getters

        void set_speed(float n){speed = n;}
	    float get_speed(){return speed;}

        void set_mass(float n){mass = n;}
	    float get_mass(){return mass;}

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

};
