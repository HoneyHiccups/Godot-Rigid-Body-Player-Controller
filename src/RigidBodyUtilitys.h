#pragma once

#include "godot_cpp/core/math.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "godot_cpp/classes/ref_counted.hpp"
class RigidBodyUtilitys : public godot::RefCounted{
    GDCLASS(RigidBodyUtilitys, godot::RefCounted)
    
private:

    
protected:
    // Required for GDExtension - binds methods to Godot
    static void _bind_methods();
    
public:

    static godot::Vector3 project_onto_plane(const godot::Vector3& vector, const godot::Vector3& plane_normal);


};
