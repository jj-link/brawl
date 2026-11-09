#include <types.h>

#pragma force_active on

extern "C" int fn_18_1A9C(void*);
extern "C" void fn_18_1C4C(void*, int);
extern "C" char lbl_2_data_1DB0[];

struct Entry {
    char pad[0x10];
    s32 val;
};

class Obj654 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s13(s32, s32);
    char pad[0xe0];
    s32 unkE4;
};

struct Class_728_base {
    char pad[0x3c];
};

class Class_728 : public Class_728_base {
public:
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
    virtual void fn_2_361C4(s32, s32);
};

struct Menu {
    char p0[0x42];
    u16 unk42;
    char p1[0x638 - 0x44];
    s32 unk638;
    void* unk63c;
    char p2[0x644 - 0x640];
    s32 unk644;
    char p3[0x64c - 0x648];
    Entry** unk64c;
    char p4[0x654 - 0x650];
    Obj654* unk654;
    Class_728* unk658;
    char p5[0x664 - 0x65c];
    s32 unk664;
    char p6[0x66c - 0x668];
    s32 unk66c;
    s32 unk670;
};

extern "C" void fn_2_14E4C(Menu* self, Obj654* arg1, s32 arg2) {
    u16 var31;
    s32 off;
    s32 var29;
    s32 var28;
    u32 cnt;

    self->unk66c = 0;
    self->unk63c = lbl_2_data_1DB0;
    cnt = 0;
    off = 0;
    self->unk654 = arg1;
    self->unk644 = 0;
    self->unk670 = 0;
    self->unk638 = arg2;

    do {
        Entry* e = *(Entry**)((char*)self->unk64c + off);
        self->unk654->s13(self->unk654->unkE4, e->val);
        cnt += 1;
        off += 4;
    } while (cnt < 6);

    switch (self->unk638) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6: {
        self->unk664 = 2;
        u16 lo = arg2 - 1;
        self->unk42 = lo;
        self->unk658->fn_2_361C4((u16)lo + 1, (u16)lo);
        break;
    }
    default:
        self->unk664 = 0;
        switch (fn_18_1A9C(self)) {
        case 0:
            var31 = 0;
            var29 = 1;
            var28 = 0;
            break;
        case 0x28:
            var31 = 2;
            var29 = 3;
            var28 = 2;
            break;
        }
        self->unk42 = var31;
        self->unk638 = 0;
        fn_18_1C4C(self, 1);
        self->unk658->fn_2_361C4(var29, var28);
        break;
    }

    fn_18_1C4C(self, 1);
}
