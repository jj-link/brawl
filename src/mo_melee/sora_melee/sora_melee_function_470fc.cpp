#include <types.h>
#pragma force_active on

extern "C" {

struct S {
    char pad0[4];
    s16 val;
    s16 count;
};

class V {
public:
    virtual void d0();
    virtual void* d1(s32 a);
};

void fn_27_46888(void* a, void* b);

void fn_27_470FC(S* p, V* obj, void* r5) {
    for (s32 i = 0; i < p->count; i++) {
        fn_27_46888(obj->d1(p->val + i), r5);
    }
}

}
