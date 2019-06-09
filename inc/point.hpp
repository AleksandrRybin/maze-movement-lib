/*!
    * @file 
    * @brief Заголовочный файл для класса IntegerPoint2D.
    * 
    * @detailed Данный файл содержит объявление класса IntegerPoint2D
    * и вспомогательного класса IntegerPoint2D::Hash.
 */

#pragma once

#include <iostream>
#include <utility>

/*!
    * @brief Двумерная точка в целочисленных координатах.
*/
class IntegerPoint2D {
public:
    
    IntegerPoint2D();
    IntegerPoint2D(const int& x, const int& y);

    int get_x() const;
    int get_y() const;
    std::pair<int, int> get() const;

    void set_x(const int& new_x);
    void set_y(const int& new_y);
    void set(const int& new_x, const int& new_y);

    /*!
        @brief Класс для хэширования объектов типа IntegerPoint2D.

        @detailed Для хэширования используется std::hash для каждой координаты,
        а для коомбинации хэшей boost::hash_combine.
     */
    class Hash {
    public:
        std::size_t operator()(const IntegerPoint2D& point) const;
    };

private:

    int _x; //< абсцисса точки
    int _y; //< ордината точки
};

bool operator==(const IntegerPoint2D& lhs, const IntegerPoint2D& rhs);

std::ostream& operator<<(std::ostream& out, const IntegerPoint2D& point);