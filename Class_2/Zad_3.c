#include <stdio.h>

// Definicja struktury Point
typedef struct {
    float x, y;
} Point;

// Funkcja do zmiany wartości współrzędnych punktu
void changePoint(Point *p, float x, float y) {
    p->x = x;
    p->y = y;
}

// Definicja struktury Rectangle
typedef struct {
    Point topLeft;     // Lewy górny róg
    Point bottomRight; // Prawy dolny róg
} Rectangle;

// Funkcja obliczająca pole prostokąta
float rectangleArea(Rectangle r) {
    float width = r.bottomRight.x - r.topLeft.x;
    float height = r.topLeft.y - r.bottomRight.y;
    return width * height;
}

// Funkcja obliczająca obwód prostokąta
float rectanglePerimeter(Rectangle r) {
    float width = r.bottomRight.x - r.topLeft.x;
    float height = r.topLeft.y - r.bottomRight.y;
    return 2 * (width + height);
}

int main() {
    // Utworzenie i zmiana współrzędnych punktu
    Point p = {0, 0};
    changePoint(&p, 5.0, 10.0);
    printf("Zmienione współrzędne punktu: x = %.2f, y = %.2f\n", p.x, p.y);

    // Utworzenie prostokąta i obliczenie jego pola i obwodu
    Rectangle rect = {{0, 10}, {10, 0}};
    float area = rectangleArea(rect);
    float perimeter = rectanglePerimeter(rect);
    printf("Pole prostokąta: %.2f\n", area);
    printf("Obwód prostokąta: %.2f\n", perimeter);

    return 0;
}
