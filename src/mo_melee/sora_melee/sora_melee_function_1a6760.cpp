#pragma force_active on
typedef unsigned int u32;

struct Fld {
    u32 a : 10;
    u32 b : 10;
    u32 c : 12;
};

extern "C" void fn_27_1A6760(void* p, u32 v) {
    Fld* f = (Fld*)((char*)p + 8);
    f->b = v;
}
