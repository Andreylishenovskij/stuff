#include <iostream>
#include <vector>
#include <iomanip>
#include "ant.h"
#define NUMBER_OF_CITIES 20
#define MAX_ROAD_LENGTH 100
#define ITERATIONS 100000

int main()
{
    std::vector <city*> cities;
    for(int i = 0 ; i < NUMBER_OF_CITIES; i++)
    {
        city *City;
        City = new city(i);
        for( city* ciity: cities)
        {
            int length = rand()%MAX_ROAD_LENGTH;
            road *Road_1;
            Road_1 = new road(ciity,City,length);
            ciity->add_road(Road_1);
            road *Road_2;
            Road_2 = new road(City,ciity,length);
            City->add_road(Road_2);
        }
        cities.push_back(City);
    }
    std::vector <ant*> ants;
    int min_distance = 1000000;
    int iterations = 0;
    while(iterations < ITERATIONS)
    {
        for(int i = 0; i < NUMBER_OF_CITIES ;i++)
        {
            ant *Ant;
            Ant = new ant(cities[i]);
            ants.push_back(Ant);
            ants[i]->ant_move();
            
        }
        for( ant *a :ants)
        {
            if( a->get_distance() < min_distance)
            {
                min_distance = a->get_distance();
               std::cout<<"New shortest path = "<<min_distance<<" way = ";
                for(int i = 0 ;i < cities.size();i++)
                {
                    std::cout<<a->return_city(i)->get_name()<<' ';
                }
                std::cout<<std::endl;
            }
        }
        for(int i = 0;i < 10;i++)
        {
            delete ants[i];
        }
        ants.clear();
        iterations++;
    }
    for(city *ciity: cities)
    {
        delete ciity;
    }
    return 0;
}






