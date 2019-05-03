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
        cout << "����஢���� ��������஢\n"
                "--------------------------\n"
                "���⮩ ᯨ᮪" << endl;

        List<int> test1;
        cout << "\n" << test1 << endl;

        cout << "\n������������� ������\n-----------\n"
                "   1. ���᮪ �� ������ �����:" << endl;

        List<double> test2(16.2);
        cout << "\n" << test2 << "\n" << endl;

        cout << "   3. ���ᨢ �� ��� ����⮢:\n"
                "���ᮡ �������: ���樠�����㥬 ���ᨢ,\n"
                "��।��� � ᯨ᮪ ᠬ ���ᨢ � ��� �����." << endl;
        float mass[6] = {static_cast<float>(-0.75), static_cast<float>(-0.5), 0, 1, 2.5, 5};
        List<float> test4(mass, 6);
        cout << "\n" << test4 << "\n" << endl;

        cout << "   4. ���ᨢ �� ��� ����⮢:\n"
                "���ᨢ, �ந��樠����஢���� ����� ����⠬�,\n"
                "��।��� � ᯨ᮪, �� � ������ 5." << endl;
        List<float> test5(mass, 5);
        cout << "\n" << test5 << endl << endl;

        cout << "   5. ��१ 䨣��� ᪮���:\n"
                "{1, 2, 3, 4}" << endl;
        List<int> test00({1, 2, 3, 4});
        cout << "\n" << test00 << endl;

        cout << endl << endl << "�����������" << endl << "-----------" << endl << endl;
        cout << "   1. ��� ��㬥�� ᯨ�� ��।��� ��㣮� ᯨ᮪:" << endl;
        List<float> test6(test5);
        cout << "\n" << test6 << "\n" << endl;
        cout << "\n" << test5 << "\n" << endl;

        cout << "   2. ��ᢠ������: " << endl;
        cout << test4 << " = " << test5 << endl;
        test4 = test5;
        cout << "\n" << test4 << endl;
        cout << "\n" << test5 << endl;

        cout << endl << endl << "�����������" << endl << "-----------" << endl << endl;
        cout << test6 << "\n" << test5 << endl;
        cout << "\n" << "����� �� ᯨ᪨?" << "\n" << endl;
        if (test5 == test6)
        {
            cout << "�����." << endl;
        }
        else
        {
            cout << "�� ࠢ��." << endl;
        }
        if (test5.equal(test6))
        {
            cout << "�����." << endl;
        }
        else
        {
            cout << "�� ࠢ��." << endl;
        }
        //test5.insert_by_ind(2, 34);
        //test5.insert_by_ind(1, 3);
        cout << endl << test6 << "\n" << test5 << endl;
        cout << "\n" << "�� ࠢ�� �� ᯨ᪨?" << "\n" << endl;
        if (test5 != test6)
        {
            cout << "�� ࠢ��." << endl;
        }
        else
        {
            cout << "�����." << endl;
        }

        cout << endl << "INSERT BY INDEX" << endl << "-----------" << endl << endl;
        cout << "� test5 ��⠢�� 55 �� ������� 0:" << endl << endl;
        float num = 55;
        size_t ind = 0;
        cout << test5 << endl << endl;
        //test5.insert_by_ind(ind, num);
        cout << test5 << endl;
        cout << "� test5 ��⠢�� 33 �� ������� 3:" << endl << endl;
        num = 33;
        ind = 3;
        cout << test5 << endl << endl;
        //test5.insert_by_ind(ind, num);
        cout << test5 << endl;

        cout << endl << "PUSH_FRONT" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "������� ����� 16.6 � ��砫�:" << endl;
        test5.add_to_head(16.6);
        cout << test5 << endl;

        cout << endl << "PUSH_BACK" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "������� ����� 30 � �����:" << endl;
        test5.add_to_tail(30);
        cout << test5 << endl;

        cout << endl << "POP_FRONT" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "������ ����� �� ��砫� ᯨ᪠:" << endl;
        //cout << endl << "��������� �᫮: " << test5.get_from_head() << endl;
        cout << test5 << endl;

        cout << endl << "POP_BACK" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "������ ����� �� ���� ᯨ᪠:" << endl;
        //cout << endl << "��������� �᫮: " << test5.get_from_tail() << endl;
        cout << test5 << endl;

        /*
        cout << endl << "REMOVE BY VALUE" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "������ ����� 0" << endl;
        test5.delete_elem(0);
        cout << test5 << endl;

        cout << endl << "REMOVE BY INDEX" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "������ ����� �� ������� 1" << endl;
        test5.delete_by_ind(1);
        cout << test5 << endl;
        cout << "������ ����� �� ������� 2" << endl;
        test5.delete_by_ind(2);
        cout << test5 << endl;
        cout << "������ ����� �� ������� 0" << endl;
        test5.delete_by_ind(0);
        cout << test5 << endl;
        */

        cout << endl << "�������� ᯨ᪮�:" << endl << "-----------" << endl << endl;
        cout << "     1." << test5 << "+ " << test6 << endl << endl;
        test5 = test5 + test6;
        cout << test5 << endl << endl;
        cout << "     2. test5.merge(test6)" << endl << endl;
        test5.merge(test6);
        cout << test5 << endl;

        /*
        List<float>test9{1, 9, 4, 6, 5};
        cout << endl << "����஢�� ᯨ᪮�:" << endl << "-----------" << endl << endl;
        cout << test9 << endl << endl;
        test9.sort();
        cout << test9 << endl << endl;
        test9.sort(false);
        cout << test9 << endl << endl;
        */

        /*
        cout << endl << "�뢥�� ����� �� �������:" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "�뢥��� ����� �� ������� 3" << endl;
        cout << test5.get_elem(3);
        */

        cout << endl << "������ ������\n-----------\n\n" << test5 << "\n�����:" << test5.size() << endl;

        test5.clear();
        cout << endl << test5 << endl << endl;

        /*
        cout << endl << "�������� ���������饣� �����:\n-----------\n";
        cout << endl << test4 << endl << endl;
        cout << "������ ����� 2.2";
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
