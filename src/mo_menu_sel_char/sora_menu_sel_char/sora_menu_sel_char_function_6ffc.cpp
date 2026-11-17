#include <gm/gm_global.h>
#include <mu/selchar/mu_selchar.h>
#include <mu/wifi/mu_wifi_interface.h>
#include <snd/snd_system.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#pragma force_active on

extern "C" {
s32 fn_10_7618(void);
void fn_10_13068(void* a, s32 b);
void fn_10_C4C8(void* self, u8 v);
void fn_10_F35C(void* self);
void fn_10_10324(void* self);
void fn_10_FD00(void* self, s32 v);
s32 fn_10_B79C(void* self, s32 a, s32* b, s32* c, u8* d);
void fn_10_1046C(void* self, s32 idx, s32 a, u8 b);
void fn_10_105A0(void* self, s32 idx);
void fn_10_10398(void* self, s32 v);
void fn_10_771C(void* self, s32 slot);
void fn_10_95B8(void* self, s32 slot, s32 v);
s32 fn_10_12010(void* a, s32 b);
void fn_10_FBD4(void* self, s32 a, s32 b);
s32 fn_10_19508(void* a);
s32 fn_10_19604(void* a);
s32 fn_10_1BD70(void* a);
s32 fn_10_1B750(void* a);
void fn_10_16FB8(void* a);
void fn_10_17300(void* a);
void fn_10_17968(void* a);
void fn_10_17A7C(void* a);
void fn_10_13CAC(void* a);
void fn_800CA5F8(void* wifi, s32 a, s32 b);
void fn_10_1C470(void* a, s32 b, void* c);
void fn_10_1A5D8(void* a, void* b);
void fn_10_1A7AC(void* a, void* b);
void fn_10_8500(void* self, s32 slot, gfPadStatus* p);
void fn_10_7A94(void* self, s32 slot, gfPadStatus* p);
void fn_10_883C(void* self, s32 slot, gfPadStatus* p);
void playSE__9sndSystemF5SndIDiiii(void* self, s32 id, s32 a, s32 b, s32 c, s32 d);
void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void* self, s32 idx, gfPadStatus* p);
}

struct SelOut {
    u8 flag;
    s32 a;
    u8 b;
    s32 c;
    u8 d;
    s32 e;
};

struct SelVec2 {
    f32 x;
    f32 y;
};

struct SelF {
    f32 v;
    f32 w;
};

static inline SelVec2 selGetPos(u8* h) {
    SelVec2 r;
    r.y = *(f32*)(h + 0x94);
    r.x = *(f32*)(h + 0x90);
    return r;
}

