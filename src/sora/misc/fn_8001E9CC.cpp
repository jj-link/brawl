#include <types.h>
#include <revolution/GX/GXTypes.h>
#pragma force_active on

extern "C" {
extern u8 lbl_805A14C0;
extern u8 lbl_805A14C1;
extern char lbl_804213F0[];
int fn_803C34CC(u8*, u8);
void fn_8001B9E8(int);
void OSReport(const char*, ...);
}

extern "C" void fn_8001E9CC(void* arg0) {
    u8 buf[2];
    s8 offset;
    int result;
    int status;
    u32* field = (u32*)((u8*)arg0 + 0x14);

    buf[0] = lbl_805A14C0;
    buf[1] = lbl_805A14C1;
    offset = (s8)((u8*)arg0)[0x15];
    buf[0] = lbl_805A14C0 + offset;

    result = fn_803C34CC(buf, lbl_805A14C0);
    if (result != 0) {
        OSReport(lbl_804213F0, buf, result);
        fn_8001B9E8(result);
        status = 0xB;
    } else {
        status = 0;
    }
    *field = GX_BITSET(*field, 0, 8, status);
}
