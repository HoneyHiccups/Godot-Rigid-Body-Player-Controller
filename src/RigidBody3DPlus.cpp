#include "RigidBody3DPlus.hpp"

void RigidBody3DPlus::_bind_methods(){

    ClassDB::bind_method(D_METHOD("set_sphere_shape_radius", "sphere_shape_radius"),      &RigidBody3DPlus::set_sphere_shape_radius);
    ClassDB::bind_method(D_METHOD("get_sphere_shape_radius"),                             &RigidBody3DPlus::get_sphere_shape_radius);

    ClassDB::bind_method(D_METHOD("set_b_is_held", "b_is_held"),      &RigidBody3DPlus::set_b_is_held);
    ClassDB::bind_method(D_METHOD("get_b_is_held"),                             &RigidBody3DPlus::get_b_is_held);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "sphere_shape_radius"), "set_sphere_shape_radius", "get_sphere_shape_radius");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "b_is_held"), "set_b_is_held", "get_b_is_held");

}
