#pragma force_active on
typedef unsigned int u32;

struct Fld {
    u32 hi : 10;
    u32 f : 10;
    u32 lo : 12;
};

extern "C" {
void fn_27_1A6454(void* obj, u32 v) {
    Fld* p = (Fld*)&((u32*)obj)[2];
    p->f = v;
}
}
