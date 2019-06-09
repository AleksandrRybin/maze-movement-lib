#include <boost/functional/hash.hpp>

#include <point.hpp>

IntegerPoint2D::IntegerPoint2D()
    : _x(0), _y(0) {}

IntegerPoint2D::IntegerPoint2D(const int& x, const int& y)
    : _x(x), _y(y) {}

int IntegerPoint2D::get_x() const {
    return _x;
}

int IntegerPoint2D::get_y() const {
    return _y;
}

std::pair<int, int> IntegerPoint2D::get() const {
    return std::make_pair(_x, _y);
}

void IntegerPoint2D::set_x(const int& new_x) {
    _x = new_x;
}

void IntegerPoint2D::set_y(const int& new_y) {
    _y = new_y;
}

void IntegerPoint2D::set(const int& new_x, const int& new_y) {
    _x = new_x;
    _y = new_y;
}

bool operator==(const IntegerPoint2D& lhs, const IntegerPoint2D& rhs) {
    return lhs.get_x() == rhs.get_x() && lhs.get_y() == rhs.get_y(); 
}

std::ostream& operator<<(std::ostream& out, const IntegerPoint2D& point) {
    out << "(" << point.get_x() << "," << point.get_y() << ")";
    return out;
}

std::size_t IntegerPoint2D::Hash::operator()(const IntegerPoint2D& point) const {
    std::size_t seed = 0;
    boost::hash_combine(seed, point.get_x());
    boost::hash_combine(seed, point.get_y());

    return seed;
}