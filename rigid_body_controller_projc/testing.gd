extends Node3D


@onready var Player : RigidPlayer = $".."
@export var DebugDraw:bool = true
@onready var landvol : float =0;
# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	Player.set_allow_align_with_gravity(true)
	landvol = land.volume_linear


func _process(delta: float) -> void:
	if(DebugDraw == true):
		debugdraw()

func debugdraw():
	var start :Vector3 = Player.global_position
	var wishdir:Vector3 = Player.get_wish_dir()
	var speed = Player.linear_velocity
	speed = speed.length()/4
	var target:Vector3 = start+(wishdir*speed)
	DebugDraw3D.draw_line(start,target,Color(255,0,0))
	DebugDraw3D.draw_line(start,(Player.get_gravity()*3000),Color(0,255,0))

@onready var foot_step: AudioStreamPlayer = $"../FootStep"
@onready var jump: AudioStreamPlayer = $"../Jump"
@onready var land: AudioStreamPlayer = $"../Land"


func _on_rigid_player_pawn_foot_step() -> void:
	foot_step.play()
	return;



func _on_rigid_player_pawn_jumped() -> void:
	jump.play();
	return;



func _on_rigid_player_pawn_just_landed(power: float) -> void:
	land.volume_linear = landvol*power
	land.play();
	return;
