#pragma force_active on
#include <types.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>

struct ChrRes {
    virtual ~ChrRes();
    virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
    virtual void f5(); virtual void f6(); virtual void f7();
    virtual void SetFrame(float);
};
struct AnimLike { char pad[0xC]; ChrRes* chr; };
struct ObjLike { char pad[0x14]; AnimLike* anim; };

struct Menu {
    u8 pad0[0x100];
    void* obj100;
    u8 pad1[0x198 - 0x104];
    void* msg198;
    u8 pad2[0x1D4 - 0x19C];
    s32 arrB[11];
    s32 arrA[11];
    u8 pad3[0x1784 - 0x22C];
    s32 cursor;
    s32 f1788;
    s32 f178C;
    u8 f1790;
    s32 f1794;
    s32 f1798;
    s32 f179C;
};

extern "C" {
extern gfPadSystem* g_gfPadSystem;
extern u8* g_gfApplication;
extern void* g_sndSystem;
extern u8* lbl_805A01D8;
extern const float lbl_2_rodata_1630;
extern const float lbl_2_rodata_1634;
extern s32 lbl_2_data_47E8[];
extern char lbl_2_data_4858[];
extern char lbl_2_data_4998[];

int getSysPadStatus__11gfPadSystemFiP11gfPadStatus(gfPadSystem*, int, gfPadStatus*);
void fn_800B9984(void*);
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, s32, s32, u16);
void* getData__9gfArchiveF11ARCNodeTypeiPiUs(void*, s32, s32, s32*, u16);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void setMsgData__5MuMsgFPv(void*, void*);
void fn_2_36A3C(void*, void*, s32);
void fn_2_376D0(void*);
void fn_2_37AB4(void*, void*);
void fn_2_37F28(void*);
void fn_800288A4(void*);
void fn_800B3C5C(void*, void*, s32);
void endKeepScreen__17gfKeepFrameBufferFv(void*);
void startKeepScreen__17gfKeepFrameBufferFv(void*);
void playBGM__9sndSystemFiUlb(void*, s32, u32, s32);
void playSE__9sndSystemF5SndIDiiii(void*, s32, s32, s32, s32, s32);
void printf__5MuMsgFUlPCce(void*, u32, const char*, ...);
float getFrame__16gfModelAnimationFd(void*);
void fn_800B7AA4(void*, s32, float);

