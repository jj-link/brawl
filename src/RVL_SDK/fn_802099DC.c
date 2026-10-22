#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

struct Node {
    u32 f0;
    u32 f4;
};

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32 level);
extern struct Node *lbl_805A0B94;
extern void *lbl_805A0B84;
extern u32 lbl_805A0B80;

void *fn_802099DC(void *arg0) {
    u32 level;
    u32 r;
    u16 v;
    u16 *hw;
    int mask;

    level = OSDisableInterrupts();
    if (lbl_805A0B94 == (struct Node *)arg0) {
        lbl_805A0B84 = arg0;
        lbl_805A0B80 = 1;
        OSRestoreInterrupts(level);
        return arg0;
    }
    if (((struct Node *)arg0)->f4 < lbl_805A0B94->f4) {
        lbl_805A0B84 = arg0;
        lbl_805A0B80 = 1;
        if (lbl_805A0B94->f0 == 1) {
            r = OSDisableInterrupts();
            hw = (u16 *)0xCC00500A;
            mask = -0xA9;
            v = *hw;
            *hw = (u16)((v & mask) | 2);
            OSRestoreInterrupts(r);
        }
        OSRestoreInterrupts(level);
        return arg0;
    }
    OSRestoreInterrupts(level);
    return 0;
}
