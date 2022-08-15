#include "road.h"
#define q 0.2 // feromone evaporation coefficient
#define FEROMONE_DEFAULT 0.200
            road::road(city* x, city * y,int z)
            {
                from = x;
                to = y;
                length = z;
                feromone = FEROMONE_DEFAULT;
    
            }
            city *road::get_from()
            {
                return from;
            }
            city *road::get_to()
            {
                return to;
            }
            unsigned road::get_length()
            {
                return length;
            }
            float road::get_feromone()
            {
                return feromone;
            }
            void road::add_feromone(float fer)
            {
                feromone+=fer;
                feromone = feromone * (1-q);
            }
