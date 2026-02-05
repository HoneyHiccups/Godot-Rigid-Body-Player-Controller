#include "RigidBodyUtilitys.h"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "godot_cpp/variant/vector3.hpp"


void RigidBodyUtilitys:: _bind_methods(){
    godot::ClassDB::bind_static_method("RigidBodyUtilitys", godot::D_METHOD("project_onto_plane", "vector", "plane_normal"),&RigidBodyUtilitys::project_onto_plane);
    godot::ClassDB::bind_static_method("RigidBodyUtilitys", godot::D_METHOD("dot_basis", "Basis", "Basis"),&RigidBodyUtilitys::dot_basis);
}

godot::Vector3 RigidBodyUtilitys::project_onto_plane( const godot::Vector3& vector, const godot::Vector3& plane_normal) {
    
    float dot = vector.dot(plane_normal);
    godot::Vector3 out = vector - (plane_normal * dot);
    out.normalize();
    return out;
}

float RigidBodyUtilitys::dot_basis(const godot::Basis &b1,const godot::Basis &b2){

    float results[3];
    results[0] = b1.get_column(0).dot(b2.get_column(0));
    results[1] = b1.get_column(1).dot(b2.get_column(1));
    results[2] = b1.get_column(2).dot(b2.get_column(2));

    float final = results[0] +results[1] + results[2];
    return final /3.0f;


}

