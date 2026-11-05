#include <types.h>
#pragma force_active on

struct Self {
    s32 id;
    s16 off;
    s16 cnt;
    char pad[0x88];
    float x, y, z;
};

class Class_3FE0 {
public:
    virtual void fn_27_4742C();
    virtual void* fn_27_4746C(s32);
};

extern "C" void* fn_27_36028(void*, s32, s32);
extern "C" void fn_27_46770(void*, void*);

extern "C" void fn_27_46BB4(Self* self, void* arg1, Class_3FE0* arg2, float x, float y, float z) {
    self->x = x;
    self->y = y;
    self->z = z;
    if (self->id != -1) {
        void* p;
        s32 i = 0;
        while (i < self->cnt) {
            p = arg2->fn_27_4746C(self->off + i);
            void* q = fn_27_36028(arg1, i, self->id);
            fn_27_46770(p, q);
            i++;
        }
    }
}