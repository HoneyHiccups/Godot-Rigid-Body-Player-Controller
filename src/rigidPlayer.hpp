#pragma once

#include "godot_cpp/classes/node3d.hpp"
#include "godot_cpp/classes/ray_cast3d.hpp"
#include "godot_cpp/classes/rigid_body3d.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/string.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "godot_cpp/classes/node3d.hpp"
#include "godot_cpp/classes/input.hpp"
#include "godot_cpp/classes/input_event.hpp"
#include "godot_cpp/classes/input_event_mouse.hpp"
#include "godot_cpp/classes/input_event_mouse_button.hpp"
#include "godot_cpp/classes/input_event_mouse_motion.hpp"
#include "godot_cpp/core/math.hpp"
#include "RigidBodyUtilitys.h"
#include "godot_cpp/core/property_info.hpp"
#include "godot_cpp/variant/basis.hpp"
#include "godot_cpp/variant/projection.hpp"
#include "godot_cpp/variant/transform3d.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "godot_cpp/variant/vector2.hpp"
#include "godot_cpp/variant/vector3.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/object.hpp"
#include "godot_cpp/core/print_string.hpp"
#include <sys/types.h>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/gdvirtual.gen.inc>



using namespace godot;

class RigidPlayer : public RigidBody3D{
    GDCLASS(RigidPlayer, RigidBody3D)

         enum InputStates{

        };

    
    protected:
        static void _bind_methods();
        GDVIRTUAL1(_extern_procces, double );
        GDVIRTUAL1(_extern_physics_process, double );
        GDVIRTUAL0(_extern_just_jumped);
        GDVIRTUAL0(_extern_just_landed);
        //void _extern_procces_default(double delta);
        //void _extern_physics_process_default(double delta);
        //void _extern_just_jumped_default();
        //void _extern_just_landed_default();

    private:

        void debuginput();
        void orbitcamtoggle();
        
    
    public:
        void _ready() override;
        void _process(double delta) override;
        void _physics_process(double delta) override; 
	    void _input(const Ref<InputEvent> &event) override;

        float MappedDotProduct(Vector3 x , Vector3 y);

        void jump();
        Vector3 GetWishDir(){return Wishdir;}
        void AlineToGravity();
        void set_gravity_aline_vector(Vector3 Gravitydir);
        void handle_gravity_ort_logic();
        void ToggleCursor();
        void UI_Mode();
        void Game_Mode();
        void Just_Landed();
        void rez_jump();
        void just_stopped_moving();
        bool is_ipnuting();


    RigidPlayer() = default;
	~RigidPlayer() override = default;


    protected:

        enum PlaylinCounterSteer{
            Forward,
            Backward,
            ForwardLeft,
            ForwardRight,
            BackwardLeft,
            BackwardRight,
            NotMoving
        };

        enum PlayerWishDirState{
            WishForward,
            WishBackward,
            WishLeft,
            WishRight,
            WishForwardLeft,
            WishForwardRight,
            WishBackwardLeft,
            WishBackwardRight,
            NoInput
        };

    private:
    //

        PlayerWishDirState InputWishdirState;
        PlaylinCounterSteer SteerSwitchKey;
        godot::Node3D* piv_body = nullptr;
        godot::Node3D* piv_head = nullptr;
        godot::Node3D* camrea_wrapper = nullptr;

        Input* input = nullptr;

        bool allowDebugFeatuers = true;
        bool allowToonJumping = true;
        bool allowMovmentInput = true;

        String MoveForwardActionMappping = "empty";
        String MoveBackWardActionMappping = "empty";
        String MoveLeftActionMappping = "empty";
        String MoveRightActionMappping = "empty";
        String JumpActionMappping = "empty";
        String DuckActionMappping = "empty";

        RayCast3D* GroundRay = nullptr;
        float playerwidith = .5;
        float playerHieght = 2.0f;

