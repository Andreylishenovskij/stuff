#ifndef __ROAD_H
#define __ROAD_H
class city;
    class road
    {
        public:
            road(city* x, city * y,int z);
            city *get_from();
            city *get_to();
            unsigned  get_length();
            float get_feromone();
            void add_feromone(float fer);
        protected:
            city *from;
            city *to;
            unsigned length;
            float feromone;
    };
#endif