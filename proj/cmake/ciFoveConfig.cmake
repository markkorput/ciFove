if( NOT TARGET ciFove )
	get_filename_component( ciFove_PATH "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE )
	get_filename_component( CINDER_PATH "${ciFove_PATH}/../.." ABSOLUTE )
	get_filename_component( ciFove_SOURCE_PATH "${ciFove_PATH}/src" ABSOLUTE )
	get_filename_component( ciFove_INCLUDE_PATH "${ciFove_PATH}/include" ABSOLUTE )

	get_filename_component( FOVE_SDK_PATH "${ciFove_PATH}/lib/FoveSdk" ABSOLUTE )

	if(WIN32)
		FILE(GLOB ciFove_SOURCES ${ciFove_SOURCE_PATH}/*.cpp)
	else(WIN32)
		FILE(GLOB ciFove_SOURCES ${ciFove_SOURCE_PATH}/*.cpp ${ciFove_SOURCE_PATH}/mock/*.cpp)
	endif(WIN32)

	add_library( ciFove ${ciFove_SOURCES} )

	target_include_directories( ciFove PUBLIC "${ciFove_INCLUDE_PATH}" )
	target_include_directories( ciFove PUBLIC "${FOVE_SDK_PATH}/include" )
	target_include_directories( ciFove SYSTEM BEFORE PUBLIC "${CINDER_PATH}/include" )

	if( NOT TARGET cinder )
		    include( "${CINDER_PATH}/proj/cmake/configure.cmake" )
		    find_package( cinder REQUIRED PATHS
		        "${CINDER_PATH}/${CINDER_LIB_DIRECTORY}"
		        "$ENV{CINDER_PATH}/${CINDER_LIB_DIRECTORY}" )
	endif()

	target_link_libraries( ciFove PRIVATE cinder )
endif()
