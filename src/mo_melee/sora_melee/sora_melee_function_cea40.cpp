#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 a : 12;
    u32 b : 6;
    u32 c : 14;
} Flags;

extern "C" void fn_27_CEA40(void* p, u32 v) {
    Flags* f = (Flags*)((char*)p + 8);
    f->b = v;
}
