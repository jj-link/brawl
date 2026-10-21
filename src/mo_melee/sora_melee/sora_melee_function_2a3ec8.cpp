#include <types.h>
#pragma force_active on

struct __FILE;
extern struct __FILE __files[];
extern const char lbl_27_data_7908C[];
extern "C" int fn_803F86E4(struct __FILE*, const char*, ...);
extern "C" void fn_803FC984(void);

extern "C" int fn_27_2A3EC8(void* mgr, u32 kind) {
    if (kind >= 0xB2) {
        fn_803F86E4((struct __FILE*)((char*)&__files + 0xA0), lbl_27_data_7908C);
        fn_803FC984();
    }
    u32 word = *(u32*)((char*)mgr + 0x119C + ((kind >> 5) << 2));
    u32 bit = 1u << (kind & 0x1F);
    return (bit & word) != 0;
}
