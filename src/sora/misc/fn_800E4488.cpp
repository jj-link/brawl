#include <types.h>
#include <math.h>
#include <stdio.h>
#pragma force_active on
struct Vec { float x, y, z; };
extern "C" {
extern char lbl_8059E260[8];
extern const float lbl_805A23C0, lbl_805A244C, lbl_805A2450;
void fn_800B6C38(Vec*, void*, const char*);
void fn_800B6838(void*, const Vec*);
}
extern "C" int fn_800E4488(int i, char* self) {
    Vec target;
    Vec pos;
    void* obj = *(void**)(self + (i + 0x19) * 4 + 0x28);
    pos.x = ((Vec*)((char*)obj + 0x3c))->x;
    pos.y = ((Vec*)((char*)obj + 0x3c))->y;
    pos.z = ((Vec*)((char*)obj + 0x3c))->z;
    char name[8];
    sprintf(name, lbl_8059E260, i + 2);
    Vec tmp;
    fn_800B6C38(&tmp, *(void**)(self + 0x88), name);
    target.x = tmp.x;
    target.y = tmp.y;
    target.z = tmp.z;
    if (pos.x != target.x) {
        if (pos.x < target.x) {
            pos.x += lbl_805A23C0;
            if (pos.x > target.x) pos.x = target.x;
        } else {
            pos.x -= lbl_805A23C0;
            if (pos.x < target.x) pos.x = target.x;
        }
    }
    float start = *(float*)(self + i * 12 + 0x228);
    pos.y = target.y + lbl_805A2450 * (float)sin(lbl_805A244C * ((pos.x - start) / (target.x - start)));
    fn_800B6838(obj, &pos);
    if (pos.x == target.x) return 2;
    return *(int*)(self + i * 4 + 0x214);
}