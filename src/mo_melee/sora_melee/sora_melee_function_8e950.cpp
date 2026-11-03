#include <mt/mt_prng.h>
#pragma force_active on
extern "C" const float lbl_27_rodata_C28;
class Class_C80 {
public:
    virtual void fn_27_FEE4();
    virtual void fn_27_FF68();
    virtual float* fn_27_FFAC(int);
    virtual int fn_27_FFF0();
};
extern "C" int fn_27_8E950(Class_C80* self) {
    float sum = lbl_27_rodata_C28;
    for (int i = 0; i < self->fn_27_FFF0(); i++) {
        sum += *self->fn_27_FFAC(i);
    }
    if (sum <= lbl_27_rodata_C28) return -1;
    sum *= randf();
    float accum = lbl_27_rodata_C28;
    if (accum == sum) {
        for (int i = 0; i < self->fn_27_FFF0(); i++) {
            if (*self->fn_27_FFAC(i) >= accum) return i;
        }
        return -1;
    }
    for (int i = 0; i < self->fn_27_FFF0(); i++) {
        accum += *self->fn_27_FFAC(i);
        if (sum <= accum) return i;
    }
    return -1;
}