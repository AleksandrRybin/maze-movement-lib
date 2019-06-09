/*!
    * @file
    * @brief Демо программа
    * 
    * @detailed Программа для демонстрации
    * работы библиотеки для навигации по лабиринту.
    * 
    * Программа принимает на вход лабиринт, маршрут 
    * и координаты начальной точки.
    * 
    * Аргументы программы:
    * 
    * --board путь до файла с лабиринтом (!обязательный аргумент)
    * 
    * --route маршрут строка вида "ulrlrldduu" где
    *     u - вверх
    *     d - вниз
    *     r - направо
    *     l - влево
    * !обязательный аргумент
    * 
    * start_x, -x абсцисса начальной точки
    * 
    * start_y, -y ордината начальной точки
    * 
    * --log включает логгирование движения в консоль
 */

#include <algorithm>

#include <boost/program_options.hpp>

#include <maze_movement.hpp>

int main(int argc, char const *argv[])
{
    namespace po = boost::program_options;

    std::string board_path;
    std::string route;
    int start_x;
    int start_y;
    bool log;
    
    // описание опций командной строки
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("board", po::value<std::string>(&board_path), "path to file with board")
        ("route", po::value<std::string>(&route), "route to navigate")
        ("start_x,x", po::value<int>(&start_x)->default_value(0), "x coordinate for start point")
        ("start_y,y", po::value<int>(&start_y)->default_value(0), "y coordinate for start point")
        ("log", po::value<bool>(&log)->default_value(false), "need log navigating through maze")
    ;
    
    // словарь опций
    po::variables_map vm;

    // сохранение полученных значений
    po::store(po::parse_command_line(argc, argv, desc), vm);

    // парсинг
    po::notify(vm);
    
    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return 0;
    }

    if (!vm.count("board")) {
        std::cout << "no board file given" << std::endl;
        return -1;
    }

    if (!vm.count("route")) {
        std::cout << "no route given" << std::endl;
        return -1;
    }

    IntegerMaze2D maze(board_path);
    
    std::list<IntegerMaze2D::MOVEMENT> movements;

    // преобразование входной строки
    // в список элементарных движений
    // для вызова метода навигации по лабиринту
    std::for_each(route.begin(), route.end(), [&movements](const auto movement) {
        switch (movement) {
            case 'u':
                movements.push_back(IntegerMaze2D::MOVEMENT::UP);
                break;
            case 'd':
                movements.push_back(IntegerMaze2D::MOVEMENT::DOWN);
                break;
            case 'l':
                movements.push_back(IntegerMaze2D::MOVEMENT::LEFT);
                break;
            case 'r':
                movements.push_back(IntegerMaze2D::MOVEMENT::RIGHT);
                break;
            default:
                break;
        }
    });

    IntegerPoint2D start_point = {start_x, start_y};

    // движение по лабиринту
    auto result = maze.navigate(start_point, movements, log);

    std::cout << "result" << " " << result << std::endl;

    return 0;
}