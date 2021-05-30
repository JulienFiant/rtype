set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")

add_library(
    game-engine
    ./GameEngine/include/Audio.h
    ./GameEngine/include/Graphics.h
    ./GameEngine/include/Physics.h
    ./GameEngine/include/Audio/AudioEngine.h
    ./GameEngine/include/Audio/IAudio.h
    ./GameEngine/include/Audio/Music.h
    ./GameEngine/include/Audio/Sound.h
    ./GameEngine/include/Graphics/AAnimation.hpp
    ./GameEngine/include/Graphics/AGraphicComponent.hpp
    ./GameEngine/include/Graphics/AnimationBasic.h
    ./GameEngine/include/Graphics/AnimationKit.h
    ./GameEngine/include/Graphics/AScene.hpp
    ./GameEngine/include/Graphics/CPhysicAnimated.hpp
    ./GameEngine/include/Graphics/GCAnimated.h
    ./GameEngine/include/Graphics/GCBasic.h
    ./GameEngine/include/Graphics/GCTextBox.h
    ./GameEngine/include/Graphics/GraphicEngine.h
    ./GameEngine/include/Graphics/IGraphics.h
    ./GameEngine/include/Graphics/NoAnimation.h
    ./GameEngine/include/Graphics/AnimationScroller.h
    ./GameEngine/include/Graphics/SceneSfml.h
    ./GameEngine/include/Physics/Collider.hpp
    ./GameEngine/include/Physics/Physics.hpp
    ./GameEngine/include/RType/Player.hpp
    ./GameEngine/include/IEngine.hpp
    ./GameEngine/include/RessourceManager.hpp
    ./GameEngine/include/Settings.hpp
    ./GameEngine/include/GameEngine.hpp
    ./GameEngine/include/AEntity.hpp
    ./GameEngine/include/AInteractive.hpp
    ./GameEngine/src/AnimationBasic.cpp
    ./GameEngine/src/AnimationKit.cpp
    ./GameEngine/src/AudioEngine.cpp
    ./GameEngine/src/CPhysicAnimated.cpp
    ./GameEngine/src/GCAnimated.cpp
    ./GameEngine/src/GCBasic.cpp
    ./GameEngine/src/GCTextBox.cpp
    ./GameEngine/src/GraphicEngine.cpp
    ./GameEngine/src/Music.cpp
    ./GameEngine/src/NoAnimation.cpp
    ./GameEngine/src/Collider.cpp
    ./GameEngine/src/Physics.cpp
    ./GameEngine/src/RessourceManager.cpp
    ./GameEngine/src/SceneSfml.cpp
    ./GameEngine/src/Settings.cpp
    ./GameEngine/src/Sound.cpp
    ./GameEngine/src/AnimationScroller.cpp
    ./GameEngine/src/GameEngine.cpp
    ./GameEngine/SfmlTools/Color/Color.hpp
    ./GameEngine/SfmlTools/Color/ColorAlgo.hpp
    ./GameEngine/SfmlTools/Color/Color.cpp
    ./GameEngine/SfmlTools/Color/ColorAlgo.cpp
    ./GameEngine/SfmlTools/Math/Trigonometry.hpp
    ./GameEngine/SfmlTools/Math/VectorCalc.hpp
    ./GameEngine/SfmlTools/Math/Trigonometry.cpp
    ./GameEngine/SfmlTools/Math/VectorCalc.cpp
    ./GameEngine/SfmlTools/PixelBuffer/DrawPixelBuffer.hpp
    ./GameEngine/SfmlTools/PixelBuffer/PixelBuffer.hpp
    ./GameEngine/SfmlTools/PixelBuffer/DrawPixelBuffer.cpp
    ./GameEngine/SfmlTools/PixelBuffer/PixelBuffer.cpp
    ./GameEngine/SfmlTools/Tools/Compare.hpp
    ./GameEngine/SfmlTools/Tools/Parser.hpp
    ./GameEngine/SfmlTools/Tools/Compare.cpp
    ./GameEngine/SfmlTools/Tools/Parser.cpp
    ./GameEngine/SfmlTools/UI/UIBox.hpp
    ./GameEngine/SfmlTools/UI/UIManager.hpp
    ./GameEngine/SfmlTools/UI/UIRelativator.hpp
    ./GameEngine/SfmlTools/UI/UIBox.cpp
    ./GameEngine/SfmlTools/UI/UIManager.cpp
    ./GameEngine/SfmlTools/UI/UIRelativator.cpp
    ./GameEngine/Network/ClientInfo.cpp
    ./GameEngine/Network/ClientInfo.hpp
    ./GameEngine/Network/ClientUdp.cpp
    ./GameEngine/Network/ClientUdp.hpp
    ./GameEngine/Network/INetwork.hpp
    ./GameEngine/Network/ServerUdp.cpp
    ./GameEngine/Network/ServerUdp.hpp
)

target_link_libraries(game-engine PRIVATE ${CONAN_LIBS} -lm -pthread)

target_include_directories(game-engine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_compile_definitions(game-engine PUBLIC ENGINE_VERISON=0.5)
