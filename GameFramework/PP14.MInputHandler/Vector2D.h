#ifndef Vector2D_h
#define Vector2D_h
#include <math.h>

class Vector2D
{
public:
    Vector2D(float x, float y) : x(x), y(y) {}
    float GetX() { return this->x; }
    float GetY() { return this->y; }
    float SetX(float x) { return this->x = x; }
    float SetY(float y) { return this->y = y; }
    float Length() { return sqrt(this->x * this->x + this->y * this->y); }
    void Normalize()
    {
        float l = Length();
        if (l > 0)
        {
            (*this) *= 1 / l;
        }
    }

    Vector2D operator+(const Vector2D& v2)
    {
        return Vector2D(this->x + v2.x, this->y + v2.y);
    }
    friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
    {
        v1.x += v2.x;
        v1.y += v2.y;
        return v1;
    }
    Vector2D operator*(float scalar)
    {
        return Vector2D(this->x * scalar, this->y * scalar);
    }
    Vector2D& operator*=(float scalar)
    {
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }

    Vector2D operator-(const Vector2D& v2)
    {
        return Vector2D(this->x - v2.x, this->y - v2.y);
    }
    friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
    {
        v1.x -= v2.x;
        v1.y -= v2.y;
        return v1;
    }
    Vector2D operator/(float scalar)
    {
        return Vector2D(this->x / scalar, this->y / scalar);
    }
    Vector2D& operator/=(float scalar)
    {
        this->x /= scalar;
        this->y /= scalar;
        return *this;
    }

private:
    float x;
    float y;
};

#endif