extern "C" void fn_10_6FFC(muSelCharTask* self, s32 slot) {
    gfPadStatus sp48;
    SelOut out;
    s32 spC;
    s32 sp8;
    u8* hand;
    s32 bit;
    s32 n;
    s32 r27;
    u8* a2;
    u8* other;
    u8* area;
    u8* var3;
    s32 r3v;
    s32 idx;
    s32 state;
    s32 cls;
    s32 flag;

    area = (u8*)self->m_selCharPlayerAreas[slot];
    hand = *(u8**)(area + 0x1A8);
    if (*(s32*)area == 2) {
        s32 t = fn_10_7618();
        if (t >= 0) {
            fn_10_13068(area, t);
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1EEF, -1, 0, 0, -1);
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x26, -1, 0, 0, -1);
            *((u8*)self + 0x5FC) = 1;
            fn_10_C4C8(self, *((u8*)self + 0x5C8));
            s32 s0 = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
            s32 f0;
            if (s0 == 8 || s0 == 0xE) {
                f0 = 1;
            } else {
                f0 = 0;
            }
            if (f0 != 0) {
                fn_10_F35C(self);
            }
            fn_10_10324(self);
            fn_10_FD00(self, 3);
            s32 r = fn_10_B79C(self, *(s32*)((u8*)self + 0x5E0), &sp8, &spC, &out.flag);
            self->dispHighScore(4, r, sp8);
            if (out.flag != 0) {
                fn_10_1046C(self, 0, out.a, out.b);
                fn_10_1046C(self, 1, out.c, out.d);
            } else {
                fn_10_105A0(self, 0);
                fn_10_105A0(self, 1);
            }
            s32 s1 = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
            if (s1 != 7) {
                fn_10_10398(self, spC);
            }
            s32 s2 = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
            if (s2 == 7) {
                fn_10_10398(self, *(s32*)((u8*)self + 0x5E0));
            }
        }
    }
    idx = *(s32*)(area + 0x1DC);
    if (idx >= 0) {
        getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, idx, &sp48);
        s32 hs = *(s32*)(hand + 0xA4);
        if (hs != 0 && hs != 4) {
            fn_10_771C(self, slot);
            return;
        }
        SelF fx;
        SelVec2 vb;
        SelVec2 va;
        SelF fy;
        f32 ty = *(f32*)(hand + 0x94);
        f32 tx = *(f32*)(hand + 0x90);
        va.x = tx;
        va.y = ty;
        ((u32*)&vb)[0] = ((u32*)&va)[0];
        ((u32*)&vb)[1] = ((u32*)&va)[1];
        f32 by = vb.y;
        f32 bx = vb.x;
        fx.v = bx;
        fy.w = by;
        if (fn_10_1B750(hand) != 2 && *(s32*)(area + 0x1B4) == 0 && *(u8**)(hand + 0xA0) != 0 && slot == fn_10_1BD70(*(u8**)(hand + 0xA0))) {
            fn_10_95B8(self, slot, 1);
        }
        bit = (((u32*)&sp48)[3] >> 9) & 1;
        r27 = fn_10_19508(area);
        r3v = fn_10_19604(area);
        if ((r27 != 0 || r3v != 0) && (s32)((unsigned char*)g_GameGlobal->m_selCharData)[4] != 0x11) {
            if (*(u8**)(hand + 0xA0) != 0) {
                var3 = (u8*)self->m_selCharPlayerAreas[fn_10_1BD70(*(u8**)(hand + 0xA0))];
            } else {
                var3 = area;
            }
            if (*((u8*)self + 0x5C8) != 0) {
                n = *(s32*)(var3 + 0x1B0);
                a2 = (u8*)self->m_selCharPlayerAreas[n];
                if (r27 != 0) {
                    fn_10_16FB8(a2);
                } else {
                    fn_10_17300(a2);
                }
                state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
                if (state >= 0 && state < 4) {
                    cls = 1;
                } else {
                    cls = 0;
                }
                if (cls != 0) {
                    cls = 0;
                } else {
                    if (state >= 4 && state < 0xC) {
                        cls = 1;
                    } else {
                        cls = 0;
                    }
                    if (cls != 0) {
                        cls = 1;
                    } else {
                        if (state >= 0xC && state < 0x10) {
                            flag = 1;
                        } else {
                            flag = 0;
                        }
                        cls = 3;
                        if (flag != 0) {
                            cls = 2;
                        }
                    }
                }
                if (cls == 0) {
                    goto zero_lbl;
                }
                {
                    if (state >= 0 && state < 4) {
                        flag = 1;
                    } else {
                        flag = 0;
                    }
                    if (flag != 0) {
                        cls = 0;
                    } else {
                        if (state >= 4 && state < 0xC) {
                            flag = 1;
                        } else {
                            flag = 0;
                        }
                        if (flag != 0) {
                            cls = 1;
                        } else {
                            if (state >= 0xC && state < 0x10) {
                                flag = 1;
                            } else {
                                flag = 0;
                            }
                            cls = 3;
                            if (flag != 0) {
                                cls = 2;
                            }
                        }
                    }
                    if (cls != 1) {
                        goto one_lbl;
                    }
                }
zero_lbl:
                cls = 0;
                goto end_lbl;
one_lbl:
                cls = 1;
end_lbl:
                if (cls != 0) {
                    fn_800CA5F8(g_muWifiInterfaceTask, n, *(s32*)(a2 + 0x1C0));
                }
                fn_10_13CAC(a2);
            } else {
                a2 = (u8*)self->m_selCharPlayerAreas[*(s32*)(var3 + 0x1B0)];
                if (r27 != 0) {
                    fn_10_17968(a2);
                } else {
                    fn_10_17A7C(a2);
                }
                fn_10_13CAC(a2);
            }
            if (slot == 0 && (s32)((unsigned char*)g_GameGlobal->m_selCharData)[4] == 4) {
                s32 v1 = *(s32*)(area + 0x1BC);
                s32 v2 = fn_10_12010(area, *(s32*)(area + 0x1B8));
                fn_10_FBD4(self, v2, v1);
            }
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
        }
        if (bit != 0) {
            other = *(u8**)((u8*)self->m_selCharPlayerAreas[slot] + 0x1AC);
            if (*(s32*)(area + 0x1B4) != 0) {
                if (*(s32*)(hand + 0xA0) == 0 && *(s32*)(other + 0x10) == 0 && *(s32*)(hand + 0xA4) == 0) {
                    if (fn_10_1B750(hand) == 1) {
                        fn_10_1C470(other, 1, hand);
                        fn_10_1A5D8(hand, other);
                    } else {
                        fn_10_1A7AC(hand, other);
                        fn_10_1C470(other, 2, hand);
                    }
                    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
                }
                return;
            }
        }
        if (fn_10_1B750(hand) == 1) {
            fn_10_8500(self, slot, &sp48);
            return;
        }
        fn_10_7A94(self, slot, &sp48);
        fn_10_883C(self, slot, &sp48);
    }
}
