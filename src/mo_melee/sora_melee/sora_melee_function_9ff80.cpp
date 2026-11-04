#include <types.h>
#include <ef/ef_screen_handle.h>
#include <ef/ef_screen.h>
#pragma force_active on

class Class_C80 {
public:
    virtual void fn_27_FEE4();
    virtual efScreenHandle* fn_27_FF68(int);
    virtual void fn_27_FFAC();
    virtual int fn_27_FFF0();
};

struct Holder {
    Class_C80* array;
};

extern "C" void fn_8005E3C8(efScreen*, const u8*, float);
extern float lbl_27_rodata_CB0;

extern "C" void fn_27_9FF80(Holder* self) {
    for (int i = 0; i < self->array->fn_27_FFF0(); i++) {
        if (self->array->fn_27_FF68(i)->isValid() == 1) {
            u8 handle = *(u8*)self->array->fn_27_FF68(i);
            fn_8005E3C8(g_efScreen, &handle, lbl_27_rodata_CB0);
            *(s8*)self->array->fn_27_FF68(i) = -1;
        }
    }
}