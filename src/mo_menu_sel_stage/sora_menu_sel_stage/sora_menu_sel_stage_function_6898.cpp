#pragma force_active on
#include <types.h>
#include <nw4r/math/math_types.h>
extern const char lbl_11_data_0[];
extern "C" {
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
int sprintf(char*, const char*, ...);
void fn_800B6C38(Vec*, void*, const char*);
}
inline nw4r::math::VEC3 getpos(void* a, const char* name) {
    Vec v;
    fn_800B6C38(&v, a, name);
    return nw4r::math::VEC3(v);
}
extern "C" int fn_11_6898(void* unused, const Vec* pos, void* a, s32 idx) {
    char sp18[8];
    char sp10[8];
    char sp8[8];
    strcpy(sp18, lbl_11_data_0 + 0x428);
    strcpy(sp10, lbl_11_data_0 + 0x430);
    if (idx >= 0) {
        sprintf(sp8, lbl_11_data_0 + 0x438, idx);
        strcat(sp18, sp8);
        strcat(sp10, sp8);
    }
    nw4r::math::VEC3 v1 = getpos(a, sp18);
    nw4r::math::VEC3 v2 = getpos(a, sp10);
    if (pos->x >= v1.x && pos->x <= v2.x && pos->y >= v1.y && pos->y <= v2.y) return 1;
    return 0;
}