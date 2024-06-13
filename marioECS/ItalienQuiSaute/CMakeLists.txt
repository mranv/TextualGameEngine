cmake_minimum_required(VERSION 3.8)

project(ItalienQuiSaute)

# Set C++ version
set(CMAKE_CXX_STANDARD 20)

# Tell CMake to use Vcpkg for package management
set(VCPKG_TARGET_TRIPLET "x64-windows")
set(CMAKE_TOOLCHAIN_FILE "C:/Users/AnubhavGain/Desktop/d3v/TextualGameEngine/vcpkg/scripts/buildsystems/vcpkg.cmake")

# Set CMAKE_PREFIX_PATH to include the vcpkg install directory
set(CMAKE_PREFIX_PATH "C:/Users/AnubhavGain/Desktop/d3v/TextualGameEngine/vcpkg/installed/x64-windows")

# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Find CURL
find_package(CURL REQUIRED)

# Find libcurl-simple-https
find_package(libcurl-simple-https REQUIRED)

# Add source files
set(SOURCES
    Game/Source/FileReader.hpp
    Game/Source/GameManager.hpp
    Game/Source/ItalienQuiSaute.cpp
    Game/Source/Level.hpp
    Game/Source/Menu.hpp
    
    Engine/API/RequestManager.hpp
    Engine/API/nlohmann/json.hpp
    Engine/API/nlohmann/json_fwd.hpp
    
    Engine/Components/CameraComponent.hpp
    Engine/Components/ColliderComponent.hpp
    Engine/Components/Component.hpp
    Engine/Components/GravityComponent.hpp
    Engine/Components/HealthComponent.hpp
    Engine/Components/PlayerControllerComponent.hpp
    Engine/Components/PlayerStateComponent.hpp
    Engine/Components/SpriteRendererComponent.hpp
    Engine/Components/TransformComponent.hpp
    
    Engine/Entities/Background.hpp
    Engine/Entities/Enemy.hpp
    Engine/Entities/Entity.hpp
    Engine/Entities/Flag.hpp
    Engine/Entities/GameObject.hpp
    Engine/Entities/PlayerEntity.hpp
    
    Engine/System/Libraries/Maths/Vector2.h
    
    Engine/System/Managers/AnimationsManager.hpp
    Engine/System/Managers/EntityManager.hpp
    Engine/System/Managers/InputManager.hpp
    Engine/System/Managers/TexturesManager.hpp
)

# Add executable
add_executable(ItalienQuiSaute ${SOURCES})

# Include directories for CURL
include_directories(${CURL_INCLUDE_DIRS})

# Link SFML libraries
target_link_libraries(ItalienQuiSaute sfml-graphics sfml-window sfml-system)

# Link CURL and libcurl-simple-https libraries
target_link_libraries(ItalienQuiSaute ${CURL_LIBRARIES} libcurl-simple-https)