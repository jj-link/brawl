#pragma force_active on
typedef unsigned int u32;

struct Fields {
    u32 a : 3;
    u32 b : 3;
    u32 c : 26;
};

extern "C" {
void fn_27_1D0044(void* self, u32 val) {
    Fields* f = (Fields*)((char*)self + 8);
    f->b = val;
}
}
