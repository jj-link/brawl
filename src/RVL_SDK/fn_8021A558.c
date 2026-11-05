#pragma force_active on
typedef int s32;
typedef unsigned int u32;
extern void *lbl_804F6810[];
extern s32 lbl_805A0C74;
u32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);

void fn_8021A558(s32 arg0, s32 arg1) {
    unsigned char *obj;
    s32 enabled;

    obj = (unsigned char *)lbl_804F6810[arg0];
    enabled = OSDisableInterrupts();
    if (*(s32 *)(obj + 0x8BC) == -1) {
        OSRestoreInterrupts(enabled);
        return;
    }
    if (lbl_805A0C74 == 0) {
        if (arg1 != 0 || *(s32 *)(obj + 0x8D4) != 1) {
            OSRestoreInterrupts(enabled);
            return;
        }
    }
    if ((arg1 == 0 && *(s32 *)(obj + 0x8D4) == 0) || ((u32)arg1 == 1 && *(s32 *)(obj + 0x8D4) == 1)) {
        OSRestoreInterrupts(enabled);
        return;
    }
    *(s32 *)(obj + 0x8D4) = arg1 != 0;
    *(s32 *)(obj + 0x8D0) = 1;
    OSRestoreInterrupts(enabled);
}
