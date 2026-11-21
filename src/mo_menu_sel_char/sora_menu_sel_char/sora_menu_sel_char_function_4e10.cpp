#include <gm/gm_global.h>
#pragma force_active on

struct SelCharInner {
    char pad0[0x100];
    u8 m_100;
    char pad101[3];
    s32 m_104;
};

struct SelCharMenu {
    char pad0[0x40];
    s32 m_40;
    s32 m_44[1];
    char pad48[0x5F8 - 0x48];
    s32 m_5f8;
    char pad5fc[0x60C - 0x5FC];
    SelCharInner* m_60c;
    char pad610[0x630 - 0x610];
    s32 m_630;
    char pad634[0x635 - 0x634];
    u8 m_635;
    u8 m_636;
    char pad637[0x644 - 0x637];
    s32 m_644;
    s32 m_648;
    s32 m_64c;
};

extern "C" {
void fn_10_5368(SelCharMenu*);
void fn_10_10758(SelCharMenu*);
void fn_10_D5F0(SelCharMenu*);
void fn_10_12210(s32);
void fn_10_62E4(SelCharMenu*);
void fn_10_1E1C(SelCharMenu*);
void fn_10_4A54(SelCharMenu*, s32, s32, s32);
void fn_10_B1CC(SelCharMenu*);
void fn_800D85A8(void*);
s32 fn_800D7A7C(void*, u8*, s32*);
void fn_800D5268(void*, s32, u8, u8);
extern void* g_muWifiInterfaceTask;
}

extern "C" void fn_10_4E10(SelCharMenu* arg0) {
    u8 sp8;
    s32 spC;
    u8 b;
    int i;
    int r0;
    int t;
    s32 state;

    arg0->m_64c = arg0->m_64c - 1;
    state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    if (state >= 0 && state < 4) r0 = 1; else r0 = 0;
    if (r0 != 0) {
        r0 = 0;
    } else {
        if (state >= 4 && state < 0xc) r0 = 1; else r0 = 0;
        if (r0 != 0) {
            r0 = 1;
        } else {
            if (state >= 0xc && state < 0x10) t = 1; else t = 0;
            r0 = 3;
            if (t != 0) r0 = 2;
        }
    }
    if (r0 == 0) goto block_38;
    {
        if (state >= 0 && state < 4) t = 1; else t = 0;
        if (t != 0) {
            t = 0;
        } else {
            if (state >= 4 && state < 0xc) t = 1; else t = 0;
            if (t != 0) {
                t = 1;
            } else {
                int r;
                if (state >= 0xc && state < 0x10) r = 1; else r = 0;
                t = 3;
                if (r != 0) t = 2;
            }
        }
        if (t != 1) goto block_39;
    }
block_38:
    r0 = 0;
    goto block_40;
block_39:
    r0 = 1;
block_40:
    if (r0 != 0) {
        fn_10_5368(arg0);
    }
    s32 r28 = arg0->m_630;
    if (r28 != 0) {
        fn_10_10758(arg0);
    }
    fn_10_D5F0(arg0);
    for (i = 0; i < arg0->m_648; i++) {
        fn_10_12210(arg0->m_44[i]);
    }
    switch (arg0->m_40) {
    case 0:
        if (r28 == 0) {
            fn_10_62E4(arg0);
        }
        return;
    case 1:
        arg0->m_5f8 = arg0->m_5f8 - 1;
        if (arg0->m_5f8 <= 0) {
            fn_10_1E1C(arg0);
            int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
            if (state >= 0 && state < 4) r0 = 1; else r0 = 0;
            if (r0 != 0) {
                r0 = 0;
            } else {
                if (state >= 4 && state < 0xc) r0 = 1; else r0 = 0;
                if (r0 != 0) {
                    r0 = 1;
                } else {
                    if (state >= 0xc && state < 0x10) t = 1; else t = 0;
                    r0 = 3;
                    if (t != 0) r0 = 2;
                }
            }
            if (r0 == 0) goto block_90;
            {
                if (state >= 0 && state < 4) t = 1; else t = 0;
                if (t != 0) {
                    t = 0;
                } else {
                    if (state >= 4 && state < 0xc) t = 1; else t = 0;
                    if (t != 0) {
                        t = 1;
                    } else {
                        int r;
                        if (state >= 0xc && state < 0x10) r = 1; else r = 0;
                        t = 3;
                        if (r != 0) t = 2;
                    }
                }
                if (t != 1) goto block_91;
            }
block_90:
            r0 = 0;
            goto block_92;
block_91:
            r0 = 1;
block_92:
            if (r0 != 0) {
                fn_800D85A8(g_muWifiInterfaceTask);
            }
            fn_10_4A54(arg0, 2, 0, 0);
        }
        break;
    case 3:
        arg0->m_40 = 4;
        return;
    case 6: {
        SelCharInner* p = arg0->m_60c;
        int v;
        if (p->m_104 != 3) {
            v = 0;
        } else {
            b = p->m_100;
            fn_10_B1CC(arg0);
            v = 2;
            if (b != 0) v = 1;
        }
        switch (v) {
        case 1:
            fn_10_4A54(arg0, 4, 0, 0);
            break;
        case 2:
            fn_10_4A54(arg0, 0, 0, 0);
            break;
        }
        break;
    }
    case 7: {
        SelCharInner* p = arg0->m_60c;
        int v;
        if (p->m_104 != 3) {
            v = 0;
        } else {
            b = p->m_100;
            fn_10_B1CC(arg0);
            v = 2;
            if (b != 0) v = 1;
        }
        if (v != 0) {
            if (arg0->m_644 == 3) {
                fn_10_4A54(arg0, 4, 0, 0);
            } else {
                fn_10_4A54(arg0, 5, 0, 0);
            }
        }
        break;
    }
    case 8: {
        int v;
        if (fn_800D7A7C(g_muWifiInterfaceTask, &sp8, &spC) != 0 && sp8 == arg0->m_635 && spC == arg0->m_636) {
            fn_10_B1CC(arg0);
            fn_10_4A54(arg0, 0, 0, 0);
            return;
        }
        {
            SelCharInner* p = arg0->m_60c;
            if (p->m_104 != 3) {
                v = 0;
            } else {
                b = p->m_100;
                fn_10_B1CC(arg0);
                v = 2;
                if (b != 0) v = 1;
            }
        }
        if (v != 0) {
            fn_800D5268(g_muWifiInterfaceTask, (v - 1) == 0, arg0->m_635, arg0->m_636);
            fn_10_4A54(arg0, 0, 0, 0);
        }
        return;
    }
    default:
        return;
    }
}
