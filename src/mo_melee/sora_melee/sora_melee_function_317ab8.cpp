#include <sr/sr_common.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(unsigned int);
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);
    virtual unsigned long long slot13(short*);
    virtual void slot14();
    virtual void slot15(unsigned int, float, void*, void*);
    virtual int slot16();
    virtual int slot17(unsigned int);
    virtual void slot18(unsigned int);
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
    virtual void slot38(int, float);
};

class Setter_vptr {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(unsigned int);
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);
    virtual void slot13(unsigned int, float);
    virtual void slot14();
    virtual void slot15(unsigned int, float);
    virtual int slot16();
    virtual int slot17(unsigned int);
    virtual void slot18(unsigned int);
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
    virtual void slot38(int, float);
};

class SetterAt48 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(unsigned int);
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(unsigned int, float);
    virtual void slot16(unsigned int, float);
    virtual int slot17(unsigned int);
    virtual void slot18(unsigned int);
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
    virtual void slot38(int, float);
};

struct Accesser {
    char pad[0xd8];
    void* modules;
};

struct Modules {
    char pad[0x64];
    Object_vptr_0* manager;
};

struct Data {
    char pad50[0x50];
    int i50;
    char pad54[4];
    float f58;
    char pad5c[0x34];
    float f90;
    float f94;
    float f98;
};

struct Owner {
    char pad[0x60];
    Accesser* accesser;
    char pad2[0x4870 - 0x64];
    Data* data;
};

extern "C" {
extern void* lbl_27_bss_F0;
extern const float lbl_27_rodata_74B0;
extern const float lbl_27_rodata_74BC;

void fn_27_1D9FF8(void*);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);

void fn_27_317AB8(void* self) {
    fn_27_1D9FF8(self);

    if (!lbl_27_bss_F0) {
        void* p = ::operator new(0x4c, Heaps::System);
        if (p)
            p = fn_27_5BCD0(p);
        lbl_27_bss_F0 = p;
    }

    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        Owner* owner = (Owner*)self;
        int kind =
            (*(Object_vptr_0**)((char*)((Modules*)owner->accesser->modules) +
                                0x70))
                ->slot16();

        if (kind != 8) {
            ((Modules*)owner->accesser->modules)
                ->manager->slot8(0x10000007);
        }

        if (kind != 6) {
            ((Modules*)owner->accesser->modules)
                ->manager->slot15(0x11000001, owner->data->f90,
                                  owner->data, owner->accesser);
        } else if (((Modules*)owner->accesser->modules)
                       ->manager->slot17(0x22000005)) {
            short value = -1;
            Object_vptr_0* va =
                *(Object_vptr_0**)((char*)((Modules*)owner->accesser->modules) +
                                   0x7c);

            union {
                unsigned long long result;
                unsigned int words[2];
            } converted;
            converted.result = va->slot13(&value);

            float speed = lbl_27_rodata_74B0;
            float threshold = owner->data->f94;
            float cur = *(float*)&converted.words[1];
            if (cur >= threshold)
                speed *= owner->data->f98;

            ((SetterAt48*)((Modules*)owner->accesser->modules)->manager)
                ->slot16(0x11000001, speed);
        }

        if (((Modules*)owner->accesser->modules)
                ->manager->slot12(0x11000001) > owner->data->f58) {
            ((Setter_vptr*)((Modules*)owner->accesser->modules)->manager)
                ->slot13(0x11000001, owner->data->f58);
        }

        ((Modules*)owner->accesser->modules)
            ->manager->slot8(0x10000006);

        if (!((Modules*)owner->accesser->modules)
                 ->manager->slot17(0x1200000c)) {
            if (((Modules*)owner->accesser->modules)
                    ->manager->slot4(0x10000006) <= owner->data->i50) {
                ((Modules*)owner->accesser->modules)
                    ->manager->slot18(0x1200000c);
                (*(Object_vptr_0**)((char*)((Modules*)owner->accesser->modules) +
                                    0x88))
                    ->slot38(0, lbl_27_rodata_74BC);
            }
        }
    }
}
}
