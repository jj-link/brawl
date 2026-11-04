#include <types.h>
#pragma force_active on
struct Msg { int id; unsigned char flag; };
struct Vec { float x, y, z; };
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(unsigned int);
    virtual void slot7();
    virtual void slot8(unsigned int);
    virtual unsigned int slot9(unsigned int);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(unsigned int, Msg*);
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
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85(Vec*, Vec*);
    virtual void slot86();
    virtual void slot87(unsigned int);
};
struct Modules { char pad[0x54]; soNullable* comp; };
struct Accesser { char pad[0xd8]; Modules* modules; };
struct Object { char pad[0x10]; Accesser* accesser; char pad14[0x18]; unsigned char a, b; };
extern "C" const float lbl_27_rodata_910[];
extern "C" void fn_27_666FC(Object* self, u32 arg1, u32 arg2) {
    if (self->accesser->modules->comp->slot9(0) == 1U) {
        if (self->a == 1) {
            Msg msg;
            msg.id = 9;
            msg.flag = 0;
            self->accesser->modules->comp->slot15(0, &msg);
        }
        if (arg1 == 1U && self->b == 1) {
            if (arg2 == 1U) {
                Vec a, b;
                a.x = lbl_27_rodata_910[0];
                a.y = lbl_27_rodata_910[0];
                a.z = lbl_27_rodata_910[0];
                b.x = lbl_27_rodata_910[0];
                b.y = lbl_27_rodata_910[0];
                b.z = lbl_27_rodata_910[0];
                self->accesser->modules->comp->slot85(&a, &b);
            }
            self->accesser->modules->comp->slot87(1);
        }
        self->accesser->modules->comp->slot8(0);
    }
    self->accesser->modules->comp->slot6(2);
}