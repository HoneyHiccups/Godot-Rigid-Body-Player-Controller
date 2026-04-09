#include "rigidPlayer.hpp"
#include "RigidBodyUtilitys.h"
#include "godot_cpp/classes/ray_cast3d.hpp"
#include "godot_cpp/classes/rigid_body3d.hpp"
#include "godot_cpp/classes/time.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/math.hpp"
#include "godot_cpp/core/memory.hpp"
#include "godot_cpp/core/object.hpp"
#include "godot_cpp/core/print_string.hpp"
#include "godot_cpp/core/property_info.hpp"
#include "godot_cpp/variant/basis.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "godot_cpp/variant/vector2.hpp"
#include "godot_cpp/variant/vector3.hpp"
#include <cstdint>

//vitrual calls not work

using namespace godot;
void RigidPlayer::_bind_methods(){
    ClassDB::bind_method(D_METHOD("get_allow_align_with_gravity"),                 &RigidPlayer::get_allow_align_with_gravity);
    ClassDB::bind_method(D_METHOD("set_allow_align_with_gravity", "bisOrienttoGravity"), &RigidPlayer::set_allow_align_with_gravity);
    ClassDB::bind_method(D_METHOD("set_gravity_aline_vector", "GravityVector"), &RigidPlayer::set_gravity_aline_vector);
    ClassDB::bind_method(D_METHOD("get_acceleration"), &RigidPlayer::get_acceleration);
    ClassDB::bind_method(D_METHOD("set_acceleration", "acceleration"), &RigidPlayer::set_acceleration);
    ClassDB::bind_method(D_METHOD("get_maxSpeed"), &RigidPlayer::get_maxSpeed);
    ClassDB::bind_method(D_METHOD("set_maxSpeed", "maxSpeed"), &RigidPlayer::set_maxSpeed);  
    ClassDB::bind_method(D_METHOD("get_pd_dampiningPower"),                      &RigidPlayer::get_pd_dampiningPower);
    ClassDB::bind_method(D_METHOD("set_pd_dampiningPower", "pd_dampiningPower"), &RigidPlayer::set_pd_dampiningPower); 
    ClassDB::bind_method(D_METHOD("get_strafe_jumpAddPower"),                        &RigidPlayer::get_strafe_jumpAddPower);
    ClassDB::bind_method(D_METHOD("set_strafe_jumpAddPower", "strafe_jumpAddPower"), &RigidPlayer::set_strafe_jumpAddPower); 
    ClassDB::bind_method(D_METHOD("get_orbit_cam_dist"),                  &RigidPlayer::get_orbit_cam_dist);
    ClassDB::bind_method(D_METHOD("set_orbit_cam_dist", "obit_cam_dist"), &RigidPlayer::set_orbit_cam_dist);  
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
    ClassDB::bind_method(D_METHOD("get_wish_dir"), &RigidPlayer::GetWishDir);
    ClassDB::bind_method(D_METHOD("is_inputing"), &RigidPlayer::is_inputing);
    ClassDB::bind_method(D_METHOD("is_grounded"), &RigidPlayer::is_grounded);
    ClassDB::bind_method(D_METHOD("is_oversloped"), &RigidPlayer::is_oversloped);
    ClassDB::bind_method(D_METHOD("get_airtime"), &RigidPlayer::get_airtime);
    ClassDB::bind_method(D_METHOD("get_current_jumps"), &RigidPlayer::get_current_jumps);  
    ClassDB::bind_method(D_METHOD("get_body_width"), &RigidPlayer::get_body_width);
    ClassDB::bind_method(D_METHOD("set_body_width", "body_width"), &RigidPlayer::set_body_width);
    ClassDB::bind_method(D_METHOD("get_body_height"), &RigidPlayer::get_body_height);
    ClassDB::bind_method(D_METHOD("set_body_height", "body_height"), &RigidPlayer::set_body_height);
    ClassDB::bind_method(D_METHOD("get_max_walk_angle"),                &RigidPlayer::get_max_walk_angle);
    ClassDB::bind_method(D_METHOD("set_max_walk_angle", "max_walk_angle"), &RigidPlayer::set_max_walk_angle);

    ClassDB::bind_method(D_METHOD("get_allow_movment"),                       &RigidPlayer::get_allow_movment);
    ClassDB::bind_method(D_METHOD("set_allow_movment", "allow_movment"),      &RigidPlayer::set_allow_movment);


    ClassDB::bind_method(D_METHOD("get_allow_toon_jumping"),                       &RigidPlayer::get_allow_toon_jumping);
    ClassDB::bind_method(D_METHOD("set_allow_toon_jumping", "allow_toon_jumping"), &RigidPlayer::set_allow_toon_jumping);

    //ClassDB::bind_method(D_METHOD("_extern_procces", "delta"), 
    //                     &RigidPlayer::_extern_procces_default);
    //ClassDB::bind_method(D_METHOD("_extern_physics_process", "delta"), 
    //                     &RigidPlayer::_extern_physics_process_default); 
    //ClassDB::bind_method(D_METHOD("_extern_just_jumped"), 
    //                     &RigidPlayer::_extern_just_jumped_default);
    //ClassDB::bind_method(D_METHOD("_extern_just_landed"), 
    //                     &RigidPlayer::_extern_just_landed_default);

    //macro       //type       // type        //var name  //setter    //getter
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "acceleration"), "set_acceleration", "get_acceleration");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "maxSpeed"), "set_maxSpeed", "get_maxSpeed");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "aircontrol"), "set_aircontrol", "get_aircontrol");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "jumppower"), "set_jumppower", "get_jumppower");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "maxjumps"), "set_maxjumps", "get_maxjumps");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "friction"), "set_friction", "get_friction");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "sensitivity"), "set_sensitivity", "get_sensitivity");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "PD_DampiningPower"), "set_pd_dampiningPower", "get_pd_dampiningPower");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "strafe_jumpAddPower"), "set_strafe_jumpAddPower", "get_strafe_jumpAddPower");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "obit_cam_dist"), "set_orbit_cam_dist", "get_orbit_cam_dist");
    ADD_PROPERTY(PropertyInfo( Variant::STRING, "Forward Action Map"), "set_forward_action_map","get_forward_action_map");
    ADD_PROPERTY(PropertyInfo( Variant::STRING, "Back Action Map"), "set_backward_action_map","get_backward_action_map");
    ADD_PROPERTY(PropertyInfo( Variant::STRING, "Left Action Map"), "set_left_action_map","get_left_action_map");
    ADD_PROPERTY(PropertyInfo( Variant::STRING, "Right Action Map"), "set_right_action_map","get_right_action_map");
    ADD_PROPERTY(PropertyInfo( Variant::STRING, "Jump Action Map"), "set_jump_action_map","get_jump_action_map");
    ADD_PROPERTY(PropertyInfo( Variant::STRING, "Duck Action Map"), "set_duck_action_map","get_duck_action_map");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "body_height"), "set_body_height", "get_body_height");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "body_width"),  "set_body_width", "get_body_width");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_walk_angle"),  "set_max_walk_angle", "get_max_walk_angle");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "allow_toon_jumping"),  "set_allow_toon_jumping", "get_allow_toon_jumping");

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
        Targetbasis = NewBodyBasis;
        this->set_basis(NewBodyBasis);

    this->set_process_input(true);
    this->set_contact_monitor(true);
    this->set_max_contacts_reported(MaxContactReportCount);
    this->set_use_continuous_collision_detection(true);
    this->set_sleeping(true);
    this->set_sleeping(false);

    GroundRay = memnew(RayCast3D);
    GroundRay->set_position(Vector3(0,0,0));
    this->add_child(GroundRay);
    GroundRay->set_target_position(Vector3(0,-1*playerHieght,0));

}

