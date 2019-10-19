CXX = g++
CXXFLAGS = -std=c++0x
# CXXFLAGS += -Wall
# CXXFLAGS += -pedantic-errors
# CXXFLAGS += -g
LDFLAGS =
#-lboost_date_time

SRCS = main.cpp map.cpp Space.cpp  pokemon.cpp Pikachu.cpp Pidgey.cpp Rattata.cpp pokemonSpace.cpp pidgeySpace.cpp rattataSpace.cpp item.cpp itemContainer.cpp potionSpace.cpp escapeRopeSpace.cpp

HEADERS = map.hpp Space.hpp pokemon.hpp Pikachu.hpp Pidgey.hpp Rattata.hpp pokemonSpace.hpp pidgeySpace.hpp rattataSpace.hpp item.hpp itemContainer.hpp potionSpace.hpp escapeRopeSpace.hpp

OBJS = main.o map.o Space.o pokemon.o Pikachu.o Pidgey.o Rattata.o pokemonSpace.o pidgeySpace.o rattataSpace.o item.o itemContainer.o potionSpace.o escapeRopeSpace.o

project5: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o project5


${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o project5
