#include <gm/gm_global.h>
#pragma force_active on

struct SelCharSelf {
    char pad000[0x5C8];
    u8 m5C8;
    char pad5C9[0x5CC - 0x5C9];
    s32 m5CC;
    char pad5D0[0x5D1 - 0x5D0];
    u8 m5D1;
    char pad5D2[0x5E0 - 0x5D2];
    s32 m5E0;
    char pad5E4[0x600 - 0x5E4];
    s32 m600;
    s32 m604;
    char pad608[0x620 - 0x608];
    s32 m620;
    char pad624[0x640 - 0x624];
    u8 m640;
    char pad641[0x650 - 0x641];
    s32 m650;
};

extern "C" {
extern void* g_muWifiInterfaceTask;
u8 fn_10_1278(void);
void fn_10_1BBC(SelCharSelf* self);
u8 fn_800D4544(void* task);
void fn_800D82E8(void* task, u8* buf, int n);
s32 fn_800D8544(void* task);
}

extern "C" void fn_10_1290(SelCharSelf* self) {
    u8 buf[2];
    unsigned char* sel;
    int state;
    int result;
    int w;
    int r0_4;
    int r0_5;
    int cond;
    int flag;

    sel = (unsigned char*)g_GameGlobal->m_selCharData;
    if (g_muWifiInterfaceTask != 0) {
        fn_800D82E8(g_muWifiInterfaceTask, buf, 1);
    }

    state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    if (state >= 0 && state < 4) result = 1; else result = 0;
    if (result != 0) {
        result = 0;
    } else {
        if (state >= 4 && state < 0xc) result = 1; else result = 0;
        if (result != 0) {
            result = 1;
        } else {
            if (state >= 0xc && state < 0x10) r0_4 = 1; else r0_4 = 0;
            result = 3;
            if (r0_4 != 0) result = 2;
        }
    }
    if (result == 2) {
        u8 v2;
        u8 cur2;
        unsigned char* task2 = (unsigned char*)g_muWifiInterfaceTask;
        int bit2 = (task2[0xFCA] >> 5) & 1;
        if (!bit2) {
            v2 = fn_10_1278();
            if (v2 == 0xFF) v2 = 4;
            cur2 = fn_800D4544(task2);
            bit2 = (cur2 == v2);
        }
        if (bit2 == 0) {
            if (fn_800D8544(g_muWifiInterfaceTask) == 1) self->m5C8 = 1; else self->m5C8 = 0;
            goto L1414;
        }
    }
    if (sel[0x33] == 1) self->m5C8 = 1; else self->m5C8 = 0;
L1414:

    {
        int state3 = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
        if (state3 >= 0 && state3 < 4) result = 1; else result = 0;
        if (result != 0) {
            result = 0;
        } else {
            if (state3 >= 4 && state3 < 0xc) result = 1; else result = 0;
            if (result != 0) {
                result = 1;
            } else {
                if (state3 >= 0xc && state3 < 0x10) r0_4 = 1; else r0_4 = 0;
                result = 3;
                if (r0_4 != 0) result = 2;
            }
        }
        if (result == 0) goto c3f;
        if (state3 >= 0 && state3 < 4) w = 1; else w = 0;
        if (w != 0) {
            w = 0;
        } else {
            if (state3 >= 4 && state3 < 0xc) w = 1; else w = 0;
            if (w != 0) {
                w = 1;
            } else {
                if (state3 >= 0xc && state3 < 0x10) r0_5 = 1; else r0_5 = 0;
                w = 3;
                if (r0_5 != 0) w = 2;
            }
        }
        if (w != 1) goto c3g;
c3f:
        cond = 0;
        goto c3e;
c3g:
        cond = 1;
c3e:;
        if (cond != 0) {
            unsigned char* task3 = (unsigned char*)g_muWifiInterfaceTask;
            int bit3 = (task3[0xFCA] >> 5) & 1;
            if (!bit3) {
                u8 v3 = fn_10_1278();
                if (v3 == 0xFF) v3 = 4;
                u8 cur3 = fn_800D4544(task3);
                bit3 = (cur3 == v3);
            }
            if (bit3 == 0) {
                self->m5CC = (buf[0] >> 4) & 3;
                goto L15C4;
            }
        }
        self->m5CC = ((unsigned char*)g_GameGlobal->m_setRule)[5];
L15C4:;
    }
    fn_10_1BBC(self);

    {
        int state4 = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
        if (state4 >= 0 && state4 < 4) result = 1; else result = 0;
        if (result != 0) {
            result = 0;
        } else {
            if (state4 >= 4 && state4 < 0xc) result = 1; else result = 0;
            if (result != 0) {
                result = 1;
            } else {
                if (state4 >= 0xc && state4 < 0x10) r0_4 = 1; else r0_4 = 0;
                result = 3;
                if (r0_4 != 0) result = 2;
            }
        }
        if (result == 0) goto c4f;
        if (state4 >= 0 && state4 < 4) w = 1; else w = 0;
        if (w != 0) {
            w = 0;
        } else {
            if (state4 >= 4 && state4 < 0xc) w = 1; else w = 0;
            if (w != 0) {
                w = 1;
            } else {
                if (state4 >= 0xc && state4 < 0x10) r0_5 = 1; else r0_5 = 0;
                w = 3;
                if (r0_5 != 0) w = 2;
            }
        }
        if (w != 1) goto c4g;
c4f:
        cond = 0;
        goto c4e;
c4g:
        cond = 1;
c4e:;
        if (cond == 0 && self->m5D1 != 0) self->m5CC = 0;
    }

    {
        int state5 = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
        if (state5 == 8 || state5 == 0xe) flag = 1; else flag = 0;
        if (flag != 0) {
            if (state5 >= 0 && state5 < 4) result = 1; else result = 0;
            if (result != 0) {
                result = 0;
            } else {
                if (state5 >= 4 && state5 < 0xc) result = 1; else result = 0;
                if (result != 0) {
                    result = 1;
                } else {
                    if (state5 >= 0xc && state5 < 0x10) r0_4 = 1; else r0_4 = 0;
                    result = 3;
                    if (r0_4 != 0) result = 2;
                }
            }
            if (result == 0) goto c5f;
            if (state5 >= 0 && state5 < 4) w = 1; else w = 0;
            if (w != 0) {
                w = 0;
            } else {
                if (state5 >= 4 && state5 < 0xc) w = 1; else w = 0;
                if (w != 0) {
                    w = 1;
                } else {
                    if (state5 >= 0xc && state5 < 0x10) r0_5 = 1; else r0_5 = 0;
                    w = 3;
                    if (r0_5 != 0) w = 2;
                }
            }
            if (w != 1) goto c5g;
c5f:
            cond = 0;
            goto c5e;
c5g:
            cond = 1;
c5e:;
            if (cond != 0) {
                unsigned char* task5 = (unsigned char*)g_muWifiInterfaceTask;
                int bit5 = (task5[0xFCA] >> 5) & 1;
                if (!bit5) {
                    u8 v5 = fn_10_1278();
                    if (v5 == 0xFF) v5 = 4;
                    u8 cur5 = fn_800D4544(task5);
                    bit5 = (cur5 == v5);
                }
                if (bit5 == 0) {
                    self->m600 = (buf[1] >> 4) & 1;
                    goto L18E4;
                }
            }
            self->m600 = sel[1];
        }
L18E4:;
    }

    {
        int state6 = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
        if (state6 == 9 || state6 == 0xd) flag = 1; else flag = 0;
        if (flag != 0) {
            if (state6 >= 0 && state6 < 4) result = 1; else result = 0;
            if (result != 0) {
                result = 0;
            } else {
                if (state6 >= 4 && state6 < 0xc) result = 1; else result = 0;
                if (result != 0) {
                    result = 1;
                } else {
                    if (state6 >= 0xc && state6 < 0x10) r0_4 = 1; else r0_4 = 0;
                    result = 3;
                    if (r0_4 != 0) result = 2;
                }
            }
            if (result == 0) goto c6f;
            if (state6 >= 0 && state6 < 4) w = 1; else w = 0;
            if (w != 0) {
                w = 0;
            } else {
                if (state6 >= 4 && state6 < 0xc) w = 1; else w = 0;
                if (w != 0) {
                    w = 1;
                } else {
                    if (state6 >= 0xc && state6 < 0x10) r0_5 = 1; else r0_5 = 0;
                    w = 3;
                    if (r0_5 != 0) w = 2;
                }
            }
            if (w != 1) goto c6g;
c6f:
            cond = 0;
            goto c6e;
c6g:
            cond = 1;
c6e:;
            if (cond != 0) {
                unsigned char* task6 = (unsigned char*)g_muWifiInterfaceTask;
                int bit6 = (task6[0xFCA] >> 5) & 1;
                if (!bit6) {
                    u8 v6 = fn_10_1278();
                    if (v6 == 0xFF) v6 = 4;
                    u8 cur6 = fn_800D4544(task6);
                    bit6 = (cur6 == v6);
                }
                if (bit6 == 0) {
                    self->m604 = (buf[1] >> 5) & 7;
                    goto L1AAC;
                }
            }
            self->m604 = sel[2];
        }
L1AAC:;
    }

    state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    if (state == 1) self->m620 = sel[3];

    state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    if (state == 0xf) {
        unsigned char* task8 = (unsigned char*)g_muWifiInterfaceTask;
        int bit8 = (task8[0xFCA] >> 5) & 1;
        if (!bit8) {
            u8 v8 = fn_10_1278();
            if (v8 == 0xFF) v8 = 4;
            u8 cur8 = fn_800D4544(task8);
            bit8 = (cur8 == v8);
        }
        if (bit8 == 0) {
            self->m5E0 = (buf[1] >> 1) & 7;
            goto L1B50;
        }
    }
    self->m5E0 = (sel[0x2e] >> 5) & 7;
L1B50:

    state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    if (state == 0xc) {
        if (sel[6] != 0) self->m640 = 1;
    }
    self->m650 = sel[8];
}
