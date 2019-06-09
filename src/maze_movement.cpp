#include <iostream>
#include <fstream>

#include <boost/spirit/include/qi.hpp>
#include <boost/bind.hpp>

#include <maze_movement.hpp>

IntegerMaze2D::PointsParser::PointsParser(std::unordered_set<IntegerPoint2D, IntegerPoint2D::Hash>& maze_ref)
    : _processed_coord(1), _maze_ref(maze_ref) {}

void IntegerMaze2D::PointsParser::add_val(const int& val) {
    switch (_processed_coord) {
        
        // Если первая координата
        // то запомнить и перейти ко второй
        case 1:
            _x = val;
            _processed_coord = 2;

            break;

        // Если вторая координата
        // то запомнить и вставить точку в лабиринт
        // и перейти снова к первой координате
        case 2:
            _y = val;
            _maze_ref.insert({_x, _y});
            _processed_coord = 1;
            
            break;
    }
}

IntegerMaze2D::IntegerMaze2D(){}

IntegerMaze2D::IntegerMaze2D(const std::string& path) {
    std::ifstream in_file(path, std::ios::in);

    if (in_file.is_open()) {
        using boost::spirit::qi::int_;
        using boost::spirit::qi::phrase_parse;
        using boost::spirit::ascii::space;
        
        using istream_spirit_it = boost::spirit::istream_iterator;

        // итераторы для парсинга потока
        istream_spirit_it fbegin(in_file), fend;

        // объект парсер
        // заполняет лабиринт
        IntegerMaze2D::PointsParser points_parser(_maze);

        bool result = phrase_parse(fbegin, fend, 
        (
            '(' // в начале скобка
            >> int_[
                    boost::bind(&IntegerMaze2D::PointsParser::add_val, 
                    &points_parser, _1)
                ] // потом число (абсцисса)
            >> ',' // потом запятая
            >> int_[
                    boost::bind(&IntegerMaze2D::PointsParser::add_val, 
                    &points_parser, _1)
                ]  // потом ещё число (ордината)
            >> ')' // в конце скобка
        ) % ',', 
        space);

        if (!result) {
            std::cout << "unable parse board" << std::endl;
        }
    }
    else {
        std::cout << "can't open file" << " " << path << std::endl;
    }

    in_file.close();
}

std::size_t IntegerMaze2D::size() const {
    return _maze.size();
}

bool IntegerMaze2D::have_neighbour(const IntegerPoint2D& point, const MOVEMENT& movement) const {
    // если в результате движения
    // координаты не поменялись
    // значит смежной точки нет
    return navigate(point, movement, false) == point ? false : true;
}

bool IntegerMaze2D::add_point(const IntegerPoint2D& point) {
    auto result = _maze.insert(point);
    return result.second;
}

bool IntegerMaze2D::remove_point(const IntegerPoint2D& point) {
    return _maze.erase(point) ? true : false;
}

IntegerPoint2D IntegerMaze2D::navigate(const IntegerPoint2D& from, const MOVEMENT& movement, bool log) const {
    if (log) {
        std::cout << "Navigating from" << " " << from << " " << movement;
    }

    auto [new_x, new_y] = from.get();
    
    switch (movement) {
        case MOVEMENT::UP:
            new_y++;
            break;
        case MOVEMENT::DOWN:
            new_y--;
            break;
        case MOVEMENT::RIGHT:
            new_x++;
            break;
        case MOVEMENT::LEFT:
            new_x--;
            break;
    }

    // точка, которая должна быть
    // получена в результате движения
    IntegerPoint2D new_point(new_x, new_y);

    // если такой точки нет в лабиринте
    // то новая точка = начальная
    if (_maze.find(new_point) == _maze.end()) {
        new_point = from;
    }

    if (log) {
        std::cout << " -> " << new_point << std::endl;
    }

    return new_point;
}

IntegerPoint2D IntegerMaze2D::navigate(const IntegerPoint2D& from, const std::list<MOVEMENT>& movements, bool log) const {
    if (log) {
        std::cout << "start" << " " << from << std::endl;
        std::cout << "route" << " ";
        for (const auto& movement : movements) {
            std::cout << movement << " ";
        }
        std::cout << std::endl;
    }

    auto current = from;
    std::size_t step = 1;
    for (const auto& movement : movements) {
        if (log) {
            std::cout << "step" << " " << step << " ";
        }
        current = navigate(current, movement, log);
        step++;
    }

    return current;
}

std::ostream& operator<<(std::ostream& out, const IntegerMaze2D& maze) {
    out << "Maze size:" << " " << maze.size() << std::endl;
    out << "Points in maze:" << " ";
    for (const auto& point : maze._maze) {
        out << point << " ";
    }
    
    return out;
}

std::ostream& operator<<(std::ostream& out, const IntegerMaze2D::MOVEMENT& movement) {
    switch (movement) {
        case IntegerMaze2D::MOVEMENT::UP:
            out << "UP";
            break;
        case IntegerMaze2D::MOVEMENT::DOWN:
            out << "DOWN";
            break;
        case IntegerMaze2D::MOVEMENT::LEFT:
            out << "LEFT";
            break;
        case IntegerMaze2D::MOVEMENT::RIGHT:
            out << "RIGHT";
            break;
    }

    return out;
}