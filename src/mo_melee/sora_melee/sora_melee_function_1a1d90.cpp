#pragma force_active on
typedef unsigned int u32;

struct Fld {
    u32 a : 6;
    u32 b : 6;
    u32 c : 20;
};

extern "C" void fn_27_1A1D90(void* self, u32 val) {
    Fld* p = (Fld*)((char*)self + 8);
    p->b = val;
}