void RigidPlayer::set_gravity_aline_vector(Vector3 Gravitydir){
    Basis BodyBasis = this->get_basis();
    Gravitydir.normalize();
    LastGravitydir = Gravitydir;
    LastGravityRight = BodyBasis.get_column(2).normalized().cross(Gravitydir);
    LastGravityRight.normalize();
    LastGravityForward = LastGravityRight.cross(-Gravitydir);
    Targetbasis = Basis(LastGravityRight,Gravitydir*-1.0f,LastGravityForward);
    Targetbasis.orthogonalize();
    this->set_basis(Targetbasis);
}

void RigidPlayer::AlineToGravity(){
    Basis BodyBasis = this->get_basis();
    Vector3 Gravitydir = this->get_gravity();
    if(Gravitydir.is_zero_approx()){
        return;
    }
    Gravitydir.normalize();


    LastGravitydir = Gravitydir;
    LastGravityRight = BodyBasis.get_column(2).normalized().cross(Gravitydir);
    LastGravityRight.normalize();
    LastGravityForward = LastGravityRight.cross(-Gravitydir);
    Targetbasis = Basis(LastGravityRight,Gravitydir*-1.0f,LastGravityForward);
    Targetbasis.orthogonalize();
    if(SlerpGravityOrientaions == true){
        float dot = RigidBodyUtilitys::dot_basis(this->get_basis(), Targetbasis);
        dot = +1;
        dot = dot/2;
        if(dot>= 0.99){
            //this->set_basis(Targetbasis);
            // not sure what I am doing wrong here 
            // snapping just felt like dog shit so
            // I turned it off
        }else{
            
        }
        this->set_basis(BodyBasis.slerp(Targetbasis,dot*(dot*0.25))); 
        
    }else{
        this->set_basis(Targetbasis);
    }
    
    
}

