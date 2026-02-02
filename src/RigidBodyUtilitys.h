#pragma once

#include "godot_cpp/core/math.hpp"
#include "godot_cpp/variant/basis.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "godot_cpp/variant/vector3.hpp"
class RigidBodyUtilitys : public godot::RefCounted{
    GDCLASS(RigidBodyUtilitys, godot::RefCounted)
    
private:

    
protected:
    // Required for GDExtension - binds methods to Godot
    static void _bind_methods();
    
public:

    static godot::Vector3 project_onto_plane(const godot::Vector3& vector, const godot::Vector3& plane_normal);

    static float dot_basis(const godot::Basis &b1,const godot::Basis &b2);

};
