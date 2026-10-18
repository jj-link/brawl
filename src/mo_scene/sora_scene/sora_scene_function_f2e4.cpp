#include <types.h>
#pragma force_active on

extern "C" {
void* fn_25_E48(void);
void fn_25_1104(void);
void* fn_25_166C(void);
void fn_25_286C(void);
void fn_25_2E14(void* p);
void* fn_24_19A0(void);
void fn_24_1E70(void);
void* fn_24_1444(void);
void fn_24_15F4(void);
}

extern "C" void fn_1_F2E4(u8* self) {
    if (self[0x368] == 0) {
        *(void**)(self + 0x380) = fn_25_E48();
        fn_25_1104();
    }
    if (self[0x368] == 0) {
        void* p = fn_25_166C();
        *(void**)(self + 0x384) = p;
        fn_25_286C();
        p = *(void**)(self + 0x384);
        ((u8*)p)[0x144C] = 0;
        fn_25_2E14(*(void**)(self + 0x384));
    }
    *(void**)(self + 0x388) = fn_24_19A0();
    fn_24_1E70();
    if (self[0x368] == 0) {
        *(void**)(self + 0x38C) = fn_24_1444();
        fn_24_15F4();
    }
    self[0x36A] = 0;
    self[0x36B] = 0;
    *(u32*)(self + 0x36C) = 0;
    *(u32*)(self + 0x374) = 0;
}
