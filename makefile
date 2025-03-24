exe:mainn.o membre.o ressource.o tache.o budget_statistic.o clubs_records.o
	gcc -o exe mainn.o membre.o ressource.o tache.o budget_statistic.o clubs_records.o
mainn.o:membre.h membre.h ressource.h tache.h
	gcc -c mainn.c membre.c ressource.c tache.c budget_statistic.c clubs_records.c
membre.o: membre.h  tache.h
	gcc -c membre.c tache.c
tache.o:tache.h 
	gcc -c tache.c
ressource.o: ressource.h
	gcc -c ressource.c

budget_statistic.o: ressource.h membre.h  tache.h 
	gcc -c budget_statistic.c membre.c tache.c
clubs_records.o: membre.h
	gcc -c clubs_records.c membre.c

clean:
	rm -f *.o
