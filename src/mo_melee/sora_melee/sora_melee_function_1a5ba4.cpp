#pragma force_active on
typedef unsigned int u32;

extern "C" char lbl_27_data_347E0[];

struct Obj {
    char* p0;
    char* p1;
    u32 flag;
};

extern "C" void fn_27_1A5BA4(Obj* o) {
    u32 f = o->flag;
    char* base = lbl_27_data_347E0;
    char* next = base + 0x48;
    f = f & 1;
    o->p0 = base;
    o->p1 = next;
    o->flag = f;
}
