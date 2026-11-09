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
typedef unsigned char u8;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
};

class Class_BDA0 {
public:
    virtual void fn_41_BDA0();
    virtual void fn_41_BE5C();
    virtual void fn_41_BFDC();
    virtual void fn_41_BDA8();
    virtual void fn_41_C59C();
};

class Class_3516C {
public:
    virtual void fn_41_3516C();
    virtual void fn_41_34F30();
    virtual void fn_41_350A4();
    virtual void fn_41_350AC();
    virtual void fn_41_350B4();
    virtual void fn_41_350BC();
    virtual void fn_41_350DC();
    virtual void fn_41_350C4();
    virtual void fn_41_35120();
    virtual void fn_41_350CC();
    virtual void fn_41_350D4();
    virtual void fn_41_350E4();
    virtual void fn_41_350EC();
    virtual void fn_41_350F0();
    virtual void fn_41_350F4();
    virtual void fn_41_350F8(s32, s32*);
};

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

struct Modules {
    char pad[0x1c];
    Class_BDA0* obj;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
extern char lbl_41_data_EB2A[];
extern const float lbl_41_rodata_FE4;

void Report__14wnemCommonProcFPCce(const char*, ...);
void SetDeadMode__10wnemSimpleFv(Wnem*);
void executeAnimCmd__10wnemSimpleFUl(Wnem*, u32);
void executeAnimCmd__10wnemSimpleFlll(Wnem*, s32, s32, s32);
u32 getFrameCounter__10wnemSimpleFl(Wnem*, s32);
void RequestDeactive__10wnemSimpleFv(Wnem*);

void fn_41_46CBC(Wnem* wn, Accesser* accesser) {
    s32* data = 0;
    if (wn->unk2234) {
        data = wn->unk2234;
    }

    bool entered = wn->unk2214;
    wn->unk2214 = false;
    if (entered) {
        Report__14wnemCommonProcFPCce(lbl_41_data_EB2A);
        SetDeadMode__10wnemSimpleFv(wn);
        executeAnimCmd__10wnemSimpleFUl(wn, 1);
        executeAnimCmd__10wnemSimpleFUl(wn, 0);
        if (data[5]) {
            executeAnimCmd__10wnemSimpleFlll(wn, data[5], 4, 1);
        }
        wn->unk2204 = lbl_41_rodata_FE4;
        wn->unk2200 = lbl_41_rodata_FE4;
        wn->unk21FC = lbl_41_rodata_FE4;
        wn->unk21F8 = lbl_41_rodata_FE4;
        wn->part.callback(0);
    }

    if (getFrameCounter__10wnemSimpleFl(wn, 1) >= (u32)data[4]) {
        accesser->modules->obj->fn_41_C59C();
        RequestDeactive__10wnemSimpleFv(wn);
    }
}
}