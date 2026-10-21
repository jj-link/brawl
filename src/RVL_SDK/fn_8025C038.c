#pragma force_active on
typedef unsigned long u32;

struct Fn038 {
    u32 x0;
    u32 x4;
    char* x8;
};

void* fn_8025C038(struct Fn038* arg0, u32 arg1) {
    return arg0->x8 + (arg1 % arg0->x4) * 8;
}
