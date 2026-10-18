#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_36028(void* a, s32 b, s32 c);
extern "C" void fn_27_468D0(s32 a, void* b, s32 c);

struct A1 {
    s32 id;
    s16 off;
    s16 cnt;
};

class Obj {
public:
    virtual s32 a();
    virtual s32 c(s32);
};

extern "C" void fn_27_47180(A1* a1, void* a2, void* a3, Obj* a4) {
    if (a1->id != -1) {
        s32 vret;
        s32 i = 0;
        while (i < a1->cnt) {
            vret = a4->c(a1->off + i);
            s32 h = fn_27_36028(a3, i, a1->id);
            fn_27_468D0(vret, a2, h);
            i++;
        }
    }
}
