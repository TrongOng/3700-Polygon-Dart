//File containing other functions necessary for the program
#include <iostream>
#include "point.h"

using namespace std;
Fraction areaPolygon(Point points[], int vs);
bool intersect(Point p1,Point p2,Point q1,Point q2, Point &x);
bool insidePolygon(Point p, Point c, Point q[], int vs);
int main() {
    int numPolygons, numVertices, numDarts, v;
    Point bottomLeft(0,0), topRight;
    Point polygons[100][20];
    Point points[20];
    //Fraction area[5];
    Point polygon[20];
    Point p, d;
    Fraction score, totalScore;
    
    //cout << "Input Top Right" << endl;
    cin >> topRight;
    //cout << "Input Number of Polygons" << endl;
    cin >> numPolygons;
    int* numberVertices = new int[numPolygons];
    for (int i = 0; i < numPolygons; i++) {
        //cout << "input vertices number amount" << endl;
        cin >> numVertices;
        //cout << "Add polygon point X and Y" << endl;
        for (int j = 0, k = 0; j < numVertices; j++, k++) {
            cin >> p;
            polygons[i][j] = p;
            points[k] = p;
            numberVertices[i] = numVertices; //take in amount of vertices in a polygon
        }
    }
    //darts thrown
    //cout << "Number of Darts: " << endl;
    cin >> numDarts;
    Point* dart = new Point[numDarts];
    for (int i = 0; i < numDarts; i++) {
        cin >> d;
        dart[i] = d;
    }
    
    for (int i = 0; i < numPolygons; i++) {
        v = numberVertices[i];
        for (int j = 0; j < v; j++) {
            polygon[j] = polygons[i][j];
            if(j == (v-1)) {
                for (int z = 0; z < numDarts; z++) {
                    if(insidePolygon(dart[z], topRight, polygon, v)) {
                        score = (topRight.getX()*topRight.getY())/areaPolygon(polygon, v);
                        totalScore = totalScore + score;
                        //cout << "True" << endl;
                        //cout << totalScore << endl;
                    }
                    else {
                        //cout << "False" << endl;
                    }
                }
            }
        }
    }
    cout << totalScore << endl;
    return 0;
}
Fraction areaPolygon(Point points[], int vs) {
    Fraction a, cp;
    for (int i = 0; i < vs; i++) {
        cp = points[i]*points[(i+1)%vs];
        a = a + cp;
    }
    return a/2;
}
bool intersect(Point p1,Point p2,Point q1,Point q2, Point &x) {
    Fraction d, t, u;
    Point r, s, v;
    r = p2 - p1;
    s = q2 - q1;
    
    v = q1 - p1;
    d = r*s;
    
    if (d !=0) {
        t = (v*s)/d;
        u = (v*r)/d;
        if (((t > 0) && (t < 1)) && ((u > 0) && (u < 1))) {
            x = p1 + (r*t);
            return true;
        }
    }
    return false;
}
bool insidePolygon(Point p, Point c, Point q[], int vs) {
    //d = p (d = darts)
    //c = opposite of 0,0 
    // w = winding number
    Point v1, v2, h1, h2, z1, z2, x;
    Point zero(0,0);
    int w = 0;
    v1 = Point(p.getX(), zero.getY());
    v2 = Point(p.getX(), c.getY());
    
    h1 = Point(zero.getX(), p.getY());
    h2 = Point(c.getX(), p.getY());
    
    //cout << v1 << endl << v2 << endl << h1 << endl << h2 << endl;
    
    for (int i = 0; i < vs; i++) {
        if (intersect(v1, v2, q[i], q[(i+1)%vs], x)) {
            z1 = x - p;
            z2 = q[(i+1)%vs] - q[i];
            
            if (z1.getY() * z2.getX() < 0) {
                w = w + 1;
            }
            else {
                w = w - 1;
            }
        }
        if (intersect(h1, h2, q[i], q[(i+1)%vs], x)) {
            z1 = x - p;
            z2 = q[(i+1)%vs] - q[i];
            
            if (z1.getX()*z2.getY() > 0) {
                w = w + 1;
            }
            else {
                w = w - 1;
            }
        }
    }
    if (w == 0) {
        return false;
    }
    else {
        return true;
    }
    
}







