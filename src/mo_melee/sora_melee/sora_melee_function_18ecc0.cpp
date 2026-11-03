#include <types.h>
#pragma force_active on
extern "C" float lbl_27_rodata_261C;
extern "C" float lbl_27_rodata_2620;
struct Msg { int id; float a; float b; u8 pad[4]; };
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual int slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual int slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30(Msg*, float);
};
struct Holder { char pad[8]; soNullable* sub; };
struct Owner { char pad[0xd8]; Holder* h; };
extern "C" void fn_27_18ECC0(void*, Owner* obj) {
    if (obj->h->sub->slot16()) {
        if ((u32)(obj->h->sub->slot21() - 0xa4) <= 3) {
            Msg msg;
            msg.id = 0x29;
            msg.a = lbl_27_rodata_261C;
            msg.b = lbl_27_rodata_2620;
            msg.pad[0] = 0;
            msg.pad[1] = 0;
            msg.pad[2] = 0;
            msg.pad[3] = 0;
            obj->h->sub->slot30(&msg, lbl_27_rodata_261C);
        } else if (!obj->h->sub->slot9()) {
            Msg msg;
            msg.id = 0x29;
            msg.a = lbl_27_rodata_261C;
            msg.b = lbl_27_rodata_2620;
            msg.pad[0] = 0;
            msg.pad[1] = 0;
            msg.pad[2] = 0;
            msg.pad[3] = 0;
            obj->h->sub->slot30(&msg, lbl_27_rodata_261C);
        }
    }
}