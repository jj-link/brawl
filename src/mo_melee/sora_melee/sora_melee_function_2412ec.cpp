#include <types.h>
#pragma force_active on

extern void* lbl_805A0350;
extern "C" void fn_8010F7EC(void*);
extern "C" void fn_8010F8FC(void*);
extern "C" void fn_8010F948(void*, int);
extern "C" void fn_8010F958(void*, int);

struct FooObj {
    u8 pad[0x64];
    u8 flags;
};

extern "C" void fn_27_2412EC(FooObj* self) {
    void* p = lbl_805A0350;
    if (p != 0) {
        if (((self->flags >> 6) & 1) == 0) {
            fn_8010F7EC(p);
            fn_8010F8FC(lbl_805A0350);
            self->flags |= 0x40;
        }
        fn_8010F948(lbl_805A0350, (self->flags >> 7) & 1);
        fn_8010F958(lbl_805A0350, (self->flags >> 5) & 1);
    }
}
