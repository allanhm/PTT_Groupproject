FLAGS = -pedantic-errors -std=c++11

item.o: item.cpp item.h
	g++ $(FLAGS) -c item.cpp

load.o: load.cpp load.h characterinfo.h
	g++ $(FLAGS) -c load.cpp

save.o: save.cpp save.h
	g++ $(FLAGS) -c save.cpp

createprofile.o: createprofile.cpp createprofile.h characterinfo.h load.h Battle.h
	g++ $(FLAGS) -c createprofile.cpp

monstercreation.o: monstercreation.cpp monstercreation.h characterinfo.h
	g++ $(FLAGS) -c monstercreation.cpp

battle.o: Battle.cpp Battle.h characterinfo.h
	g++ $(FLAGS) -c Battle.cpp

main.o: main.cpp createprofile.h characterinfo.h MonsterCreation.h save.h Battle.h item.h
	g++ $(FLAGS) -c main.cpp

main: main.o battle.o monstercreation.o createprofile.o save.o load.o item.o
	g++ $(FLAGS) item.o load.o save.o createprofile.o monstercreation.o battle.o main.o -o main

clean:
	rm -f main main.o battle.o monstercreation.o createprofile.o save.o load.o item.o

.PHONY: clean