void RigidPlayer::handle_gravity_ort_logic(){
    
    Vector3 test = this->get_gravity();
    test.normalize();
    if(test != LastGravitydir && bisOrienttoGravity == true){
        AlineToGravity();
    }else if (!(Targetbasis.is_equal_approx(this->get_basis())) && bisOrienttoGravity == true) {
        AlineToGravity();
    }

    Vector3 Testing  = this->get_basis().get_column(1);
    test.normalize();

}

void RigidPlayer::_process(double delta){


    //_gdvirtual__extern_procces_call(delta);
}



void RigidPlayer::_physics_process(double delta){
    RigidBody3D* StandingOnRigidBodyPtr = nullptr;
    int contanct = this->get_contact_count();
    Vector3 HitNoraml = this->get_basis().get_column(1);
    float StandingAngle  = 0;
    float RayHitDist = -1;
    Raybisgrounded = false;
    isOverSlooped = true;
    if(GroundRay->is_colliding()){
        HitNoraml = GroundRay->get_collision_normal();
        if(dynamic_cast<RigidBody3D*>(GroundRay->get_collider()) ){
            StandingOnRigidBodyPtr = dynamic_cast<RigidBody3D*>(GroundRay->get_collider());
            //
        }
        float SlopeRadins = HitNoraml.angle_to(this->get_basis().get_column(1));
        StandingAngle = SlopeRadins * 180 / 3.14;
        RayHitDist = GroundRay->get_collision_point().distance_to(this->get_global_position());
        RayHitDist = RayHitDist- playerHieght/2;
        RayHitDist = Math::absf(RayHitDist);
        if(StandingAngle<MaxStandAngle){
            isOverSlooped = false;
            walkingPlane.set_normal(HitNoraml);
        }else{
            walkingPlane.set_normal(Vector3(0,0,0));
        }
        if(RayHitDist<0.22f){
            Raybisgrounded = !isOverSlooped; // looks werid but trust me
        } 
    }
    
    
      
    if(contanct == 0 || Raybisgrounded == false){
        bisGrounded = false;
        airtime = airtime+delta;
        // to britle
    }if ( contanct >0 && Raybisgrounded == true){
        if(bisGrounded == false){
            Just_Landed();
        }
        bisGrounded = true;
        airtime = 0;
    }

    Vector3 temptesting = this->get_linear_velocity();
    temptesting = walkingPlane.project(temptesting);
    CurrentSpeed = temptesting.length();

    //CurrentSpeed = (this->get_linear_velocity().x+
    //this->get_linear_velocity().y+
    //this->get_linear_velocity().z
    //);

    CurrentSpeed = Math::abs(CurrentSpeed);
    Vector2 InputDir = Vector2(
    input->get_action_raw_strength(MoveRightActionMappping) -input->get_action_raw_strength(MoveLeftActionMappping),
    //0.0f,
    input->get_action_raw_strength(MoveBackWardActionMappping) - input->get_action_raw_strength(MoveForwardActionMappping)
    );

    if(Math::abs(InputDir.x)< 0.6){
        InputDir.x = 0;
    }

    if(Math::abs(InputDir.y)< 0.6){
        InputDir.y = 0;
    }

    if(allowMovmentInput == false){
        InputDir = Vector2(0,0);
    }
    //print_line(InputDir);

    float FrictionBurn = Math::clamp(MaxSpeed - CurrentSpeed, 0.33f, 9999.0f);
    FrictionBurn = friction/(FrictionBurn*FrictionBurnPower);

    if(input != nullptr && piv_body != nullptr){
        if(InputDir.is_zero_approx()== false && bisGrounded == true){
            // on ground and inputing
            bisinputing = true;
            InputDir.normalize();
            Basis BodyBasis = piv_body->get_global_transform().get_basis();
            //
            Vector3 ForwardVec = BodyBasis.get_column(2);
            Vector3 RightVec = BodyBasis.get_column(0);
            Wishdir = (RightVec*InputDir.x) + (ForwardVec*InputDir.y);
            Wishdir.normalize();
 
            // im going to do rots to mke sure the player is not just walking forward forever
            // in flax I used a good physics engiene but godots is worse so I cant relie of physics mats

            Vector3 linVel = this->get_linear_velocity();
            linVel.normalize();
            float rot_wishdir = Wishdir.dot(linVel);
            Vector3 linvelFlat = walkingPlane.project(linVel);
            linvelFlat.normalize();
            SteerSwitchKey = NotMoving;
            
            setsterringEnums(InputDir, linvelFlat, ForwardVec, RightVec);

            // Creates an amount to reduce speed
            float speedDampiningFactor = Math::clamp(CurrentSpeed - MaxSpeed, 0.f, 99999999.f);
            //creates a new accel power to avoid goining light speed
            float effectiveAccel = Math::clamp(Acceleration - speedDampiningFactor, 00.0f, 99999999.f);
            // jazzhands gives us bost moving in perpducular movments from base move dir
            float jazzhands = MappedDotProduct(linVel, Wishdir) + (StrafeJumpAddPower*(CurrentSpeed/PD_DampiningPower));


            //the goal here is to make a scaler that will rotate the wishdir
            //so that the player dose not conserve forward speed as much as they do
            //this will make it feel more arcady
            //
            //
            



            //wishdir getting shifted
            
            Wishdir = walkingPlane.project(Wishdir);
            CreateTwistedWishDir(Wishdir , linvelFlat);
            

            /*I need to rotate the wishdir to corspond to walking angles*/
            Vector3 Force = Wishdir * jazzhands * this->get_mass() * effectiveAccel * delta - (linVel * this->get_mass() * PD_DampiningPower * delta);
            // need to do planer rots
            Force = Force/FrictionBurn;
            apply_central_force(Force);

        }else if (InputDir.is_zero_approx()== true && bisGrounded == true){
            //this is auto slow no di;
            bisinputing = false;
            if ( autoslow == true && bisGrounded == true && input->is_action_pressed(JumpActionMappping) == false){                 
                Wishdir = this->get_linear_velocity();
                if(!Wishdir.is_zero_approx()){
                    Wishdir.normalize();
                    Wishdir = Wishdir*-1.f;
                    Vector3 linVel = this->get_linear_velocity();
                    linVel.normalize();
                    float speedDampiningFactor = Math::clamp(CurrentSpeed - MaxSpeed, 0.f, 99999999.f);
                    float effectiveAccel = Math::clamp(Acceleration - speedDampiningFactor, 00.0f, 99999999.f);
                    float jazzhands = MappedDotProduct(linVel, Wishdir) + (StrafeJumpAddPower*(CurrentSpeed/PD_DampiningPower));
                    Vector3 Force = Wishdir * jazzhands * this->get_mass() * effectiveAccel * delta - (linVel * this->get_mass() * PD_DampiningPower * delta);
                    Force = Force*autoslowPower;
                    Force = Force/FrictionBurn;

                    if(contanct < 2 &&Force.is_equal_approx(Vector3(0,0,0)) || this->get_linear_velocity().is_zero_approx() || this->get_linear_velocity().abs() < Vector3(.1,.1,.1)){
                        this->set_linear_velocity(Vector3(0,0,0));
                        just_stopped_moving();
                            //need to ad exceptions to when standing on rigid bodys for both
                    }else{

                        this->apply_central_force(Force);
                        
                    }

                }

            }
            _gdvirtual__extern_physics_process_call(delta);
        }
        
        if (piv_body != nullptr && bisGrounded == false ){
            // in air not sliding
            bisinputing = true;
            InputDir.normalize();
            Basis BodyBasis = piv_body->get_global_transform().get_basis();
            Vector3 ForwardVec = BodyBasis.get_column(2);
            Vector3 RightVec = BodyBasis.get_column(0);
            Wishdir = (RightVec*InputDir.x) + (ForwardVec*InputDir.y);
            Wishdir.normalize();
            Vector3 linVel = this->get_linear_velocity();
            linVel.normalize();
            float speedDampiningFactor = Math::clamp(CurrentSpeed - MaxSpeed, 0.f, 99999999.f);
            float effectiveAccel = Math::clamp(Acceleration - speedDampiningFactor, 00.0f, 99999999.f);
            float jazzhands = MappedDotProduct(linVel, Wishdir) + (StrafeJumpAddPower*(CurrentSpeed/PD_DampiningPower));
            Vector3 Force = Wishdir * jazzhands * this->get_mass() * effectiveAccel * delta - (linVel * this->get_mass() * PD_DampiningPower * delta);
            Force = Force/aircontrol;
            apply_central_force(Force);
        }
        if (piv_body != nullptr && bisGrounded == false && isOverSlooped == true){
            // in air not sliding

            // over slooped
            /*
            bisinputing = true;
            InputDir.normalize();
            Basis BodyBasis = piv_body->get_global_transform().get_basis();
            Vector3 ForwardVec = BodyBasis.get_column(2);
            Vector3 RightVec = BodyBasis.get_column(0);
            Wishdir = (RightVec*InputDir.x) + (ForwardVec*InputDir.y);
            Wishdir.normalize();
            Vector3 linVel = this->get_linear_velocity();
            linVel.normalize();
            float speedDampiningFactor = Math::clamp(CurrentSpeed - MaxSpeed, 0.f, 99999999.f);
            float effectiveAccel = Math::clamp(Acceleration - speedDampiningFactor, 00.0f, 99999999.f);
            float jazzhands = MappedDotProduct(linVel, Wishdir) + (StrafeJumpAddPower*(CurrentSpeed/PD_DampiningPower));
            Vector3 Force = Wishdir * jazzhands * this->get_mass() * effectiveAccel * delta - (linVel * this->get_mass() * aircontrol * PD_DampiningPower * delta);
            apply_central_force(Force);
            */
        }

        if(input->is_action_just_pressed(JumpActionMappping)){
            jump();
        }
        debuginput();
    }

    handle_gravity_ort_logic();
    
}

