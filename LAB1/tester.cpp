#include <iostream>
#include <cmath>
using namespace std;

// Hàm giải phương trình trùng phương: a*x^4 + b*x^2 + c = 0
int solveQuartic(double a, double b, double c, double x[]) {
    if (a == 0 && b == 0 && c == 0) return -1; // vô số nghiệm
    if (a == 0 && b == 0) return 0; // vô nghiệm

    if (a == 0) { // b*x^2 + c = 0
        double y = -c / b;
        if (y < 0) return 0;
        x[0] = sqrt(y);
        x[1] = -sqrt(y);
        return 2;
    }

    double delta = b*b - 4*a*c;
    if (delta < 0) return 0;

    double y1 = (-b + sqrt(delta)) / (2*a);
    double y2 = (-b - sqrt(delta)) / (2*a);

    int count = 0;
    if (y1 >= 0) {
        x[count++] = sqrt(y1);
        x[count++] = -sqrt(y1);
    }
    if (y2 >= 0 && fabs(y2 - y1) > 1e-9) {
        x[count++] = sqrt(y2);
        x[count++] = -sqrt(y2);
    }
    return count;
}

void runTest(double a, double b, double c, string desc) {
    double x[4];
    int n = solveQuartic(a,b,c,x);

    cout << desc << " -> ";
    if (n == -1) {
        cout << "infinite solutions";
    } else if (n == 0) {
        cout << "no solution";
    } else {
        cout << n << " solution(s): ";
        for (int i=0;i<n;i++) cout << x[i] << " ";
    }
    cout << endl;
}

int main() {
    runTest(0,0,0, "(0,0,0)");
    runTest(0,0,5, "(0,0,5)");
    runTest(0,2,-8, "(0,2,-8)");
    runTest(1,0,1, "(1,0,1)");
    runTest(1,0,-1, "(1,0,-1)");
    runTest(1,-5,4, "(1,-5,4)");
    runTest(1,2,1, "(1,2,1)");
    runTest(-1,1,0, "(-1,1,0)");
    return 0;
}
