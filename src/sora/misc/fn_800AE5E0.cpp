#include <types.h>
#pragma force_active on
extern "C" const float lbl_805A21E8;
struct Point { float x, y; };
extern "C" int fn_800AE5E0(const Point* a, unsigned int na, const Point* b, unsigned int nb) {
    for (unsigned int i = 0; i < na - 1; i++) {
        Point p = { a[i].x, a[i].y };
        unsigned int count = 0;
        for (unsigned int j = 0; j < nb - 1; j++) {
            Point v = { b[j].x, b[j].y };
            Point w = { b[j+1].x, b[j+1].y };
            if (v.y == w.y && w.y == p.y) {
                float maxx = v.x < w.x ? w.x : v.x;
                if (p.x <= maxx) {
                    if (j == nb - 2) break;
                    unsigned int prev = j == 0 ? nb - 2 : j - 1;
                    float py = b[prev].y;
                    float ny = b[j+2].y;
                    if ((py < p.y && ny > p.y) || (py > p.y && ny < p.y)) count++;
                    j++;
                }
            } else {
                float low, high;
                if (v.y < w.y) { low = v.y; high = w.y; }
                else { low = w.y; high = v.y; }
                if (p.y < low || p.y > high) continue;
                if (v.y == p.y) {
                    if (!(v.x < p.x)) {
                        float py = j == 0 ? ((const float*)(b + nb))[-3] : b[j-1].y;
                        if ((v.y < w.y && v.y > py) || (v.y > w.y && v.y < py)) count++;
                    }
                } else if (w.y == p.y) {
                    if (j == nb - 2) break;
                    if (w.x < p.x) { j++; continue; }
                    float ny = b[j+2].y;
                    if (ny != p.y) {
                        if ((w.y < v.y && w.y > ny) || (w.y > v.y && w.y < ny)) count++;
                        j++;
                    }
                } else {
                    float minx, maxx;
                    if (v.x < w.x) { minx = v.x; maxx = w.x; }
                    else { minx = w.x; maxx = v.x; }
                    if (p.x < minx) count++;
                    else if (!(p.x > maxx)) {
                        if (v.x == w.x) {
                            if (p.x < v.x) count++;
                        } else {
                            float slope = (v.y - w.y) / (v.x - w.x);
                            float y = v.y + slope * p.x - slope * v.x;
                            if (slope < lbl_805A21E8) {
                                if (p.y <= y) count++;
                            } else {
                                if (p.y >= y) count++;
                            }
                        }
                    }
                }
            }
        }
        if ((count & 1) == 1) return 1;
    }
    return 0;
}