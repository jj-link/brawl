#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_80192744(u8 **arg0, u32 *arg1, u8 *arg2) {
    if (arg1 != 0) {
        u8 *inner = *arg0;
        u32 offset = *(u32 *)(inner + 8);
        u32 result;
        if (offset != 0)
            result = (u32)inner + offset;
        else
            result = 0;
        *arg1 = result;
    }
    if (arg2 != 0) {
        *arg2 = *(*arg0 + 0x1d);
    }
}