void RigidPlayer::setsterringEnums(Vector2 &input, Vector3 &lin, Vector3 &forward, Vector3 &right){
    if(lin.dot(forward)<0){
                // the player is moving forward
                SteerSwitchKey = Forward;
                if(lin.dot(right)<0){
                    //moivng forward left
                    SteerSwitchKey = ForwardLeft;
                }else{
                    //movving forward right
                    SteerSwitchKey = ForwardRight;
                }
            }else{
                //player is moving backward
                SteerSwitchKey = Backward;
                if(lin.dot(right)<0){
                    //moivng backward left
                    SteerSwitchKey = BackwardLeft;
                }else{
                    //movving backward right
                    SteerSwitchKey = BackwardRight;

                }
            }
            InputWishdirState = NoInput;
            if(input.x>0){
                //print_line("Right");
                InputWishdirState = WishRight;
            }
            if(input.x<0){
                //print_line("left");
                InputWishdirState = WishLeft;
            }
            if(input.y > 0){
                //print_line("backwards");
                InputWishdirState = WishBackward;
            }
            if(input.y < 0){
                //print_line("forwwards");
                InputWishdirState = WishForward;
            }
            if(input.x > 0 && input.y > 0){
                //print_line("back right");
                InputWishdirState = WishBackwardRight;
            }
            if(input.x < 0 && input.y > 0){
                //print_line("back left");
                InputWishdirState = WishBackwardLeft;
            }
            if(input.x < 0 && input.y < 0){
                //print_line("Forward Left");
                InputWishdirState = WishForwardLeft;
            }
            if(input.x > 0 && input.y < 0){
                //print_line("Forward Right");
                InputWishdirState = WishForwardRight;
            }
    
    return;

                switch (SteerSwitchKey) {
                case 0:
                    print_line("forward");
                    break;
                case 1:
                    print_line("backward");
                    break;
                case 2:
                    print_line("forward left");
                    break;
                case 3:
                    print_line("forward Right");
                    break;
                case 4:
                    print_line("backward left");
                    break;
                case 5:
                    print_line("backward right");
                    break;
                case 6:
                    print_line(" not moving;");
            
            }

            switch (InputWishdirState){
                case 0:
                    print_line("WishForward");
                    break;
                case 1:
                    print_line("wish backward");
                    break;
                case 2:
                    print_line("wish left");
                    break;
                case 3:
                    print_line("wish right");
                    break;
                case 4:
                    print_line("wish forward left");
                    break;
                case 5:
                    print_line("wish forward right");
                    break;
                case 6:
                    print_line("wish backward left");
                    break;
                case 7:
                    print_line("wish backward right");
                    break;
                case 8:
                    print_line( "no input");

            }
}

