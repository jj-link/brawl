#include <types.h>
#pragma force_active on

extern "C" void fn_800606C4(void* mgr, u32 flag);

extern void* g_ecMgr;

class fnVirtObj {
public:
    virtual void vf0() {}
    virtual void vf1() {}
    virtual void vf2() {}
    virtual void vf3() {}
    virtual void vf4() {}
    virtual void vf5() {}
    virtual int vf6(int a, int b, int c, int d, int e, float f);
};

extern "C" {
int fn_27_9881C(fnVirtObj* obj, int a, int b, int c, int d, float f) {
    fn_800606C4(g_ecMgr, 1);
    int result = obj->vf6(a, b, c, d, -1, f);
    fn_800606C4(g_ecMgr, 0);
    return result;
}
}
