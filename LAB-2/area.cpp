#include <stdio.h>
#include <iostream>
using namespace std;

class area {
public:
    int calculateSquareArea(int length) {
        return length * length;
    }
    int calculateCubeArea(int length) {
        return 6 * length * length;
    }
    int calculateRectangleArea(int length, int breadth) {
        return length * breadth;
    }
    int calculateCuboidArea(int length, int breadth, int height) {
        return 2 * (length * breadth + breadth * height + length * height);
    }
};

int main() {
    int choice;
    area Area;

    do {
        printf("\nMenu:\n");
        printf("1. SQUARE\n");
        printf("2. CUBE\n");
        printf("3. RECTANGLE\n");
        printf("4. CUBOID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int l, b, h; // Variables for dimensions
        switch (choice) {
            case 1:
                printf("Enter the value of the side length: ");
                scanf("%d", &l);
                printf("Area of the Square: %d\n", Area.calculateSquareArea(l));
                break;
            case 2:
                printf("Enter the value of the side length: ");
                scanf("%d", &l);
                printf("Surface Area of the Cube: %d\n", Area.calculateCubeArea(l));
                break;
            case 3:
                printf("Enter the value of length: ");
                scanf("%d", &l);
                printf("Enter the value of breadth: ");
                scanf("%d", &b);
                printf("Area of the Rectangle: %d\n", Area.calculateRectangleArea(l, b));
                break;
            case 4:
                printf("Enter the value of length: ");
                scanf("%d", &l);
                printf("Enter the value of breadth: ");
                scanf("%d", &b);
                printf("Enter the value of height: ");
                scanf("%d", &h);
                printf("Area of the Cuboid: %d\n", Area.calculateCuboidArea(l, b, h));
                break;
            case 5:
                printf("Exit\n");
                break;
            default:
                printf("Invalid\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
