//
// Created by alvar on 18/04/2023.
//
#include "shapes.h"
#include <stdlib.h>
#include <stdio.h>


Point *create_point(int px, int py){
    Point *p;
    p = (Point*)malloc(sizeof(Point));
    p->pos_x = px;
    p->pos_y = py;
    return p;
}

void delete_point(Point * point){
    free(point);
}

void print_point(Point * p){
    printf("POINT %d %d\n",p->pos_x,p->pos_y);
}

Line *create_line(Point * p1, Point * p2){
    Line *l;
    l = (Line*)malloc(sizeof(Line));
    l->p1 = p1;
    l->p2 = p2;
    return l;
}

void delete_line(Line * line){
    free(line->p1);
    free(line->p2);
    free(line);
}

void print_line(Line * line){
    printf("LINE %d %d %d %d\n",line->p1->pos_x,line->p1->pos_y,line->p2->pos_x,line->p2->pos_y);
}

Square *create_square(Point *point, int length){
    Square *sq;
    sq = (Square*)malloc(sizeof(Square));
    sq->top_left = point;
    sq->length = length;
    return sq;
}

void delete_square(Square *square){
    free(square->top_left);
    free(square);
}

void print_square(Square *square){
    printf("SQUARE:\nTop left corner: %d %d\n Length: %d\n",square->top_left->pos_x,square->top_left->pos_y,square->length);
}

Rectangle *create_rectangle(Point * point, int width, int height){
    Rectangle *rtg;
    rtg=(Rectangle*)malloc(sizeof(Rectangle));
    rtg->top_left= point;
    rtg->length = height;
    rtg->width = width;
    return rtg;
}

void delete_rectangle(Rectangle * rectangle) {
    free(rectangle->top_left);
    free(rectangle);
}

void print_rectangle(Rectangle * rectangle){
    printf("RECTANGLE:\nTop left corner: %d %d\n Length: %d\n Width: %d\n",rectangle->top_left->pos_x,rectangle->top_left->pos_y,rectangle->length,rectangle->width);
}

Circle *create_circle(Point * center, int radius){
    Circle *c;
    c=(Circle*)malloc(sizeof(Circle));
    c->center= center;
    c->radius= radius;
    return c;
}

void delete_circle(Circle * circle){
    free(circle->center);
    circle->center= NULL;
    free(circle);
    circle= NULL;
}

void print_circle(Circle * circle){
    printf("CIRCLE:\nCenter: %d %d \n Radius: %d", circle->center->pos_x,circle->center->pos_y,circle->radius);
}

Polygon *create_polygon(int n,int lst[]){
    Polygon *polygon = (Polygon *) malloc(sizeof(Polygon));
    polygon->n = n;
    Point * point;
    polygon->points = (Point **) malloc(n * sizeof(Point *));
    for (int i = 0; i < 2*n; i++) {
        point = create_point(lst[i], lst[i+1]);
        polygon->points[i]= point;
        i+=2;
    }
    return polygon;
}


void delete_polygon(Polygon * polygon){
    for (int i = 0; i < polygon->n; i++) {
        delete_point(polygon->points[i]);
    }
    free(polygon->points);
    free(polygon);
}

void print_polygon(Polygon * polygon) {
    printf("POLYGON:\n Number of vertices: %d\n Coordinates of vertices:\n", polygon->n);
    for (int i = 0; i < polygon->n; i++) {
        printf("(%d, %d)\n", polygon->points[i]->pos_x, polygon->points[i]->pos_y);
    }
}


Shape *create_empty_shape(SHAPE_TYPE shape_type)
{
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = 1; // plus tard on appelera get_next_id();
    shp->shape_type = shape_type;
    return shp;
}

Shape *create_point_shape(int px, int py)
{
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}

Shape *create_line_shape(int px1, int py1, int px2, int py2){
    Shape *shp = create_empty_shape(LINE);
    Line *l= create_line(create_point(px1, py1),create_point(px2, py2));
    shp->ptrShape= l;
    return shp;
}

Shape *create_square_shape(int px, int py, int length){
    Shape *shp = create_empty_shape(SQUARE);
    Square *sq= create_square(create_point(px, py),length);
    shp->ptrShape= sq;
    return shp;
}

Shape *create_rectangle_shape(int px, int py, int width, int height){
    Shape *shp = create_empty_shape(RECTANGLE);
    Rectangle *rtg= create_rectangle(create_point(px, py),width, height);
    shp->ptrShape= rtg;
    return shp;
}

Shape *create_circle_shape(int px, int py, int radius){
    Shape *shp = create_empty_shape(CIRCLE);
    Circle *c= create_circle(create_point(px, py),radius);
    shp->ptrShape= c;
    return shp;
}

Shape *create_polygon_shape(int lst[], int n){
    Shape *shp = create_empty_shape(POLYGON);
    Polygon *poly= create_polygon(n, lst);
    shp->ptrShape= poly;
    return shp;
}

void delete_shape(Shape * shape){
    if (shape->shape_type == POINT)
    {
        delete_point(shape->ptrShape);
    }
    if (shape->shape_type == LINE)
    {
        delete_line(shape->ptrShape);
    }
    if (shape->shape_type == SQUARE)
    {
        delete_square(shape->ptrShape);
    }
    if (shape->shape_type == RECTANGLE)
    {
        delete_rectangle(shape->ptrShape);
    }
    if (shape->shape_type == CIRCLE)
    {
        delete_circle(shape->ptrShape);
    }
    if (shape->shape_type == POLYGON)
    {
        delete_polygon(shape->ptrShape);
    }
}

void print_shape(Shape * shape){
    if (shape->shape_type == POINT)
    {
        print_point(shape->ptrShape);
    }
    if (shape->shape_type == LINE)
    {
        print_line(shape->ptrShape);
    }
    if (shape->shape_type == SQUARE)
    {
        print_square(shape->ptrShape);
    }
    if (shape->shape_type == RECTANGLE)
    {
        print_rectangle(shape->ptrShape);
    }
    if (shape->shape_type == CIRCLE)
    {
        print_circle(shape->ptrShape);
    }
    if (shape->shape_type == POLYGON)
    {
        print_polygon(shape->ptrShape);
    }
}
