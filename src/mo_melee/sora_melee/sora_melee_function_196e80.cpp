#include <types.h>
#pragma force_active on
struct WorkObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 get();
};
struct Container {
    void* unk0;
    WorkObj* work;
    s32 flag;
    s32 value;
};
extern "C" s32 fn_27_196E80(const Container* container) {
    s32 result = container->value;
    if (container->flag == 0) {
        result = 0;
    }
    if (container->work) {
        return result + container->work->get();
    }
    return result;
}
