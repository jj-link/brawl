#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

extern "C" s32 fn_27_11FA48(u8* base, s32 target) {
    s32 j;
    u8* p;
    u32 off;
    u8* e;
    s32 count = 0;
    u32 i = 0;

    for (; i < 8; i++) {
        off = (u8)i * 0x30;
        e = base + off;
        if (*(s32*)(e + 0x338) == -1) {
            continue;
        }

        u32 v;
        p = e;
        j = 0;
        for (s32 k = 0; k < 4; k++) {
            if (*(u32*)(p + 0x310) != 0xffff) {
                v = *(u32*)(e + j * 8 + 0x310);
                goto found;
            }
            p += 8;
            j++;
        }
        v = 0xffff;

    found:
        if (v != 0xffff) {
            if (target == count) {
                return *(s32*)((u32)base + off + 0x330);
            }
            count++;
        }
    }
    return -1;
}
