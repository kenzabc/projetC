#include <stdio.h>
#include "shapes.h"


int main() {
    //test point
    /*
    Point *p = create_point(10,15);
    print_point(&p);
    delete_point(&p);
    */

    //test line
    /*
    Point * p1 = create_point (10, 15);
    Point * p2 = create_point (21, 25);
    Line * l = create_line (p1 ,p2);
    print_line (&l);
    delete_line(&l);
    delete_point(&p1);
    delete_point(&p2);
    */
    int L[]={1,2,3,4,5,6,7,8,9,10};
    print_polygon(create_polygon(5,L));
    return 0;
}
