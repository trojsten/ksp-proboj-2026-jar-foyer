#pragma once

#include <iostream>
#include <vector>

#include "glaze/glaze.hpp"

struct Point {
	int x, y;
    Point(int x,int y) : x(x), y(y){}
    Point() = default;
    long long dist2() const;
    friend Point operator+(const Point &, const Point&);
    friend Point operator-(const Point &, const Point&);
    auto operator<=>(const Point&) const = default;
    friend std::ostream& operator<<(std::ostream &, const Point&);

};

template <>
struct glz::meta<Point> {
    using T = Point;
    static constexpr auto value = glz::object(
        &T::x,
        &T::y
    );
};

// @brief: Calculate all points, that are inside the circle with center in 'center' and radius2 'r'.
// @param: center - center of the circle
// @param: r - radius of the circle squared
// @return: vector of points that are inside the circle
std::vector<Point> points_in_circle(Point, int);
