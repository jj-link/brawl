#include <revolution/types.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct {
    u32 a;
    u32 b;
    u16 c;
    u16 pad;
    u32 d;
    u32 e;
} Ent14;

extern void *memset(void *, int, unsigned long);
extern s64 fn_801E1B54(void);
extern void *lbl_804F6810[];
extern Ent14 lbl_804F9F70[];
extern u8 lbl_805A0C58;
extern u8 lbl_805A0C5C;

void fn_8021887C(int arg0)
{
    unsigned char *base;
    BOOL enabled;

    base = lbl_804F6810[arg0];
    *(u8 *)(base + 0x8C8) = 0;
    *(u32 *)(base + 0x850) = 0;
    *(u32 *)(base + 0x8D4) = 0;
    *(u32 *)(base + 0x89C) = 0;
    *(u32 *)(base + 0x8A0) = 0;
    *(u32 *)(base + 0x8A8) = 0;
    *(u32 *)(base + 0x8AC) = 0;
    *(u32 *)(base + 0x8B0) = 0;
    *(u32 *)(base + 0x8B4) = 0;
    *(u32 *)(base + 0x8B8) = 0;
    *(s32 *)(base + 0x8BC) = -1;
    *(u8 *)(base + 0x8C1) = 0xFD;
    *(u8 *)(base + 0x8C2) = 0;
    *(u8 *)(base + 0x911) = 0;
    *(u16 *)(base + 0x912) = 0;
    *(u8 *)(base + 0x8C0) = 0;
    *(u8 *)(base + 0x8CA) = 0xC;
    *(u8 *)(base + 0x8CB) = 0;
    *(u8 *)(base + 0x8CC) = 0;
    *(u16 *)(base + 0x8F8) = 0;
    *(u16 *)(base + 0x8FA) = 0;
    *(u16 *)(base + 0x8FC) = 0;
    *(u16 *)(base + 0x8FE) = 0;
    *(u16 *)(base + 0x900) = 0;
    *(u16 *)(base + 0x902) = 0;
    *(s64 *)(base + 0x8F0) = fn_801E1B54();
    *(s64 *)(base + 0x908) = fn_801E1B54();
    *(u8 *)(base + 0x910) = 0;
    *(u8 *)(base + 0x8C9) = 0;
    *(u32 *)(base + 0x8C4) = 0;
    *(u32 *)(base + 0x974) = 0;
    *(u32 *)(base + 0x978) = 0;
    *(u16 *)(base + 0x980) = 0;
    *(u32 *)(base + 0x97C) = 0;
    *(s8 *)(base + 0x8C3) = -1;
    *(u32 *)(base + 0x8D8) = 0;
    *(u32 *)(base + 0x8DC) = 0;
    *(u32 *)(base + 0x8E0) = 0;
    *(u8 *)(base + 0x8CD) = 1;
    *(u8 *)(base + 0x8CE) = 0;
    *(u8 *)(base + 0x8CF) = 0;
    *(u8 *)(base + 0x982) = 0;
    *(u8 *)(base + 0x983) = 0;
    *(u16 *)(base + 0x984) = 0;
    *(u8 *)(base + 0x986) = 1;
    *(u8 *)(base + 0x98C) = 0;
    *(u32 *)(base + 0x988) = 0;
    *(u8 *)(base + 0x98E) = 0;
    memset(base + 0x838, 0, 0x18);
    memset(base + 0x934, 0, 0x40);
    memset(base + 0xA0, 0, 0xC0);
    memset(base + 0x40, 0, 0x60);
    memset(base + 0x854, 0, 0x2E);
    memset(base + 0x882, 0, 0x1A);
    memset(base + 0x914, 0, 0x10);
    memset(base + 0x924, 0, 8);
    memset(base + 0x92C, 0, 8);
    memset(base, 0, 0x38);
    *(s32 *)(base + 0x38) = -1;
    *(s32 *)(base + 0x3C) = -1;
    *(void **)(base + 0x164) = base + 0x16C;
    *(s32 *)(base + 0x168) = 0x18;
    *(void **)(base + 0x5F0) = base + 0x5F8;
    *(s32 *)(base + 0x5F4) = 0xC;
    enabled = OSDisableInterrupts();
    *(u8 *)(base + 0x160) = 0;
    *(u8 *)(base + 0x161) = 0;
    memset(*(void **)(base + 0x164), 0, *(s32 *)(base + 0x168) * 0x30);
    OSRestoreInterrupts(enabled);
    enabled = OSDisableInterrupts();
    *(u8 *)(base + 0x5EC) = 0;
    *(u8 *)(base + 0x5ED) = 0;
    memset(*(void **)(base + 0x5F0), 0, *(s32 *)(base + 0x5F4) * 0x30);
    OSRestoreInterrupts(enabled);
    lbl_804F9F70[arg0].a = 0;
    lbl_804F9F70[arg0].b = 0;
    lbl_804F9F70[arg0].c = 0;
    lbl_804F9F70[arg0].d = 0;
    lbl_804F9F70[arg0].e = 0;
    *((u8 *)&lbl_805A0C58 + arg0) = 0;
    *((u8 *)&lbl_805A0C5C + arg0) = 0;
}
