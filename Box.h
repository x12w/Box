//
// Created by x12w on 25-9-9.
//

#ifndef BOX_H
#define BOX_H
#include <vector>
namespace BOX {
    enum direction { UP, RIGHT , DOWN, LEFT };
    class Struct;
    class coordinate_system;
    /*the basic unit*/
    class Point {
        private:
        int x,y;//the location of point
        Struct *main_struct;//point to the struct that the point belonged to
        coordinate_system *belonged_system;//point to the coordinate system that the point belond to
        bool movable[4];//whether the point can move to that direction
        public:
        Struct &get_Struct()const;//get the struct that the point belonged to
        const int &get_x()const;//get the x location
        const int &get_y()const;//get the y location
        bool move(direction dir);//try to move the point to the gived direction
        void refresh();//refresh the movable situation of the point
        /*the constructor methods*/
        Point(const int &_x, const int &_y);
        Point();

    };
    /*the struct that made of the points*/
    class Struct {
        private:
        std::vector<Point*> points;//the points that the struct include
        bool movable[4];//whether the struct could move
        static int number;//the total number of structs
        public:
        bool move(enum direction dir);//try to move the struct and return the result
        void refresh();//refresh the movable of the struct
        std::vector<Point*> get_points();//get the points belong to the struct
        const int &get_number();//get the number of the structs
        /*the constructor methods*/
        explicit Struct(std::vector<Point*> _points);
        Struct();
    };
    /*moniter the points*/
    class coordinate_system {
        private:
        int origin_x,origin_y;
        std::vector<std::vector<Point*>> x,y;//point to the points located on the x/y value
        public:
        bool isempty(const int &_x, const int &_y);//whether the gived location is empty
        //void x_extend(const int &_x, const int &_y);
        bool extend(const int &value , enum direction dir);//extend the coordinate system and return the result
        /*the constructor methods*/
        coordinate_system(const int &_x, const int &_y);
        coordinate_system();

    };

}

#endif //BOX_H
