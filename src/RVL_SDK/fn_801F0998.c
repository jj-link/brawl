#pragma force_active on
#pragma peephole off

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u8 pad[0x5FC];
    s32 dirtyState;
} GXData;

extern GXData* const __GXData;
extern u8 lbl_805A08C0;

extern s32 OSDisableInterrupts(void);
extern s32 OSRestoreInterrupts(s32);
extern void fn_801F0E10(s32);
extern void fn_801D50A0(void);

void GXSetDrawDone(void) {
    s32 level = OSDisableInterrupts();

    *(u8*)0xCC008000 = 0x61;
    *(u32*)0xCC008000 = 0x45000002;

    if (__GXData->dirtyState != 0) {
        fn_801F0E10(level);
    }

    *(u32*)0xCC008000 = 0;
    *(u32*)0xCC008000 = 0;
    *(u32*)0xCC008000 = 0;
    *(u32*)0xCC008000 = 0;
    *(u32*)0xCC008000 = 0;
    *(u32*)0xCC008000 = 0;
    *(u32*)0xCC008000 = 0;
    *(u32*)0xCC008000 = 0;

    fn_801D50A0();
    lbl_805A08C0 = 0;
    OSRestoreInterrupts(level);
}
