//
// Created by x12w on 25-9-9.
//

#ifndef BOX_H
#define BOX_H
#include <vector>
#include <unordered_set>
namespace BOX {
    enum direction { UP, RIGHT , DOWN, LEFT };
    class Struct;
    class coordinate_system;
    /*the basic unit*/
    class Point {
        private:
        int x,y;//the location of point
        Struct *main_struct;//point to the struct that the point belonged to
        coordinate_system *belonged_system;//point to the coordinate system that the point belonged to
        bool movable[4];//whether the point can move to that direction
        bool get_movable(direction dir);
        public:
        Struct *get_Struct()const;//get the struct that the point belonged to
        coordinate_system *get_belonged_system()const;
        const int &get_x()const;//get the x location
        const int &get_y()const;//get the y location
        bool move(direction dir);//try to move the point to the gave direction
        void refresh();//refresh the movable situation of the point
        /*the constructor methods*/
        Point(const int &_x, const int &_y);
        Point();

    };
    /*the struct that made of the points*/
    class Struct {
        private:
        std::vector<Point*> points;//the points that the struct include
        std::unordered_set<Struct*> immediately_adjacent_structure[4];
        std::unordered_set<Struct*> moved_structure[4];
        std::unordered_set<Point*> immediately_adjacent_empty_point[4];
        bool movable[4];//whether the struct could move
        static int number;//the total number of structs
        void get_immediately_adjacent_structure(direction dir)const;//get the structs next to this struct in one direction
        void get_moved_structure(direction dir)const;//get the structs need to move when this struct need to move in one direction
        void get_immediately_adjacent_point(direction dir)const;
        bool get_movable(direction dir)const;//get the movable in one direction
        public:
        void add_point(Struct *point);
        void subtract_point(Struct *point);
        bool move(enum direction dir);//try to move the struct and return the result
        void refresh();//refresh the movable of the struct
        std::vector<Point*> get_points();//get the points belong to the struct
        const int &get_number();//get the number of the structs
        /*the constructor methods*/
        explicit Struct(std::vector<Point*> _points);
        Struct();
    };
    /*monitor the points*/
    class coordinate_system {
        private:
        int origin_x,origin_y;
        std::vector<std::vector<Point*>> x,y;//point to the points located on the x/y value
        public:
        bool isEmpty(const int &_x, const int &_y);//whether the gave location is empty
        //void x_extend(const int &_x, const int &_y);
        bool extend(const int &value , enum direction dir);//extend the coordinate system and return the result
        /*the constructor methods*/
        coordinate_system(const int &_x, const int &_y);
        coordinate_system();
    };
    class signal {
        private:
        std::unordered_set<Struct*> set;
        Struct *current;
        public:

    };

}

#endif //BOX_H
