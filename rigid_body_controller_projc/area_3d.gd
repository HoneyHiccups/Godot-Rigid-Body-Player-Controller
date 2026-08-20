extends Area3D

func _on_body_shape_entered(body_rid: RID, body: Node3D, body_shape_index: int, local_shape_index: int) -> void:
	return
	if(body is RigidPlayer):
		body.set_allow_align_with_gravity(true)
	


func _on_body_shape_exited(body_rid: RID, body: Node3D, body_shape_index: int, local_shape_index: int) -> void:
	return;
	if(body is RigidPlayer):
		body.set_allow_align_with_gravity(false)
		body.set_gravity_aline_vector(Vector3(0,-1,0))
