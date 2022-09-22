#include <iostream>
#include <conio.h>


int main()
{
    float x_coord,
        y_coord,
        large_a,
        little_a;
    std::cin>>large_a>>little_a>>x_coord>>y_coord;
    if(!( ( (x_coord>0)&&(x_coord<little_a)&&(y_coord<0)&&(y_coord>-1*little_a) )||( (x_coord>-1*little_a)&&(x_coord<0)&&(y_coord>0)&&(y_coord<little_a) ) ) &&((x_coord>=-1/2*large_a)&&(x_coord<=large_a/2)&&(y_coord>=-1/2*large_a)&&(y_coord<=large_a/2)))
    {
        std::cout<<"yes";
        
    }
    else{
        std::cout<<"no";
    }
    getch();

    return 0;
}