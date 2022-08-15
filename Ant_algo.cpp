#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include "ant.h"
#define NUMBER_OF_CITIES 52
#define MAX_ROAD_LENGTH 100
#define ITERATIONS 5000 //number of iterations left after new route discovered(refreshes after new shortest route discovered), prevents infinite loop

int main()
{
    std::vector <city*> cities;
    for(int i = 0 ; i < NUMBER_OF_CITIES; i++)//creates cities
    {
        city *City;
        try
        {
            City = new city(i);
        }
        catch (const std::bad_alloc &e)
        {
		    std::cout << "Allocation failed: " << e.what() <<std::endl<<"Abort"<<std::endl;
		    for( city *c :cities)
		    {
		        delete c;
		    }
		    std::abort();
        }
        for( city* ciity : cities)//adds 2-way road between cities
        {
            try
            {
                unsigned length = rand()%MAX_ROAD_LENGTH;
                road *Road_1;
                Road_1 = new road(ciity,City,length);
                ciity->add_road(Road_1);
                road *Road_2;
                Road_2 = new road(City,ciity,length);
                City->add_road(Road_2);
            }
            catch (const std::bad_alloc &e)
            {
		        std::cout << "Allocation failed: " << e.what()<<std::endl<<"Abort"<<std::endl;
		        for( city *c :cities)
		        {
		            delete c;
		        }
    		    std::abort();
            }
        }
        cities.push_back(City);
    }
    std::vector <ant*> ants;
    int min_distance = std::numeric_limits<unsigned>::max();
    unsigned iterations = 0; 
    while(iterations < ITERATIONS)
    {
        for(int i = 0; i < NUMBER_OF_CITIES ; i++)//for each iteration an ant is created for each city
        {
            try
            {
                ant *Ant;
                Ant = new ant(cities[i]);
                ants.push_back(Ant);
                ants[i]->ant_move();
            }
            catch (const std::bad_alloc &e)
            {
		        std::cout << "Allocation failed: " << e.what() <<std::endl<<"Abort"<<std::endl;
		        for( city *c :cities)
		        {
		            delete c;
		        }
		    std::abort();
            }
        }
        for( ant *a :ants)//checks if any ant discovered a short path,then shows and saves it
        {
            unsigned total = a->get_distance();
            if(total < min_distance)
            {
                iterations = 0;
                min_distance = total;
                std::cout<<"New shortest path = "<<min_distance<<" way = ";
                for(int i = 0 ; i < NUMBER_OF_CITIES ; i++)
                {
                    std::cout<<a->return_city(i)->get_name()<<' ';
                }
                std::cout<<std::endl;
            }
        }
        for(ant *a : ants)//deleting ants before each new iteration
        {
            delete a;
        }
        ants.clear();
        iterations++;
    }
    for(city *ciity: cities)//deleting cities and roads
    {
        delete ciity;
    }
    return 0;
}






