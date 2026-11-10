#include <types.h>
#pragma force_active on

extern char lbl_41_data_EB0A[];
extern float lbl_41_rodata_FE0[];

#define VIRTUAL_SLOTS(n) \
    virtual void s##n##a(); \
    virtual void s##n##b(); \
    virtual void s##n##c(); \
    virtual void s##n##d(); \
    virtual void s##n##e(); \
    virtual void s##n##f(); \
    virtual void s##n##g(); \
    virtual void s##n##h(); \
    virtual void s##n##i(); \
    virtual void s##n##j();

class VirtualPart {
    char pad[0x3C];

public:
    VIRTUAL_SLOTS(0)
    VIRTUAL_SLOTS(1)
    VIRTUAL_SLOTS(2)
    VIRTUAL_SLOTS(3)
    VIRTUAL_SLOTS(4)
    VIRTUAL_SLOTS(5)
    VIRTUAL_SLOTS(6)
    VIRTUAL_SLOTS(7)
    VIRTUAL_SLOTS(8)
    VIRTUAL_SLOTS(9)
    virtual void t0();
    virtual void t1();
    virtual void t2();
    virtual void t3();
    virtual void t4();
    virtual void t5();
    virtual void cb(int, int);
};

#undef VIRTUAL_SLOTS

struct Wnem {
    char pad0[0xC];
    VirtualPart vpart;
    char pad4C[0x21F8 - 0x4C];
    float unk21F8;
    float unk21FC;
    float unk2200;
    float unk2204;
    char pad2208[0xC];
    bool unk2214;
    char pad2215[0x1F];
    s32* unk2234;
};

extern "C" {
void Report__14wnemCommonProcFPCce(const char*, ...);
void SetDeadMode__10wnemSimpleFv(Wnem*);
void setProcFnc_LifeZero__10wnemSimpleFl(Wnem*, s32);
u32 getFrameCounter__10wnemSimpleFl(Wnem*, s32);
void changeProcFnc__10wnemSimpleFll(Wnem*, s32, s32);

void fn_41_46B8C(void* in) {
    float* k = lbl_41_rodata_FE0;
    s32* data = 0;
    Wnem* wn = (Wnem*)in;
    if (wn->unk2234) {
        data = wn->unk2234;
    }

    bool entering = wn->unk2214;
    wn->unk2214 = false;
    if (entering) {
        Report__14wnemCommonProcFPCce(lbl_41_data_EB0A);
        SetDeadMode__10wnemSimpleFv(wn);
        setProcFnc_LifeZero__10wnemSimpleFl(wn, 0x2B);
        wn->vpart.cb(2, 0);

        if (wn->unk21F8 > k[1] && wn->unk21F8 < k[4]) {
            wn->unk21F8 = k[5];
        } else if (wn->unk21F8 < k[1]) {
            if (wn->unk21F8 >= k[6]) {
                wn->unk21F8 = k[7];
            }
        }
        wn->unk2200 = k[1];
    }

    if (getFrameCounter__10wnemSimpleFl(wn, 1) >= (u32)data[3]) {
        changeProcFnc__10wnemSimpleFll(wn, 0x2B, 1);
    }
    float* d = (float*)data;
    float scale = d[2];
    wn->unk21F8 *= scale;
}
}
