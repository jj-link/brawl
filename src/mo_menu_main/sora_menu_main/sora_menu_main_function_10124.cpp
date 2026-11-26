#include <gf/gf_pad_system.h>
#include <snd/snd_system.h>
#pragma force_active on

struct Sub {
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13(void*, void*);
};

struct Entry {
    float val;
    int a;
    int b;
};

struct MenuData {
    char pad0[0x314];
    Entry entries[1000];
    unsigned int start[1000];
    unsigned int count[1000];
};

extern "C" {
void fn_2_12C6C(void* self, gfPadStatus* out);
void fn_2_114FC(void* self);
void fn_2_116AC(void* self);
void fn_2_117BC(void* self);
int fn_2_10600(void* self, int idx);
void fn_800B3C5C(void* model, const void* info, int flag);
extern char lbl_2_data_1438[];
extern char lbl_2_data_14D0[];
}

#define OFF_U32(p, o) (*(unsigned int*)((char*)(p) + (o)))
#define OFF_PTR(p, o) (*(void**)((char*)(p) + (o)))
#define OFF_S32(p, o) (*(int*)((char*)(p) + (o)))

static inline unsigned int bestIndex(char* a, unsigned int n) {
    MenuData* m = (MenuData*)a;
    unsigned int s = m->start[n];
    int i;
    unsigned int idx;
    int j;
    unsigned int off;
    unsigned long base;
    unsigned int total;
    float best;
    idx = 0;
    i = 1;
    j = 12;
    off = s * 12;
    total = m->count[n] + (&m->count[1])[n];
    base = (unsigned long)a + off;
    best = *(float*)(a + off + 0x314);
    for (; i < total; j += 12, i++) {
        if (best < *(float*)(j + base + 0x314)) {
            best = *(float*)(j + base + 0x314);
            idx = i;
        }
    }
    return idx;
}

static inline void stepDown(char* a) {
    unsigned int n = OFF_U32(a, 0x108) - 2;
    OFF_U32(a, 0x108) = n;
    OFF_S32(a, 0x54) = bestIndex(a, n);
}

static inline void playWithModel(char* a, unsigned int modelOff, const void* info, unsigned int state) {
    void* o = OFF_PTR(OFF_PTR(a, 0x40), 0x48);
    ((Sub*)o)->f13(OFF_PTR(o, 0xE4), OFF_PTR(OFF_PTR(a, modelOff), 0xC));
    fn_800B3C5C(OFF_PTR(a, modelOff), info, 0);
    OFF_S32(a, 0x44) = state;
    g_sndSystem->playSE((SndID)0x1EE8, -1, 0, 0, -1);
}

extern "C" void fn_2_10124(void* arg0) {
    char* a = (char*)arg0;
    gfPadStatus s;
    g_gfPadSystem->getSysPadStatus(0xF0, &s);
    fn_2_12C6C(a, &s);

    if (s.m_buttonsPressedThisFrame.bits & 0x200) {
        g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
        fn_800B3C5C(OFF_PTR(a, 0x516C), lbl_2_data_1438 + 0x14, 0);
        fn_2_114FC(a);
        OFF_S32(a, 0x44) = 7;
        return;
    }

    unsigned int p2 = s.m_buttonsPressedThisFrame2.bits;
    if ((p2 & 0x20) || (p2 & 0x400)) {
        unsigned char f = *(unsigned char*)(a + 0x310);
        if ((f == 0 || OFF_U32(a, 0x30C) > OFF_U32(a, 0x108) + 2) &&
            (f == 0 || OFF_U32(a, 0x30C) > 2)) {
            fn_2_114FC(a);
            OFF_S32(a, 0x54) = 0;
            OFF_U32(a, 0x108) = OFF_U32(a, 0x108) + 2;
            if (*(unsigned char*)(a + 0x310) == 0) {
                fn_2_117BC(a);
            }
            *(unsigned char*)(a + 0x5164) = 1;
            playWithModel(a, 0x5170, lbl_2_data_14D0, 8);
        }
    } else if (((p2 & 0x40) || (p2 & 0x800)) && OFF_U32(a, 0x108) >= 2) {
        fn_2_114FC(a);
        stepDown(a);
        *(unsigned char*)(a + 0x5164) = 1;
        playWithModel(a, 0x5174, lbl_2_data_14D0 + 0x14, 9);
    }

    if (!(s.m_buttonsCurrentFrame2.bits & 0x40) && !(s.m_buttonsCurrentFrame2.bits & 0x800) &&
        !(s.m_buttonsCurrentFrame2.bits & 0x20) && !(s.m_buttonsCurrentFrame2.bits & 0x400)) {
        unsigned int q = s.m_buttonsPressedThisFrame2.bits;
        if (q & 8) {
            fn_2_10600(a, 0);
            return;
        }
        if (q & 4) {
            fn_2_10600(a, 1);
            return;
        }
        if (q & 1) {
            if (fn_2_10600(a, 2) == 0 && OFF_U32(a, 0x108) >= 2) {
                fn_2_114FC(a);
                stepDown(a);
                fn_2_116AC(a);
                playWithModel(a, 0x5174, lbl_2_data_14D0 + 0x14, 9);
            }
        } else if ((q & 2) && fn_2_10600(a, 3) == 0) {
            unsigned char f = *(unsigned char*)(a + 0x310);
            if ((f == 0 || OFF_U32(a, 0x30C) > OFF_U32(a, 0x108) + 2) &&
                (f == 0 || OFF_U32(a, 0x30C) > 2)) {
                fn_2_114FC(a);
                OFF_S32(a, 0x54) = 0;
                OFF_U32(a, 0x108) = OFF_U32(a, 0x108) + 2;
                if (*(unsigned char*)(a + 0x310) == 0) {
                    fn_2_117BC(a);
                }
                fn_2_116AC(a);
                playWithModel(a, 0x5170, lbl_2_data_14D0, 8);
            }
        }
    }
}
