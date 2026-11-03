#include <types.h>
#pragma force_active on

class Class_80488F1C {
public:
    virtual void fn_80331A88();
    virtual void fn_80080A64();
    virtual void fn_803318E4(void* item, s32 flag);
};

extern "C" void fn_80331884(Class_80488F1C* self, void** list) {
    while (*list != 0) {
        self->fn_803318E4(*list, 0);
        list++;
    }
}
