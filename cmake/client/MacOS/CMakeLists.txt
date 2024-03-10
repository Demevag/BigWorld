CMAKE_MINIMUM_REQUIRED( VERSION 3.23 )

INCLUDE (client/BWClient)

SET( BW_LIBRARY_PROJECTS
	# BigWorld
	memhook				lib/memhook
	ashes				lib/ashes
    asset_pipeline		lib/asset_pipeline
	camera				lib/camera
	chunk				lib/chunk
	chunk_scene_adapter lib/chunk_scene_adapter
	connection			lib/connection
	connection_model	lib/connection_model
	cstdmf				lib/cstdmf
	duplo				lib/duplo
	entitydef			lib/entitydef
	input				lib/input
	math				lib/math
	model				lib/model
	moo					lib/moo
	network				lib/network
	open_automate		lib/open_automate
	particle			lib/particle
	physics2			lib/physics2
	post_processing		lib/post_processing
	pyscript			lib/pyscript
	resmgr				lib/resmgr
	romp				lib/romp
	scene				lib/scene
	compiled_space		lib/compiled_space
	space				lib/space
	script				lib/script
	terrain				lib/terrain
	urlrequest			lib/urlrequest
	waypoint			lib/waypoint
	web_render			lib/web_render

	# Third party
	libpng				third_party/png/projects/visualc71
	nedalloc			third_party/nedalloc
	zip					third_party/zip
	libpython			third_party/python
	re2					third_party/re2
)

IF( BW_FMOD_SUPPORT )
	SET( BW_LIBRARY_PROJECTS ${BW_LIBRARY_PROJECTS}
		fmodsound			lib/fmodsound
	)
ENDIF()

ADD_SUBDIRECTORY (${BW_SOURCE_DIR}/client ${BW_GAME_DIR}/client)

BW_LINK_PROJECTS(BWClient "${BW_LIBRARY_PROJECTS}")