void fn_2_36FBC(u8* self) {
    gfPadStatus sp50;
    s32 sp8;
    s32 p30 = 0, p29 = 0, p28 = 0, i;
    for (i = 0; i < 8; i++) {
        getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, i, &sp50);
        switch (sp50.m_controllerType) {
        case 2:
            p30 = p30 || (sp50.m_buttonsPressedThisFrame.bits & 0x400000);
            p29 = p29 || (sp50.m_buttonsPressedThisFrame.bits & 0x200000);
            p28 = p28 || (sp50.m_buttonsPressedThisFrame.bits & 0x10000);
            break;
        case 3:
            p30 = p30 || (sp50.m_buttonsPressedThisFrame.bits & 0x10000);
            p29 = p29 || (sp50.m_buttonsPressedThisFrame.bits & 0x20000);
            p28 = p28 || (sp50.m_buttonsPressedThisFrame.bits & 0x200);
            break;
        default:
            p30 = p30 || (sp50.m_buttonsPressedThisFrame.bits & 0x840);
            p29 = p29 || (sp50.m_buttonsPressedThisFrame.bits & 0x420);
            p28 = p28 || (sp50.m_buttonsPressedThisFrame.bits & 0x200);
            break;
        }
    }
    fn_800B9984(self + 0x4C);
    s32 buttons = *(s32*)(self + 0x5C);
    s32 v4 = 1;
    if (p30 == 0 && !(buttons & 1)) v4 = 0;
    s32 v5 = 1;
    if (p29 == 0 && !(buttons & 2)) v5 = 0;
    switch (*(s32*)(self + 0x44)) {
    case 0: {
        if (self[0x2849] == 0) {
            if (*(u8*)(*(u8**)(self + 0x40) + 0x1A4) == 0) return;
            self[0x2849] = 1;
        }
        if (self[0x2848] == 0) {
            if (!((*(u8*)(*(u8**)(self + 0x2844) + 9) >> 7) & 1)) return;
            self[0x2848] = 1;
        }
        void* d = getData__9gfArchiveF11ARCNodeTypeiUs(*(void**)(self + 0x2844), 2, 0, 0xFFFE);
        *(void**)(self + 0x19C) = d;
        Init__Q34nw4r3g3d7ResFileFPv(self + 0x19C);
        setMsgData__5MuMsgFPv(*(void**)(self + 0x198), getData__9gfArchiveF11ARCNodeTypeiUs(*(void**)(self + 0x2844), 1, 0, 0xFFFE));
        fn_2_36A3C(self + 0x1A0, getData__9gfArchiveF11ARCNodeTypeiPiUs(*(void**)(self + 0x2844), 1, 1, &sp8, 0xFFFE), sp8);
        *(s32*)(self + 0x44) = 1;
        fn_2_37F28(self);
        endKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
        playBGM__9sndSystemFiUlb(g_sndSystem, 0x270C, 0, 1);
        *(s32*)(lbl_805A01D8 + 0x174) = 0x2D;
        break;
    }
    case 1: {
        if (lbl_2_rodata_1630 == getFrame__16gfModelAnimationFd(((ObjLike*)*(u8**)(self + 0xFC))->anim)) {
            *(s32*)(self + 0x48) = 0;
            *(s32*)(self + 0x44) = 2;
            AnimLike* a = (*(ObjLike**)(self + 0xFC))->anim;
            a->chr->SetFrame(lbl_2_rodata_1634);
            fn_800B3C5C(*(void**)(self + 0xFC), lbl_2_data_4858 + 0x14, 1);
        }
        break;
    }
    case 2: {
        if (p28 != 0) {
            *(s32*)(self + 0x44) = 3;
            startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 2, -1, 0, 0, -1);
        } else if (v4 != 0) {
            Menu* m = (Menu*)self;
            s32 n = m->cursor;
            if (n > 0) {
                m->cursor = n - 1;
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
                if (m->cursor == 2) m->cursor = 1;
                s32 idx = m->cursor;
                m->f1788 = 0;
                m->f178C = 0;
                m->f1790 = 0;
                m->f1794 = m->arrA[idx];
                m->f1798 = m->arrB[idx];
                m->f179C = 0;
                fn_800B7AA4(m->obj100, 7, (float)(idx + 1));
                printf__5MuMsgFUlPCce(m->msg198, 0, lbl_2_data_4998, *(s32*)((char*)lbl_2_data_47E8 + (m->cursor + 0xB) * 4));
                fn_2_376D0(self);
            }
        } else if (v5 != 0) {
            Menu* m = (Menu*)self;
            s32 n = m->cursor;
            if (n < 0xA) {
                m->cursor = n + 1;
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
                if (m->cursor == 2) m->cursor = 3;
                s32 idx = m->cursor;
                m->f1788 = 0;
                m->f178C = 0;
                m->f1790 = 0;
                m->f1794 = m->arrA[idx];
                m->f1798 = m->arrB[idx];
                m->f179C = 0;
                fn_800B7AA4(m->obj100, 7, (float)(idx + 1));
                printf__5MuMsgFUlPCce(m->msg198, 0, lbl_2_data_4998, *(s32*)((char*)lbl_2_data_47E8 + (m->cursor + 0xB) * 4));
                fn_2_376D0(self);
            }
        } else {
            gfPadStatus sp10;
            getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, 0xF0, &sp10);
            fn_800288A4(&sp10);
            fn_2_37AB4(self, &sp10);
        }
        break;
    }
    }
    *(s32*)(self + 0x48) += 1;
}
}
