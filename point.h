#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <functional>
#include <cstdint>

struct Point {
    int x;
    int y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

namespace std {
    template<>
    struct hash<Point> {
        size_t operator()(const Point& p) const {
            uint32_t x = static_cast<uint32_t>(p.x);
            uint32_t y = static_cast<uint32_t>(p.y);
    
            return (static_cast<size_t>(x) << 32) | y;
        }
    };
}

#endif