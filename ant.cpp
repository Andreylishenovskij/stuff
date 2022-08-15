#include "ant.h"
#include <math.h>
#define Q 1.000 // stands for feromone added to a road after it's walked through
#define ALPHA 1.000 // stands for correlation between distance between cities and chance of going from one to another
#define BETA 1.000 // stands for correlation between feromone between cities and chance of going from one to another
ant::ant(city *City)
{
    current = City;
    start_city = current;
}
ant::~ant()
{
    for( road *r : roads_visited)
    {
        r->add_feromone(Q/roads_visited.size());
    }
                
}
city *ant::return_city(int i)
{
    return cities_visited[i];
}
void ant::ant_move()
{
    while(true)
    {
        add_visit();
        std::vector <road*> where_to_go;
        for( road* r : current->get_roads())
        {
            bool was = false;
            for(city * c: cities_visited)
            {
                if(c == r->get_to())
                {
                    was = true;
                }
            }
            if(!was)
            {
                where_to_go.push_back(r);
            }
        }
                    if(where_to_go.empty())
                    {
                        for(road *r: current->get_roads() )
                        {
                            if(r->get_to() == start_city)
                            {
                                distance+=r->get_length();
                                roads_visited.push_back(r);
                            }
                        }
                        return;
                    }
                    float array[where_to_go.size()+1];
                    array[where_to_go.size()] = 1;
                    float sum_of_probs = 0;
                    for(int i = 0;i<where_to_go.size();i++)
                    {
                       sum_of_probs+=pow(1/(where_to_go[i]->get_length()*1.0),ALPHA)*pow(where_to_go[i]->get_feromone(),BETA);
                       array[i] = pow(1/(where_to_go[i]->get_length()*1.0),ALPHA)*pow(where_to_go[i]->get_feromone(),BETA);
                    }
                    array[0] = 0;
                    for(int i = 1;i<where_to_go.size();i++)
                    {
                        array[i] = array[i-1] + array[i]/sum_of_probs;
                    }
                    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                    for(int i = 0; i < where_to_go.size();i++)
                    {
                        if(r <= array[i+1] )
                        {   roads_visited.push_back(where_to_go[i]);
                            current = where_to_go[i]->get_to();
                            distance+=where_to_go[i]->get_length();
                            break;
                        }
                    }
                }
            }
    
void ant::add_visit()
{
    this->cities_visited.push_back(current);
}
unsigned ant::get_distance()
{
    return distance;
}
void ant::print_route()
{
    for(road *r:roads_visited)
    {
        std::cout<<r->get_length()<<' ';
    }
    std::cout<<std::endl;
}

