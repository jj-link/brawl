#include <types.h>
#include <mu/mu_msg.h>
#pragma force_active on

extern "C" {
void fn_2_224A8(void* self);
void fn_2_2262C(void* self, u8 b);
void fn_800B330C(void* obj, void* data, int flag);
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void setUpdateRate__16gfModelAnimationFf(void* anim, float rate);
extern char lbl_2_data_2B48[];
extern float lbl_2_rodata_990;
extern float lbl_2_rodata_994;
}

struct Base3C { char pad[0x3c]; };

struct Class_728 : Base3C {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void fn_2_36914();
    virtual void fn_2_36908();
    virtual void fn_2_361C4(int, int);
};

struct O654 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10();
    virtual void f34(int a, void* b);
    char p[0xe0];
    int e4;
};

struct Obj650 {
    char pad[0x2c];
    void* p2c;
};

struct MenuObj {
    char pad[0x10];
    nw4r::g3d::ScnMdlSimple* scn;
};

struct AnimObj {
    char pad[0x14];
    void* anim;
};

struct Obj64C {
    char pad[0x1f8];
    MenuObj* arr[6];
    MenuObj* o210;
    AnimObj* o214;
};

struct Menu {
    char pad0[0x64c];
    Obj64C* o64c;
    Obj650* o650;
    O654* o654;
    Class_728* o658;
    char pad1[0x664 - 0x65c];
    s32 s664;
    char pad2[0x66c - 0x668];
    u8 s66c_lo : 2;
    u8 s66c_hi : 6;
    char pad3[0x670 - 0x66d];
    s32 s670;
    s32 s674;
    u8 s678;
    u8 s679;
    char pad4[0x67c - 0x67a];
    MuMsg* msg;
    char pad5[0x684 - 0x680];
    void* msgData;
};

extern "C" void fn_2_21B80(Menu* self, O654* arg1, u32 arg2) {
    self->o654 = arg1;
    self->s670 = 0;
    self->s674 = 0;
    self->s678 = 0;
    self->s66c_lo = 0;
    arg1->f34(arg1->e4, self->o650->p2c);
    self->msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, 0x2a, 0x2b);
    self->msg->allocMsgBuf(0x100, 7);
    self->msg->setMsgData(self->msgData);
    int off;
    int i;
    for (i = 0, off = 0; i < 6; i++, off += 4) {
        self->msg->attachScnMdlSimple(i, (*(MenuObj**)((u8*)self->o64c + 0x1f8 + off))->scn, 0, lbl_2_rodata_990);
    }
    self->msg->attachScnMdlSimple(6, self->o64c->o210->scn, 0, lbl_2_rodata_990);
    setUpdateRate__16gfModelAnimationFf(self->o64c->o214->anim, lbl_2_rodata_994);
    fn_2_224A8(self);
    fn_2_2262C(self, self->s679);
    for (i = 0, off = 0; i < 6; i++, off += 4) {
        fn_800B330C(*(MenuObj**)((u8*)self->o64c + 0x1f8 + off), lbl_2_data_2B48 + 0x14, 0);
    }
    fn_800B330C(self->o64c->o210, lbl_2_data_2B48 + 0x14, 0);
    self->s670 = 1;
    if (arg2 == 6) {
        self->o658->fn_2_361C4(0x1e, 0x25);
        self->s664 = 0;
    } else {
        self->s664 = 1;
    }
}
