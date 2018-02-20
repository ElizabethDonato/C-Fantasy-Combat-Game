
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = ValidInt.o Menu.o UserInput.o Game.o Creature.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o
SRCS = fantasyGame.cpp 

all: ValidInt Menu UserInput Game Creature Barbarian Vampire BlueMen Medusa HarryPotter fantasyGame

ValidInt: ValidInt.hpp ValidInt.cpp
	${CXX} ${CXXFLAGS} ValidInt.cpp -c

Menu: ValidInt.hpp Menu.hpp ValidInt.cpp Menu.cpp
	${CXX} ${CXXFLAGS} ValidInt.cpp Menu.cpp -c

UserInput: UserInput.hpp UserInput.cpp
	${CXX} ${CXXFLAGS} UserInput.cpp -c

Game: ValidInt.hpp Menu.hpp Game.hpp ValidInt.cpp Menu.cpp
	${CXX} ${CXXFLAGS} ValidInt.cpp Menu.cpp -c

Creature: Creature.hpp Creature.cpp
	${CXX} ${CXXFLAGS} Creature.cpp -c

Barbarian: Barbarian.hpp Barbarian.cpp
	${CXX} ${CXXFLAGS} Barbarian.cpp -c

Vampire: Vampire.hpp Vampire.cpp
	${CXX} ${CXXFLAGS} Vampire.cpp -c

BlueMen: BlueMen.hpp BlueMen.cpp
	${CXX} ${CXXFLAGS} BlueMen.cpp -c

Medusa: Medusa.hpp Medusa.cpp
	${CXX} ${CXXFLAGS} Medusa.cpp -c

HarryPotter: HarryPotter.hpp HarryPotter.cpp
	${CXX} ${CXXFLAGS} HarryPotter.cpp -c

fantasyGame: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} ${SRCS} -o fantasyGame

val:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-fds=yes ./fantasyGame

clean:
	rm -f *.o fantasyGame