void RigidPlayer:: CreateTwistedWishDir(Vector3 &wish, Vector3 &Lin){

}

void RigidPlayer::just_stopped_moving(){

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
    if(currentjumps == 0 || airtime>CoyoteTime)
        return;
    Vector3 GravityDir = (this->get_gravity());
    GravityDir.normalize();
    Vector3 ToonJumpPower = this->get_linear_velocity()*GravityDir;
    GravityDir = GravityDir * -1.f;
    ToonJumpPower = ToonJumpPower.clamp(Vector3(0,0,0), ToonJumpPower); // not working fix later;
    ToonJumpPower = ToonJumpPower*float(allowToonJumping);
    this->apply_central_impulse( (ToonJumpPower * this->get_mass()) + ((GravityDir*this->get_mass()) * jumppower)  );
    currentjumps = currentjumps-1;
    _gdvirtual__extern_just_jumped_call();
}

void RigidPlayer::Just_Landed(){
    rez_jump();
    _gdvirtual__extern_just_landed_call();
}

void RigidPlayer::rez_jump(){
    currentjumps = maxjumps;
}

void RigidPlayer::orbitcamtoggle(){

    if(camrea_wrapper!= nullptr){
        Vector3 camloc = camrea_wrapper->get_position();
        if(camloc == Vector3 (0.0f,0.0f,0.0f)){
            camrea_wrapper->set_position(Vector3(0,0,obit_cam_dist));
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

float RigidPlayer::MappedDotProduct(Vector3 x , Vector3 y) {
    float out = x.dot(y);
    //0 for aligned vectors // changed to .33
    //1 for perpendicular
    //2 for opposite directions // changed to 1.33
    float shifter = .12f;
    if (out > 0) {
        return Math::lerp(0.33f - shifter, 1.f-shifter-shifter,1 - out);

    }
    else {
        return Math::lerp(1.0f-shifter-shifter, 1.33f-shifter, -out);
    }
}
