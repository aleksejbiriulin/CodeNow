#include <GL/glut.h>

void drawCube() {
    glBegin(GL_QUADS); // Начинаем рисовать квадраты (грань куба)

    // Передняя грань (синий)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);

    // Задняя грань (красный)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    // Левый бок (зеленый)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);

    // Правый бок (желтый)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f,  1.0f);
    glVertex3f(1.0f,  1.0f,  1.0f);
    glVertex3f(1.0f,  1.0f, -1.0f);

    // Верхняя грань (белый)
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f,  1.0f);
    glVertex3f( 1.0f, 1.0f,  1.0f);
    glVertex3f( 1.0f, 1.0f, -1.0f);

    // Нижняя грань (черный)
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    glEnd(); // Заканчиваем рисование
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Очищаем буфер цвета и глубины
    glLoadIdentity(); // Загружаем единичную матрицу

    // Устанавливаем камеру
    gluLookAt(5.0, 5.0, 5.0,   // Позиция камеры
              0.0, 0.0, 0.0,   // Центр просмотра
              0.0, 1.0, 0.0);  // Вектор "вверх"

    drawCube(); // Рисуем куб

    glutSwapBuffers(); // Обмениваем буферы
}

void init() {
    glEnable(GL_DEPTH_TEST); // Включаем тест глубины
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Инициализация GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Устанавливаем режим отображения
    glutInitWindowSize(800, 600); // Устанавливаем размер окна
    glutCreateWindow("3D Cube"); // Создаем окно
    init(); // Инициализируем OpenGL
    glutDisplayFunc(display); // Устанавливаем функцию отображения
    glutMainLoop(); // Запускаем главный цикл GLUT
    return 0;
}
