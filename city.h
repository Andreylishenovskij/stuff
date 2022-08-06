#ifndef __CITY_H
#define __CITY_H
#include "road.h"
#include <vector>
class city
    {
        public:
            city(int i);
            ~city();
            int get_name();
            void add_road(road *Road);
            std::vector <road*> get_roads();
        protected:
            std::vector <road*> roads;
            int name;
    };
#endif