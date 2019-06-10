/*!
    * @file
    * @brief Заголовочный файл для класса *IntegerMaze2D*.
    * 
    * @detailed Данный файл содержит объявление класса *IntegerMaze2D
    * и вспомогательных класса IntegerMaze2D*::PointsParser
    * и перечисления IntegerMaze2D*::MOVEMENT.
 */

#pragma once

#include <unordered_set>
#include <string>
#include <list>

#include <point.hpp>

/*!
    * @brief Класс лабиринт.
    * 
    * @detailed Лабиринт состоит из секций,
    * которые представляются точками с двумя целочисленными координатами.
    * 
    * Класс представляет функционал навигации по лабиринту:
    * 
    * - шаг по лабиринту.
    * 
    * - движение по заданному маршруту.
    * 
    * и редактирования лабиринта:
    * 
    * - добавление секции.
    * 
    * - удалении секции.
    * 
    * Далее секция=точка.
    * 
    * Внутри лабиринт реализуется с помощью std::unordered_set (хэш таблица)
    * Таким образом добавить, удалить и найти точку в лабиринте
    * можно в большинстве случаев за О(1).
 */
class IntegerMaze2D {
public:
    
    /*!
        * @brief Направление движения в лабиринте.
     */
    enum class MOVEMENT {
        UP,      //< вверх
        DOWN,    //< вниз
        RIGHT,   //< направо
        LEFT     //< налево
    };

    IntegerMaze2D();

    /*!
        * @brief Загрузка лабиринта из файла.
        * 
        * @detailed Файл должен содержать список точек лабиринта
        * через запятую. Точка представляется двумя координатами 
        * в скобках через запятую.
        *
        * Пример: (0, 1), (1, 2), (3, 4), (-5, -15).
        * 
        * Если файл не может быть прочитан или
        * содержит неккоректные данные, то
        * лабиринт все равно создаётся, но
        * будет пустым (не содержать ни одной точки).
        * 
        * @param path путь до файла.
     */
    IntegerMaze2D(const std::string& path);

    /*!
        * @brief Создание лабиринта из списка точек
        * @param points список точек
     */
    IntegerMaze2D(const std::list<IntegerPoint2D>& points);

    /*!
        * @brief Размер лабиринта
     */
    std::size_t size() const;

    /*!
        * @brief Проверка на пустоту лабиринта
     */
    bool is_empty() const;

    /*!
        * @brief Есть ли данная точка в лабиринте.
        * @param point точка для проверки.
        * @return true если точка есть, иначе false.
     */
    bool have_point(const IntegerPoint2D& point) const;
    
    /*!
        * @brief Имеет ли точка смежную.
        * @param point точка для проверки.
        * @param movement направление для поиска.
        * @return true если точка имеет соседа в данном направление, иначе false.
     */
    bool have_neighbour(const IntegerPoint2D& point, 
    const MOVEMENT& movement) const;

    /*!
        * @brief Добавить точку в лабиринт.
        * @param point точка для добавление.
        * @return true если точка была добавлена, иначе false если точка уже есть в лабиринте.
     */
    bool add_point(const IntegerPoint2D& point);

    /*!
        * @brief Удалить точку из лабиринта.
        * @param point точка для удаления.
        * @return true если точка была удалена, иначе false если такой точки нет в лабиринте.
     */
    bool remove_point(const IntegerPoint2D& point);

    /*!
        * @brief Сделать шаг по лабиринту.
        *
        * @detailed Если в данном направлении нет смежной точки,
        * то координаты начальной точки не меняются.
        * Ошибки при этом не происходит.
        * 
        * @param from начальная точка.
        * @param movement направление движения.
        * @param log включает логгирование движения в консоль.
        * @return точка в результате движения.
     */
    IntegerPoint2D navigate(const IntegerPoint2D& from, 
    const MOVEMENT& movement, bool log=false) const;

    /*!
        * @brief Движение в лабиринте по заданному маршруту.
        *
        * @detailed Маршрут представляет собой список
        * элементарных перемещений. Если в данном направлении нет смежной точки,
        * то координаты начальной точки не меняются.
        * Ошибки при этом не происходит.
        * 
        * @param from начальная точка.
        * @param movements маршрут (список элементарных движений).
        * @param log включает логгирование движения в консоль.
        * @return точка в результате движения.
    */
    IntegerPoint2D navigate(const IntegerPoint2D& from, 
    const std::list<MOVEMENT>& movements, bool log=false) const;

    friend std::ostream& operator<<(std::ostream& out, const IntegerMaze2D& maze);

private:    

    std::unordered_set<IntegerPoint2D, IntegerPoint2D::Hash> _maze;

    /*!
        * @brief Вспомогательный класс для чтения лабиринта из файла.
        * 
        * @detailed класс реализует функтор, который используется
        * как семантическое действие в парсере boost::spirit::qi.
        * 
        * Парсер необходим для разбора содержимого файла при
        * заполнении лабиринта.
     */
    class PointsParser {
    public:
    
        PointsParser(std::unordered_set<IntegerPoint2D, IntegerPoint2D::Hash>& maze_ref);
        
        /*!
            * @brief Функция при обнаружении координаты точки
            * 
            * @detailed Функция срабатывает, когда парсер
            * обнаруживает одну из двух координат точки.
            * 
            * Например для файла, содержащего (1, 2), (3, 4) ...
            * Данная функция будет вызвана сначала при обнаружении первой
            * координаты первой точки со значением 1, далее при обнаружении второй координаты
            * со значением 2 и так далее со значениями 3, 4, ...
            * 
            * @param val число, обнаруженное парсером.
         */
        void add_val(const int& val);
        
    private:
    
        std::unordered_set<IntegerPoint2D, IntegerPoint2D::Hash>& _maze_ref; //< ссылка на лабиринт для заполнения
        std::size_t _processed_coord; //< номер координаты, обрабатываемой в данный момент
        int _x;                       //< абсцисса точки
        int _y;                       //< ордината точки
    };
};

std::ostream& operator<<(std::ostream& out, const IntegerMaze2D::MOVEMENT& movement);