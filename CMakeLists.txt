cmake_minimum_required(VERSION 3.27)
project(twoseventen)

set(CMAKE_CXX_STANDARD 17)

add_executable(twoseventen main.cpp
        include/deck.h
        include/player.h
        include/commands/factory.h
        include/commands/command.h
        include/commands/command_impl.h
        include/commands/help.h
        include/bot.h
        include/dealer.h
        src/commands/factory.cpp
        src/commands/factory.cpp
        src/commands/command.cpp
        src/commands/view.cpp
        src/commands/help.cpp
        src/deck.cpp
        src/player.cpp
        src/commands/quit.cpp
        src/commands/play.cpp
        src/bot.cpp
        src/dealer.cpp)
