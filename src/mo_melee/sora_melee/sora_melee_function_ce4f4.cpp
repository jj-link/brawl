#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 a : 5;
    u32 b : 27;
} Fields;

extern "C" void fn_27_CE4F4(void* p, u32 v) {
    Fields* f = (Fields*)((char*)p + 8);
    f->a = v;
}
