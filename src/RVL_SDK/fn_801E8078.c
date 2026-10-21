#pragma force_active on
typedef signed int s32;

extern s32 lbl_805A081C;
s32 OSDisableInterrupts();
void OSRestoreInterrupts();

s32 fn_801E8078(s32 arg0) {
    s32 old;

    old = lbl_805A081C;
    OSDisableInterrupts();
    lbl_805A081C = arg0;
    OSRestoreInterrupts();
    return old;
}
