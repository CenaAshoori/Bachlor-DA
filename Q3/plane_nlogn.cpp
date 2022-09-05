#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;


struct Point
{
    int x, y;
};

struct Result
{
    Result() :p1({ 0,0 }), p2({ 0,0 }), distance(LC_MAX) {};
    Point p1;
    Point p2;
    float distance;
};

float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
        (p1.y - p2.y) * (p1.y - p2.y)
    );
}

Result find_closest_in_rectangle(vector<Point> rectangle, Result r)
{
    float min = r.distance;
    int size = rectangle.size();

    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size && (rectangle[j].y - rectangle[i].y) < min; j++) {
            float distance = dist(rectangle[i], rectangle[j]);
            if (distance < min) {
                min = distance;
                r.p1 = rectangle[i];
                r.p2 = rectangle[j];
                r.distance = distance;
            }
        }
    return r;
}

Result recursive_find_minium_distance(vector<Point> px_list, vector<Point> py_list, int n)
{
    if (n <= 2) {                                                          // O(2.logn)
        float min = LC_MAX;
        Result result;
        for (int i = 0; i < n; ++i)                                        // O(1)  خطی
            for (int j = i + 1; j < n; ++j) {
                float distance = dist(px_list[i], px_list[j]);
                if (distance < min) {
                    min = distance;
                    result.p1 = px_list[i];
                    result.p2 = px_list[j];
                    result.distance = distance;
                }
            }
        return result;
    }

    int mid = n / 2;

    Point middle_point = px_list[mid];

    vector<Point> py_left;
    vector<Point> py_right;
    for (int i = 0; i < n; i++)                                                         // O(N.logN)
    {
        if (py_list[i].x <= middle_point.x )
        {
            py_left.push_back(py_list[i]);

        }
        else {
            py_right.push_back(py_list[i]);
        }
    }



    Result dl = recursive_find_minium_distance(px_list, py_left, mid);                      //O(logn)

    vector<Point> new_right;
    for (int i = n - mid; i < new_right.size(); i++)
        new_right.push_back(px_list[i]);

    Result dr = recursive_find_minium_distance(new_right, py_right, new_right.size());      // O(logn)



    Result r = (dl.distance < dr.distance) ? dl : dr;

    vector<Point> rectangle;
    for (int i = 0; i < n; i++)                                                     // O(N.logN)
        if (abs(py_list[i].x - middle_point.x) < r.distance)                        // O(N.logN)
            rectangle.push_back(py_list[i]);


    return find_closest_in_rectangle(rectangle, r);                                     // O(logn)

}


Result closest_points(vector<Point> points)
{
    vector<Point>  px;
    vector<Point>  py;
    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        px.push_back(points[i]);
        py.push_back(points[i]);
    }

    sort(px.begin(), px.end(), [](const Point& p1, const Point& p2)->bool {
        return (p1.x < p2.x);
        });
    sort(py.begin(), py.end(), [](const Point& p1, const Point& p2)->bool {
        return (p1.y < p2.y);
        });

    return recursive_find_minium_distance(px, py, n);
}

Result brutforce_method(vector<Point> points) {
    float min = LC_MAX;
    int size = points.size();
    Result result;
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            float distance = dist(points[i], points[j]);
            if (distance < min) {
                min = distance;
                result.p1 = points[i];
                result.p2 = points[j];
                result.distance = distance;
            }
        }
    }
    return result;
}

void show_result(Result result,string method_type)
{
    cout <<method_type <<":  \n"<< result.p1.x << "  " << result.p1.y << endl
        << result.p2.x << "  " << result.p2.y << endl
        << result.distance << "\n\n";
}
int tamrin5G()
{
    vector<Point> points = {
      {1,20},
      {2,1},
      {4,5},
      {5,19},
      {30,40},
    };
    Result result = closest_points(points);
    show_result(result, "nlogn algorithm");

    result = brutforce_method(points);
    show_result(result, "n ^2 algorithm");

    return 0;
}
