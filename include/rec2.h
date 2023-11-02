//
// Created by Aardhyn Lavender on 2/11/23.
//

#ifndef SDL3_TEMPLATE_PROJECT_REC2_H
#define SDL3_TEMPLATE_PROJECT_REC2_H

#include <vec2.h>
#include <concept.h>

template<NumericPrimitive T>
struct Rec2 final {
    Vec2<T> position;
    Vec2<T> size;

    Rec2(Vec2<T> position, Vec2<T> size) : position{position}, size{size} {}

    Rec2(Vec2<T> size) : position{Vec2<T>(0, 0)}, size{size} {}

    inline bool operator==(const Rec2<T> &other) const { return position == other.position && size == other.size; }

    inline bool operator!=(const Rec2<T> &other) const { return !(*this == other); }

    inline bool contains(Vec2<T> point) const { return point < position + size && point > position; }

    inline friend std::ostream &operator<<(std::ostream &os, const Rec2<T> &rec) {
        os << "{ " << rec.position << " , " << rec.size << " }";
        return os;
    }

    inline operator SDL_Rect() const {
        return SDL_Rect{(int) position.x, (int) position.y, (int) size.x, (int) size.y};
    }

    inline operator SDL_FRect() const {
        return SDL_FRect{(float) position.x, (float) position.y, (float) size.x, (float) size.y};
    }
};

#endif //SDL3_TEMPLATE_PROJECT_REC2_H
