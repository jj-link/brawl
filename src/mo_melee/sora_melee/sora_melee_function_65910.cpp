#include <types.h>
#pragma force_active on

class Object_vptr_0 {
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
    virtual u32 slot9(int);
    virtual u32 slot10(int);
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual u32 slot20(int);
    virtual int slot21(int);
};

struct Prefix { char pad[8]; };
class Object_vptr_8 : public Prefix {
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
    virtual int slot41();
};

struct Modules {
    char pad[0x38];
    Object_vptr_8* first;
    char pad2[0x18];
    Object_vptr_0* second;
};
struct Object {
    char pad[0xd8];
    Modules* modules;
};
struct Self {
    char pad[0x10];
    Object* object;
};

extern "C" int fn_27_65910(Self* self) {
    Object* object = self->object;
    if (object->modules->second->slot10(0) == 1U ||
        self->object->modules->second->slot9(0) == 1U) {
        if (self->object->modules->first->slot41() == 0) {
            if (self->object->modules->second->slot20(0) == 1U) {
                if (self->object->modules->second->slot21(0) == 0) {
                    return 1;
                }
            } else {
                return 1;
            }
        } else {
            if (self->object->modules->second->slot20(0) == 1U) {
                self->object->modules->second->slot21(0);
            }
        }
    }
    return 0;
}
