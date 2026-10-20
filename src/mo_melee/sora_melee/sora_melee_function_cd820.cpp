#pragma force_active on
typedef unsigned int u32;

struct FnBits {
    u32 a : 2;
    u32 b : 2;
    u32 c : 28;
};

extern "C" {
void fn_27_CD820(void* p, u32 v) {
    FnBits* f = (FnBits*)((char*)p + 8);
    f->b = v;
}
}
