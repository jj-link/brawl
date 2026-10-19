#pragma force_active on
#define VIRTUAL_SLOTS(n) \
    virtual void unused##n##a(); \
    virtual void unused##n##b(); \
    virtual void unused##n##c(); \
    virtual void unused##n##d(); \
    virtual void unused##n##e(); \
    virtual void unused##n##f(); \
    virtual void unused##n##g(); \
    virtual void unused##n##h(); \
    virtual void unused##n##i(); \
    virtual void unused##n##j();

typedef unsigned int u32;
typedef int s32;

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
    VIRTUAL_SLOTS(10)
    virtual void callback(int);
};

#undef VIRTUAL_SLOTS

struct Wnem {
    char pad0[0xC];
    VirtualPart part;
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
extern char lbl_41_data_EB94[];
extern const float lbl_41_rodata_FE4;

void Report__14wnemCommonProcFPCce(const char*, ...);
void SetDeadMode__10wnemSimpleFv(Wnem*);
u32 getFrameCounter__10wnemSimpleFl(Wnem*, s32);
void RequestDeactive__10wnemSimpleFv(Wnem*);

void fn_41_46FF0(Wnem* wn) {
    s32* data = 0;
    if (wn->unk2234) {
        data = wn->unk2234;
    }

    bool entered = wn->unk2214;
    wn->unk2214 = false;
    if (entered) {
        Report__14wnemCommonProcFPCce(lbl_41_data_EB94);
        SetDeadMode__10wnemSimpleFv(wn);
        wn->unk2204 = lbl_41_rodata_FE4;
        wn->unk2200 = lbl_41_rodata_FE4;
        wn->unk21FC = lbl_41_rodata_FE4;
        wn->unk21F8 = lbl_41_rodata_FE4;
        wn->part.callback(0);
    }

    if (getFrameCounter__10wnemSimpleFl(wn, 1) >= (u32)data[14]) {
        RequestDeactive__10wnemSimpleFv(wn);
    }
}
}
