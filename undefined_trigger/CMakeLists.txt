add_executable( undefined_trigger undefined_trigger.cpp SobogusInterface.h SobogusInterface.cpp FrictionProblem.hpp FrictionProblem.cpp FrictionProblem.impl.hpp Cadoux.hpp )

find_package( Eigen3 3.2.7 REQUIRED )
target_include_directories( undefined_trigger SYSTEM PRIVATE ${EIGEN3_INCLUDE_DIR} )

target_compile_definitions( undefined_trigger PRIVATE EIGEN_DONT_PARALLELIZE )
if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
  target_compile_definitions( undefined_trigger PRIVATE EIGEN_DONT_ALIGN EIGEN_INITIALIZE_MATRICES_BY_NAN )
endif()

find_package( Sobogus REQUIRED )
target_include_directories( undefined_trigger SYSTEM PRIVATE ${SOBOGUS_INCLUDE_DIR} )
