#include "city.h"
            city::city(int i)
            {
                name = i;
            }
            city::~city()
            {
                for(road *r :roads)
                {
                    delete r;
                }
            }
            int city::get_name()
            {
                return name;
            }
            void city::add_road(road *Road)
            {
                roads.push_back(Road);
            }
            std::vector <road*> city::get_roads()
            {
                return roads;
            }


