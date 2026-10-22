#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    unsigned char buf[0x40];
    u32 offset;
    s32 enabled;
    s32 locked;
    s32 sync;
} SramCB;

typedef struct {
    unsigned char pad[0x28];
    u16 val;
} SramEx;

extern SramCB lbl_804DD500;
extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
extern void fn_801D76BC(void *, u32);
extern s32 fn_801DFB80(s32, u32);
extern s32 fn_801E42E4(s32, void *, s32, s32, s32);
extern s32 fn_801E4604(s32, void *, s32, s32, s32);
extern s32 fn_801E46FC(s32);
extern s32 fn_801E4D4C(s32, s32, s32);
extern s32 fn_801E4E7C(s32);
extern s32 fn_801E54E0(s32, s32, s32);
extern void fn_801E55DC(s32);

static s32 ReadSram(void *buffer) {
    s32 err;
    u32 cmd;
    fn_801D76BC(buffer, 0x40);
    if (fn_801E54E0(0, 1, 0) == 0) return 0;
    if (fn_801E4D4C(0, 1, 3) == 0) {
        fn_801E55DC(0);
        return 0;
    }
    cmd = 0x20000100;
    err = 0;
    err |= fn_801E42E4(0, &cmd, 4, 1, 0) == 0;
    err |= fn_801E46FC(0) == 0;
    err |= fn_801E4604(0, buffer, 0x40, 0, 0) == 0;
    err |= fn_801E46FC(0) == 0;
    err |= fn_801E4E7C(0) == 0;
    fn_801E55DC(0);
    return !err;
}

static SramEx *LockSram(u32 offset) {
    s32 enabled = OSDisableInterrupts();
    if (lbl_804DD500.locked != 0) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    lbl_804DD500.enabled = enabled;
    lbl_804DD500.locked = 1;
    return (SramEx *)(lbl_804DD500.buf + offset);
}

static void SetVal(u16 v) {
    SramEx *p = LockSram(0x14);
    if (v == p->val) {
        fn_801DFB80(0, 0x14);
        return;
    }
    p->val = v;
    fn_801DFB80(1, 0x14);
}

static u16 GetVal(void) {
    SramEx *p = LockSram(0x14);
    u16 v = p->val;
    fn_801DFB80(0, 0x14);
    return v;
}

void fn_801DF980(void) {
    u32 v;
    lbl_804DD500.enabled = 0;
    lbl_804DD500.locked = 0;
    lbl_804DD500.sync = ReadSram(lbl_804DD500.buf);
    lbl_804DD500.offset = 0x40;
    v = GetVal();
    if ((v & 0x7C00) == 0x5000 || (v & 0xC0) == 0xC0) {
        v = 0;
    }
    SetVal((u16)v);
}
