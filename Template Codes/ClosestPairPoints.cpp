#include <bits/stdc++.h>
#define SQR(a) ((a)*(a))
using namespace std;

class point
{
    public:
    int x, y;
};

bool compareX(point p1,point p2){return p1.x < p2.x;}
bool compareY(point p1,point p2){return p1.y < p2.y;}
double dist(point p1,point p2){return sqrt(SQR(p1.x - p2.x) + SQR(p1.y - p2.y));}

// A Brute Force method to return the smallest distance between two points in P[] of size n
double bruteForce(point P[], int n)
{
    double min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

// A utility function to find the distance between the closest points of strip of a given size. All points in strip[] are sorted according to y coordinate. They all have an upper bound on minimum distance as d. Note that this method seems to be a O(n^2) method, but it's a O(n) method as the inner loop runs at most 6 times
double stripClosest(point strip[], int size, double d)
{
    double min = d;  // Initialize the minimum distance as d
    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}
// A recursive function to find the smallest distance. The array Px contains
// all points sorted according to x coordinates and Py contains all points
// sorted according to y coordinates




double closestUtil(point Px[], point Py[], int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(Px, n);

    // Find the middle point
    int mid = n/2;
    point midPoint = Px[mid];


    // Divide points in y sorted array around the vertical line.
    // Assumption: All x coordinates are distinct.
    point Pyl[mid+1];   // y sorted points on left of vertical line
    point Pyr[n-mid-1];  // y sorted points on right of vertical line
    int li = 0, ri = 0;  // indexes of left and right subarrays
    for (int i = 0; i < n; i++)
    {
      if (Py[i].x <= midPoint.x)
         Pyl[li++] = Py[i];
      else
         Pyr[ri++] = Py[i];
    }

    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and dr on right side
    double dl = closestUtil(Px, Pyl, mid);
    double dr = closestUtil(Px + mid, Pyr, n-mid);

    // Find the smaller of two distances
    double d = min(dl, dr);

    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;

    // Find the closest points in strip.  Return the minimum of d and closest distance is strip[]
    return min(d, stripClosest(strip, j, d) );
}

double closest(point P[], int n)
{
    point Px[n];
    point Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }

    sort(Px, Px + n, compareX);
    sort(Py, Py + n, compareY);

    // Use recursive function closestUtil() to find the smallest distance
    return closestUtil(Px, Py, n);
}

int main()
{
    point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << "The smallest distance is " << closest(P, n);
    return 0;
}




