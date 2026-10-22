#pragma force_active on
#include <types.h>

struct VObj {
    char pad[0x3C];
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
    virtual void slot25();
    virtual void slot26();
    virtual void call(s32 a, s32 b);
};

struct Arg1 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void call(s32 a, void* b);
    char pad[0xE0];
    s32 field_e4;
};

struct Menu {
    char pad0_42[0x42];
    s16 field_42;
    char pad44_63c[0x63c - 0x44];
    void* field_63c;
    void* field_640;
    s32 field_644;
    void* field_648;
    void* field_64c;
    void* field_650;
    void* field_654;
    VObj* field_658;
    char pad65c_664[8];
    s32 field_664;
};

extern "C" void fn_18_1C4C(Menu* a, int b);
extern "C" char lbl_2_data_2198[];

extern "C" void fn_2_17FD4(Menu* arg0, Arg1* arg1) {
    arg0->field_63c = &lbl_2_data_2198;
    arg0->field_654 = arg1;
    arg0->field_664 = 0;
    arg0->field_42 = 0;
    arg0->field_644 = 0x63;

    s32 offset = 0;
    u32 count = 0;
    do {
        void* ptr = *(void**)((char*)arg0->field_64c + offset + 0x18c);
        void* val = *(void**)((char*)ptr + 0x10);
        arg1->call(arg1->field_e4, val);
        count += 1;
        offset += 4;
    } while (count < 5);

    fn_18_1C4C(arg0, 1);
    arg0->field_658->call(0x1b, 0x49);
}
