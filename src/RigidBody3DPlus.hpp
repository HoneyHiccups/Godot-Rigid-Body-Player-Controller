#pragma once

#include "godot_cpp/classes/cylinder_mesh.hpp"
#include "godot_cpp/classes/node3d.hpp"
#include "godot_cpp/classes/ray_cast3d.hpp"
#include "godot_cpp/classes/rigid_body3d.hpp"
#include <sys/types.h>
#include <cstdint>


using namespace godot;



class RigidBody3DPlus : public RigidBody3D{
    GDCLASS(RigidBody3DPlus, RigidBody3D)

    protected:
    static void _bind_methods();
    
    private:
    enum PickupShape{ //right where just gunna use the shpere
        Sphere,
        Box,
        Cylinder,
        Capsule
    };
    u_int8_t SphereR = 0;

    public:

    void set_sphere_shape_radius(uint8_t n){SphereR = n;}
    float get_sphere_shape_radius(){return float(SphereR);}


};
