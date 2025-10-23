#include <iostream>
#include <cmath>
using namespace std;

// Function prototypes
void sphere();
void cuboid();
void pyramid();
void cylinder();

const double pi = 3.142;

int main() {
    int choice;

    cout << "=== Area and Volume Calculator ===\n";
    cout << "1. Sphere\n";
    cout << "2. Cuboid\n";
    cout << "3. Pyramid\n";
    cout << "4. Cylinder\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    cout << endl;

    switch (choice) {
        case 1: sphere(); break;
        case 2: cuboid(); break;
        case 3: pyramid(); break;
        case 4: cylinder(); break;
        default: cout << "Invalid choice!" << endl;
    }

    return 0;
}

// Function for sphere
void sphere() {
    double r;
    cout << "Enter radius (in cm): ";
    cin >> r;

    double area = 4 * pi * r * r;
    double volume = (4.0 / 3.0) * pi * r * r * r;

    cout << "Surface Area = " << area << "cm^2" << endl;
    cout << "Volume = " << volume << "cm^3" << endl;
}

// Function for cuboid
void cuboid() {
    double l, w, h;
    cout << "Enter length, width, and height (in cm): ";
    cin >> l >> w >> h;

    double area = 2 * (l*w + w*h + h*l);
    double volume = l * w * h;

    cout << "Surface Area = " << area << "cm^2" << endl;
    cout << "Volume = " << volume << "cm^3" << endl;
}

// Function for pyramid (square base)
void pyramid() {
    double base, height;
    cout << "Enter base length and height (in cm): ";
    cin >> base >> height;

    double base_area = base * base;
    double slant_height = sqrt((base / 2) * (base / 2) + height * height);
    double area = base_area + 2 * base * slant_height;
    double volume = (base_area * height) / 3;

    cout << "Surface Area = " << area << "cm^2" << endl;
    cout << "Volume = " << volume << "cm^3" << endl;
}

// Function for cylinder
void cylinder() {
    double r, h;
    cout << "Enter radius and height (in cm): ";
    cin >> r >> h;

    double area = 2 * pi * r * (r + h);
    double volume = pi * r * r * h;

    cout << "Surface Area = " << area << "cm^2" << endl;
    cout << "Volume = " << volume << "cm^3" << endl;
}
