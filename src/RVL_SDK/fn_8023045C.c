#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern u8 lbl_804FD448[];
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32 level);

s32 fn_8023045C(u32 arg0, u32 arg1) {
    u8 idx;
    s32 level;

    if (arg0 >= 8) {
        return 1;
    }
    level = OSDisableInterrupts();
    idx = lbl_804FD448[0];
    *(s32 *)(lbl_804FD448 + idx * 4 + 4) = level;
    lbl_804FD448[0]++;
    *(u16 *)(lbl_804FD448 + 0x28808 + (u8)arg0 * 2) |= arg1;
    idx = lbl_804FD448[0] - 1;
    lbl_804FD448[0] = idx;
    OSRestoreInterrupts(*(s32 *)(lbl_804FD448 + idx * 4 + 4));
    return 0;
}
