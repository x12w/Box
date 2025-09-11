//
// Created by x12w on 25-9-9.
//
#include <iostream>
#include <vector>
#include "Box.h"

namespace BOX {
    Struct &Point::get_Struct() const {
        return *main_struct;
    }
    const int &Point::get_x() const {
        return x;
    }
    const int &Point::get_y() const {
        return y;
    }
    bool Point::move(direction dir) {
        switch (dir) {
            case UP:
                y += 1;
                break;
            case DOWN:
                y -= 1;
                break;
            case LEFT:
                x -= 1;
                break;
            case RIGHT:
                x += 1;
                break;
        }
        return false;
    }
    void Point::refresh() {
        for (int i = 0; i < 4; i++) {
            movable[i] = get_movable(static_cast<direction>(i));
        }
    }
    bool Point::get_movable(direction dir) {

    }





}