        float PD_DampiningPower = 0.8f;
        float StrafeJumpAddPower = 0.f;
        float Acceleration = 10;
        float MaxSpeed = 10;
        float friction = 10;
        float sensitivity = 1;
        float aircontrol = 3.0f;
        float jumppower = 300;
        float obit_cam_dist = 7;
        int maxjumps = 1;
        int currentjumps = maxjumps;
        bool bisGrounded = true;
        float autoslowPower = 0.4f;
        float FrictionBurnPower = .66f;
        float CoyoteTime = .15f;
        float airtime = 0;
        bool toonjump = true;
        Plane walkingPlane;

        int MaxContactReportCount = 4;
        // cant use a u_int here cuss microsoft and there dword or whatever i guess
        // tilted about it ngl, dont make this go negative cuss somthing bad will prob happen



        float CurrentSpeed;

        bool mousecursor_show = true;

        float CurrentHeadRot = 0;
        Vector3 LastGravitydir = Vector3(0,-1,0);
        Vector3 LastGravityForward = Vector3(1,0,0);
        Vector3 LastGravityRight;

        Basis Targetbasis;
        Vector3 Wishdir = Vector3(0,0,0);
        bool bisOrienttoGravity = false;
        bool keepskewedGravityOrientaions = true;
        bool SlerpGravityOrientaions = true;
        bool isOverSlooped = false;
        bool Raybisgrounded = false;
        bool autoslow = true; // needs grounded check to work
        float MaxStandAngle = 41; // will let player walk up 40 degree slops




    public:
        bool bisinputing = false;
        Vector3 CreateTwistedWishDir(PlaylinCounterSteer l ,PlayerWishDirState w, Vector3 wish);
        
    public: //setters and getters
        bool is_inputing(){return bisinputing;}
        bool is_grounded(){return bisGrounded;}
        bool is_oversloped(){return isOverSlooped;}
        float get_airtime(){return airtime;}
        int get_current_jumps(){return currentjumps;}

        void set_allow_movment(bool n){allowMovmentInput = n;}
        bool get_allow_movment(){return allowMovmentInput;}

        void set_max_walk_angle(float n){MaxStandAngle = n;}
	    float get_max_walk_angle(){return MaxStandAngle;}

        void set_allow_toon_jumping(bool n){allowToonJumping = n;}
        bool get_allow_toon_jumping(){return allowToonJumping;}

        void set_allow_align_with_gravity(bool n){bisOrienttoGravity = n;}
	    bool get_allow_align_with_gravity(){return bisOrienttoGravity;}

        void set_maxjumps(int n){maxjumps = n;}
	    int get_maxjumps(){return maxjumps;}

        void set_orbit_cam_dist(float n){obit_cam_dist = n;}
	    float get_orbit_cam_dist(){return obit_cam_dist;}

        void set_pd_dampiningPower(float n){PD_DampiningPower = n;}
	    float get_pd_dampiningPower(){return PD_DampiningPower;}

        void set_strafe_jumpAddPower(float n){StrafeJumpAddPower = n;}
	    float get_strafe_jumpAddPower(){return StrafeJumpAddPower;}

        void set_jumppower(float n){jumppower = n;}
	    float get_jumppower(){return jumppower;}

        void set_aircontrol(float n){aircontrol = n;}
	    float get_aircontrol(){return aircontrol;}

        void  set_acceleration(float n){Acceleration = n*100.0f;}
	    float get_acceleration(){return Acceleration/100.0f;}

        void  set_maxSpeed(float n){MaxSpeed = n;}
	    float get_maxSpeed(){return MaxSpeed;}

	    void set_friction(float n){friction = n;}
	    float get_friction(){return friction;}

        void set_sensitivity(float n){sensitivity = n;}
	    float get_sensitivity(){return sensitivity;}

	    void set_body_width(float n){playerwidith = n;}
	    float get_body_width(){return playerwidith;}

	    void set_body_height(float n){playerHieght = n;}
	    float get_body_height(){return playerHieght;}

	    void set_piv_body(Node3D* n){piv_body = n;}
	    Node3D* get_piv_body(){return piv_body;}

	    void set_piv_head(Node3D* n){piv_head = n;}
	    Node3D* get_piv_head(){return piv_head;}

	    void set_camrea_wrapper(Node3D* n){camrea_wrapper = n;}
	    Node3D* get_camrea_wrapper(){return camrea_wrapper;}

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
