#include <iostream>
#include "list.h"
#include "list_elem.h"
#include "list_iterator.h"
#include "errors.h"

using namespace std;

int main(int argc, const char * argv[])
{
    try
    {
        cout << "Тестирование конструкторов\n"
                "--------------------------\n"
                "Пустой список" << endl;

        List<int> test1;
        cout << "\n" << test1 << endl;

        cout << "\nИНИЦИАЛИЗАЦИЯ СПИСКА\n-----------\n"
                "   1. Список из одного элемента:" << endl;

        List<double> test2(16.2);
        cout << "\n" << test2 << "\n" << endl;

        cout << "   3. Массив из шести элементов:\n"
                "Способ задания: инициализируем массив,\n"
                "передаем в список сам массив и его длину." << endl;
        float mass[6] = {static_cast<float>(-0.75), static_cast<float>(-0.5), 0, 1, 2.5, 5};
        List<float> test4(mass, 6);
        cout << "\n" << test4 << "\n" << endl;

        cout << "   4. Массив из пяти элементов:\n"
                "Массив, проинициализированный шестью элементами,\n"
                "передаем в список, но с длиной 5." << endl;
        List<float> test5(mass, 5);
        cout << "\n" << test5 << endl << endl;

        cout << "   5. Через фигурные скобки:\n"
                "{1, 2, 3, 4}" << endl;
        List<int> test00({1, 2, 3, 4});
        cout << "\n" << test00 << endl;

        cout << endl << endl << "КОПИРОВАНИЕ" << endl << "-----------" << endl << endl;
        cout << "   1. Как аргумент списку передаем другой список:" << endl;
        List<float> test6(test5);
        cout << "\n" << test6 << "\n" << endl;
        cout << "\n" << test5 << "\n" << endl;

        cout << "   2. Присваивание: " << endl;
        cout << test4 << " = " << test5 << endl;
        test4 = test5;
        cout << "\n" << test4 << endl;
        cout << "\n" << test5 << endl;

        cout << endl << endl << "СРАВНИВАНИЕ" << endl << "-----------" << endl << endl;
        cout << test6 << "\n" << test5 << endl;
        cout << "\n" << "Равны ли списки?" << "\n" << endl;
        if (test5 == test6)
        {
            cout << "Равны." << endl;
        }
        else
        {
            cout << "Не равны." << endl;
        }
        if (test5.equal(test6))
        {
            cout << "Равны." << endl;
        }
        else
        {
            cout << "Не равны." << endl;
        }
        //test5.insert_by_ind(2, 34);
        //test5.insert_by_ind(1, 3);
        cout << endl << test6 << "\n" << test5 << endl;
        cout << "\n" << "НЕ равны ли списки?" << "\n" << endl;
        if (test5 != test6)
        {
            cout << "Не равны." << endl;
        }
        else
        {
            cout << "Равны." << endl;
        }

        cout << endl << "INSERT BY INDEX" << endl << "-----------" << endl << endl;
        cout << "В test5 вставим 55 по индексу 0:" << endl << endl;
        float num = 55;
        size_t ind = 0;
        cout << test5 << endl << endl;
        //test5.insert_by_ind(ind, num);
        cout << test5 << endl;
        cout << "В test5 вставим 33 по индексу 3:" << endl << endl;
        num = 33;
        ind = 3;
        cout << test5 << endl << endl;
        //test5.insert_by_ind(ind, num);
        cout << test5 << endl;

        cout << endl << "PUSH_FRONT" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "Добавим элемент 16.6 в начало:" << endl;
        test5.add_to_head(16.6);
        cout << test5 << endl;

        cout << endl << "PUSH_BACK" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "Добавим элемент 30 в конец:" << endl;
        test5.add_to_tail(30);
        cout << test5 << endl;

        cout << endl << "POP_FRONT" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "Удалим элемент из начала списка:" << endl;
        //cout << endl << "Удаленное число: " << test5.get_from_head() << endl;
        cout << test5 << endl;

        cout << endl << "POP_BACK" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "Удалим элемент из конца списка:" << endl;
        //cout << endl << "Удаленное число: " << test5.get_from_tail() << endl;
        cout << test5 << endl;

        /*
        cout << endl << "REMOVE BY VALUE" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "Удалим элемент 0" << endl;
        test5.delete_elem(0);
        cout << test5 << endl;

        cout << endl << "REMOVE BY INDEX" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "Удалим элемент по индексу 1" << endl;
        test5.delete_by_ind(1);
        cout << test5 << endl;
        cout << "Удалим элемент по индексу 2" << endl;
        test5.delete_by_ind(2);
        cout << test5 << endl;
        cout << "Удалим элемент по индексу 0" << endl;
        test5.delete_by_ind(0);
        cout << test5 << endl;
        */

        cout << endl << "Сложение списков:" << endl << "-----------" << endl << endl;
        cout << "     1." << test5 << "+ " << test6 << endl << endl;
        test5 = test5 + test6;
        cout << test5 << endl << endl;
        cout << "     2. test5.merge(test6)" << endl << endl;
        test5.merge(test6);
        cout << test5 << endl;

        /*
        List<float>test9{1, 9, 4, 6, 5};
        cout << endl << "Сортировка списков:" << endl << "-----------" << endl << endl;
        cout << test9 << endl << endl;
        test9.sort();
        cout << test9 << endl << endl;
        test9.sort(false);
        cout << test9 << endl << endl;
        */

        /*
        cout << endl << "Вывести элемент по индексу:" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "Выведем элемент по индексу 3" << endl;
        cout << test5.get_elem(3);
        */

        cout << endl << "РАЗМЕР СПИСКА\n-----------\n\n" << test5 << "\nДлина:" << test5.size() << endl;

        test5.clear();
        cout << endl << test5 << endl << endl;

        /*
        cout << endl << "Удаление несуществующего элемента:\n-----------\n";
        cout << endl << test4 << endl << endl;
        cout << "Удалим элемент 2.2";
        test4.delete_elem(2.2);
        cout << endl << test4 << endl << endl;
        */
    }
    catch (baseError & err)
    {
        cout << "\n\n" << err.what() << endl;
    }
    return 0;
}
