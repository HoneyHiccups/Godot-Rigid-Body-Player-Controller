#pragma once

#include "godot_cpp/classes/node3d.hpp"
#include "godot_cpp/classes/rigid_body3d.hpp"
#include "godot_cpp/classes/wrapped.hpp"

class RigidPlayer : public godot::RigidBody3D{
    GDCLASS(RigidPlayer, godot::RigidBody3D)

    protected:
        static void _bind_method();
    

    private:
        
        

    public:
        void _ready() override;
        void virtual _virtual_ready();


    protected:

    private:
        godot::Node3D piv_body;
        godot::Node3D piv_head;
        godot::Node3D piv_camrea_shake;

    public:
    
};
