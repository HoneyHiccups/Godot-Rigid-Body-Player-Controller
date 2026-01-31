#include "RigidBodyUtilitys.h"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "godot_cpp/variant/vector3.hpp"


void RigidBodyUtilitys:: _bind_methods(){
    godot::ClassDB::bind_static_method("RigidBodyUtilitys", godot::D_METHOD("project_onto_plane", "vector", "plane_normal"),&RigidBodyUtilitys::project_onto_plane);
}

godot::Vector3 RigidBodyUtilitys::project_onto_plane( const godot::Vector3& vector, const godot::Vector3& plane_normal) {
    
    float dot = vector.dot(plane_normal);
    godot::Vector3 out = vector - (plane_normal * dot);
    out.normalize();
    return out;
}
