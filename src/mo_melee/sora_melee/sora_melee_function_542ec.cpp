#pragma force_active on
typedef unsigned int u32;

struct Flags9 {
    u32 high : 9;
    u32 low : 23;
};

extern "C" {
void fn_27_542EC(void* p, u32 v) {
    Flags9* f = (Flags9*)((char*)p + 8);
    f->high = v;
}
}
