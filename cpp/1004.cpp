#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <cmath>

struct position {
    int x, y;
};

struct solar_system {
    position middle;
    int radius;
};

float get_length (position p1, position p2) {
    int x = p1.x - p2.x; int y = p1.y - p2.y;
    int result = x * x + y * y;
    return sqrt(result);
}

int define_pos_in_system (position start, position end, solar_system s) {
    float start_dist = get_length(start, s.middle);
    float end_dist = get_length(end, s.middle);
    float radius = s.radius;
    
    // 둘 다 항성계 안에 있을 때
    if (start_dist <= radius && end_dist <= radius) return 0;
    // 둘 중 하나만 항성계 안에 있을 때
    else if (start_dist <= radius && end_dist > radius) return 1;
    else if (start_dist > radius && end_dist <= radius) return 1;
    // 둘 다 항성계 밖에 있을 때
    else return 0;
}

void test() {
    position start_point, end_point;
    cin >> start_point.x >> start_point.y >> end_point.x >> end_point.y;
    
    int solar_system_count; cin >> solar_system_count;
    vector<solar_system> ss_arr(solar_system_count);
    int result = 0;
    // solar_system_count만큼 반복해서 행성계 중점 및 반지름 집어넣기
    for (int i = 0; i < solar_system_count; i++) {
        cin >> ss_arr[i].middle.x >> ss_arr[i].middle.y >> ss_arr[i].radius;
        result += define_pos_in_system(start_point, end_point, ss_arr[i]);
    }
    cout << result << endl;
}

int main() {
    int T; cin >> T;
    while (T--) test();
    return 0;
}