#ifndef __ANT_H
#define __ANT_H
#include "road.h"
#include "city.h"
class ant
    {
        public:
            ant(city *City);
            ~ant();
            city *return_city(int i);
            void ant_move();
            void add_visit();
            int get_distance();
        protected:
            city *start_city;
            int distance = 0;
            city *current;
            std::vector <road*> roads_visited;
            std::vector <city*> cities_visited;
    };
#endif