#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern char lbl_8047FE30[];
extern u8 lbl_805A0D30;
extern char lbl_80529AC8[];

void fn_802319FC(u32, void *, void *);
void fn_802322F4(u32, u8, void *);
void fn_80232328(u32, u8, void *);
void fn_80232780(void *);
void *memcpy(void *, void *, u32);

void fn_8023673C(u8 *arg0, u8 *arg1) {
    void *sp8;
    u8 buf[12];
    u8 *r30;
    u16 op;
    char *base;
    char *var5;

    base = lbl_8047FE30;
    sp8 = *(void **)(arg1 + 0xc);
    r30 = (u8 *)sp8 + *(u16 *)((u8 *)sp8 + 4);
    if (lbl_805A0D30 >= 5) {
        switch (*(u16 *)(arg0 + 0x10)) {
        case 4: var5 = base + 0x16C; break;
        case 5: var5 = base + 0x180; break;
        case 6: var5 = base + 0x194; break;
        case 7: var5 = base + 0x1AC; break;
        case 8: var5 = base + 0x1C4; break;
        case 9: var5 = base + 0x1D8; break;
        case 2: var5 = base + 0x1F0; break;
        default: var5 = base + 0x200; break;
        }
        fn_802319FC(0x504, base + 0x2A8, var5);
    }
    buf[0] = 0;
    buf[1] = arg0[0x16];
    op = *(u16 *)(arg0 + 0x10);
    switch (op) {
    case 8:
        buf[2] = r30[8];
        break;
    case 4:
        memcpy(&buf[2], sp8, 8);
        break;
    case 6:
        buf[2] = r30[8];
        break;
    default:
    case 7:
    case 9:
    case 5:
        if (lbl_805A0D30 >= 5) {
            switch (op) {
            case 4: var5 = base + 0x16C; break;
            case 5: var5 = base + 0x180; break;
            case 6: var5 = base + 0x194; break;
            case 7: var5 = base + 0x1AC; break;
            case 8: var5 = base + 0x1C4; break;
            case 9: var5 = base + 0x1D8; break;
            case 2: var5 = base + 0x1F0; break;
            default: var5 = base + 0x200; break;
            }
            fn_802319FC(0x504, base + 0x2CC, var5);
        }
        break;
    }
    fn_80232328(0x17, arg0[0x15], arg0 + 8);
    fn_802322F4(0x17, arg0[0x15], arg0 + 8);
    ((void (*)(u16, void *, void *))(*(void **)(lbl_80529AC8 + 0x224)))(
        *(u16 *)(arg0 + 0x10), buf, lbl_80529AC8);
    *(u16 *)(arg0 + 0x10) = 0;
    fn_80232780(&sp8);
}
