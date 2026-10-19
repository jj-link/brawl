#pragma force_active on
typedef int s32;

struct FnObj {
    s32 pad;
    s32 val;
};

extern "C" {
int fn_27_23334(const FnObj* a, const FnObj* b) {
    s32 x = a->val >> 16;
    s32 y = b->val >> 16;
    if (x == y) {
        return 0;
    }
    return x > y ? 1 : -1;
}
}
