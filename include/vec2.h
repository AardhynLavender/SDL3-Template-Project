//
// Created by Aardhyn Lavender on 1/11/23.
//

#ifndef SDL3_TEMPLATE_PROJECT_VEC2_H
#define SDL3_TEMPLATE_PROJECT_VEC2_H

#include <concept.h>
#include <iostream>

template<NumericPrimitive T = double>
struct Vec2 {
    inline static constexpr T ORIGIN = 0.0;

    T x, y;

    Vec2(T x, T y) : x{x}, y{y} {}

    Vec2(T scalar) : x{scalar}, y{scalar} {}

    Vec2() : x{ORIGIN}, y{ORIGIN} {}

    inline Vec2<T> operator+(const Vec2<T> &other) const { return Vec2<T>(x + other.x, y + other.y); }

    inline Vec2<T> operator-(const Vec2<T> &other) const { return Vec2<T>(x - other.x, y - other.y); }

    inline Vec2<T> operator*(const Vec2<T> &other) const { return Vec2<T>(x * other.x, y * other.y); }

    inline Vec2<T> operator/(const Vec2<T> &other) const { return Vec2<T>(x / other.x, y / other.y); }

    inline Vec2<T> &operator+=(const Vec2<T> &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    inline Vec2<T> &operator-=(const Vec2<T> &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    inline Vec2<T> &operator*=(const Vec2<T> &other) {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    inline Vec2<T> &operator/=(const Vec2<T> &other) {
        x /= other.x;
        y /= other.y;
        return *this;
    }

    inline Vec2<T> operator+(const T scalar) const {
        return Vec2<T>(x + scalar, y + scalar);
    }

    inline Vec2<T> operator-(const T scalar) const {
        return Vec2<T>(x - scalar, y - scalar);
    }

    inline Vec2<T> operator*(const T scalar) const {
        return Vec2<T>(x * scalar, y * scalar);
    }

    inline Vec2<T> operator/(const T scalar) const {
        return Vec2<T>(x / scalar, y / scalar);
    }

    inline bool operator==(const Vec2<T> &other) const { return x == other.x && y == other.y; }

    inline bool operator!=(const Vec2<T> &other) const { return x != other.x || y != other.y; }

    inline bool operator<(const Vec2<T> &other) const { return x < other.x && y < other.y; }

    inline bool operator>(const Vec2<T> &other) const { return x > other.x && y > other.y; }

    inline bool operator<=(const Vec2<T> &other) const { return x <= other.x && y <= other.y; }

    inline bool operator>=(const Vec2<T> &other) const { return x >= other.x && y >= other.y; }

    inline bool operator!() const { return x == ORIGIN && y == ORIGIN; }

    inline friend std::ostream &operator<<(std::ostream &os, const Vec2 &vec) {
        os << "{ x: " << vec.x << ", y: " << vec.y << " }\n";
        return os;
    }

    inline operator Vec2<int>() const { return {(int) x, (int) y}; }

    inline operator Vec2<float>() const { return {(float) x, (float) y}; }

    inline operator Vec2<double>() const { return {(double) x, (double) y}; }
};

#endif //SDL3_TEMPLATE_PROJECT_VEC2_H
