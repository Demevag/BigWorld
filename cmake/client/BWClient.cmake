CMAKE_MINIMUM_REQUIRED( VERSION 3.23 )

INCLUDE( utils/BWMacros )

BW_ADD_CONSUMER_RELEASE_CONFIG()

SET_PROPERTY( DIRECTORY APPEND PROPERTY
	COMPILE_DEFINITIONS_CONSUMER_RELEASE
	CONSUMER_CLIENT
	_RELEASE )

SET( USE_MEMHOOK ON )
# To enable Scaleform support, you need the Scaleform GFx SDK, and
# probably have to modify FindScaleformSDK.cmake to locate it.
SET( BW_SCALEFORM_SUPPORT OFF )

ADD_DEFINITIONS( -DBW_CLIENT )
ADD_DEFINITIONS( -DUSE_MEMHOOK )
ADD_DEFINITIONS( -DALLOW_STACK_CONTAINER )

IF( BW_UNIT_TESTS_ENABLED )
	MESSAGE( STATUS "Unit tests enabled for client." )
	ENABLE_TESTING()

	SET( BW_CLIENT_UNIT_TEST_LIBRARIES
		CppUnitLite2		third_party/CppUnitLite2
		unit_test_lib		lib/unit_test_lib
		)

	SET( BW_CLIENT_UNIT_TEST_BINARIES
		compiled_space_unit_test lib/compiled_space/unit_test
		cstdmf_unit_test	lib/cstdmf/unit_test
		duplo_unit_test		lib/duplo/unit_test
		entitydef_unit_test	lib/entitydef/unit_test
		math_unit_test		lib/math/unit_test
		model_unit_test		lib/model/unit_test
		moo_unit_test		lib/moo/unit_test
		network_unit_test	lib/network/unit_test
		particle_unit_test	lib/particle/unit_test
		physics2_unit_test	lib/physics2/unit_test
		pyscript_unit_test	lib/pyscript/unit_test
		resmgr_unit_test	lib/resmgr/unit_test
		scene_unit_test		lib/scene/unit_test
		script_unit_test	lib/script/unit_test
		space_unit_test		lib/space/unit_test
		)
ENDIF()


IF( BW_FMOD_SUPPORT )
	SET( BW_LIBRARY_PROJECTS ${BW_LIBRARY_PROJECTS}
		fmodsound			lib/fmodsound
	)
ENDIF()

IF( BW_SCALEFORM_SUPPORT )
	SET( BW_LIBRARY_PROJECTS ${BW_LIBRARY_PROJECTS}
		scaleform			lib/scaleform
	)
ENDIF()

IF( BW_SPEEDTREE_SUPPORT )
	SET( BW_LIBRARY_PROJECTS ${BW_LIBRARY_PROJECTS}
		speedtree			lib/speedtree
	)
ENDIF()

SET( BW_BINARY_PROJECTS
	bwclient			client
	emptyvoip			lib/emptyvoip
	${BW_CLIENT_UNIT_TEST_BINARIES}
)

