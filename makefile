CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -pedantic-errors
CXXFLAGS += -Wall
LDFLAGS = -lboost_date_time
OBJS = main.o LivingRoom.o Kitchen.o Garage.o Game.o Bedroom2.o Bedroom.o Bathroom.o Bathroom2.o validateMenu.o Space.o Player.o menu.hpp
SRCS = main.cpp LivingRoom.cpp Kitchen.cpp Garage.cpp Game.cpp Bedroom2.cpp Bedroom.cpp Bathroom.cpp Bathroom2.cpp validateMenu.cpp Space.cpp Player.cpp menu.cpp
HEADERS = LivingRoom.hpp Kitchen.hpp Garage.hpp Game.hpp Bedroom2.hpp Bedroom.hpp Bathroom.hpp Bathroom2.hpp validateMenu.hpp Space.hpp Player.hpp menu.hpp

main: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}:${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

.PHONY: clean


clean: 
	-rm ${OBJS} main
