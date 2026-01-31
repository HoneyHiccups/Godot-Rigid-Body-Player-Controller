extends Node3D


@onready var Player : RigidPlayer = $".."


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass # Replace with function body.


func _process(delta: float) -> void:
	var start :Vector3 = Player.global_position
	var wishdir:Vector3 = Player.get_wish_dir()
	var speed = Player.linear_velocity
	speed = speed.length()/4
	var target:Vector3 = start+(wishdir*speed)
	DebugDraw3D.draw_line(start,target,Color(255,0,0))
	DebugDraw3D.draw_line(start,(Player.get_gravity()*3000),Color(0,255,0))
