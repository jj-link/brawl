#include <types.h>
#include <ut/ut_relocate.h>
#pragma force_active on

extern "C" {
void* fn_80015E34(void*, s32, s32, s32, u32*, u16);
void* fn_800B03F0(void*, s32);
void fn_25_1304(void*, void*);
void fn_25_2C58(void*, void*);
void fn_25_2F3C(void*, void*);
void fn_25_2FF4(void*, void*);
void fn_24_1FD8(void*, void*);
void fn_24_1740(void*, void*);
extern char lbl_1_data_4A9C[];
extern char lbl_1_data_4AAC[];
}

extern "C" void fn_1_F48C(void* arg0) {
    u8* p = (u8*)arg0;
    u32 size;
    u8* buf = (u8*)fn_80015E34(*(void**)(p + 0x378), 0, 1, 0x28, &size, 0xFFFE);
    utRelocate reloc(buf, size);
    *(void**)(p + 0x360) = reloc.getPublicAddress(lbl_1_data_4A9C);
    *(void**)(p + 0x364) = reloc.getPublicAddress(lbl_1_data_4AAC);
    if (*(void**)(p + 0x380) != 0) {
        void* spC = fn_800B03F0(*(void**)(p + 0x378), 0x23);
        fn_25_1304(*(void**)(p + 0x380), &spC);
    }
    if (*(void**)(p + 0x384) != 0) {
        void* sp8 = fn_800B03F0(*(void**)(p + 0x378), 0x32);
        fn_25_2C58(*(void**)(p + 0x384), &sp8);
        *(void**)(*(u8**)(p + 0x384) + 0x40) = *(void**)(p + 0x380);
        fn_25_2F3C(*(void**)(p + 0x384), *(void**)(p + 0x360));
        fn_25_2FF4(*(void**)(p + 0x384), *(void**)(p + 0x364));
    }
    if (*(void**)(p + 0x388) != 0) {
        fn_24_1FD8(*(void**)(p + 0x388), *(void**)(p + 0x378));
    }
    if (*(void**)(p + 0x38C) != 0) {
        fn_24_1740(*(void**)(p + 0x38C), *(void**)(p + 0x378));
    }
}
