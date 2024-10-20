#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab_07.1it/Lab_07.1it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab71
{
    TEST_CLASS(UnitTestLab71)
    {
    public:

        TEST_METHOD(TestSort)
        {
            // Ініціалізація матриці
            int rowCount = 3;
            int colCount = 3;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            // Вхідні дані для тестування
            a[0][0] = 10; a[0][1] = 20; a[0][2] = 30;
            a[1][0] = 20; a[1][1] = 25; a[1][2] = 35;
            a[2][0] = 10; a[2][1] = 15; a[2][2] = 25;

            // Очікуваний результат
            int expected[3][3] = {
                {20, 25, 35},
                {10, 20, 30},
                {10, 15, 25}
            };

            // Виклик функції сортування
            Sort(a, rowCount, colCount);

            // Перевірка результату
            for (int i = 0; i < rowCount; i++) {
                for (int j = 0; j < colCount; j++) {
                    Assert::AreEqual(expected[i][j], a[i][j]);
                }
            }

            // Звільнення пам'яті
            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}