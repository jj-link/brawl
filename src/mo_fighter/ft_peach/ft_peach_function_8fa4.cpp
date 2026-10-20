#include <types.h>
#pragma force_active on

struct PeachObject {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void apply(s32*);
};

extern "C" void fn_103_8FA4(PeachObject* object, s32* values, s32 count) {
    if (values == 0 || count <= 0) {
        return;
    }

    for (s32 i = 0; i < count; ++i) {
        object->apply(&values[i]);
    }
}
