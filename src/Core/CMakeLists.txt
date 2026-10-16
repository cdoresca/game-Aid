
file(GLOB FILES CONFIGURE_DEPENDS 
    *.cpp 
)

add_library(Core ${FILES})

add_library(${PROJECT_NAME}::Core ALIAS Core)

target_include_directories(Core
    PUBLIC  ${INCLUDE_DIR}/Core
    PRIVATE ${SOURCE_DIR}/Core
)

target_compile_features(Core PUBLIC cxx_std_17)