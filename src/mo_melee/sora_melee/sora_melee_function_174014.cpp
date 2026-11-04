#include <mt/mt_vector.h>
#pragma force_active on

struct Context;

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned int);
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
    virtual void slot15(Context*, Vec3f*);
    virtual void slot16();
    virtual int slot17(unsigned int);
    virtual void slot18(unsigned int);
};

class soPostureModuleImpl {
public:
    virtual void isNull();
    virtual ~soPostureModuleImpl();
    virtual void fn_27_2362C();
    virtual void fn_27_236B0();
    virtual Vec3f fn_27_25088();
    virtual void fn_27_23E84();
    virtual void fn_27_25184();
    virtual void fn_27_2370C();
    virtual void fn_27_23728();
    virtual void fn_27_23E28();
    virtual void fn_27_23CC0();
    virtual void fn_27_25068();
    virtual void fn_27_23A9C();
    virtual void fn_27_23B18();
    virtual void fn_27_250FC();
    virtual void fn_27_250A4();
    virtual void fn_27_23BF8();
    virtual void fn_27_251B8();
    virtual void fn_27_251B0();
};

struct Modules {
    char pad0[0xc];
    soPostureModuleImpl* posture;
    char pad10[0x54];
    soNullable* work;
};

struct Context {
    char pad0[8];
    void* owner;
    char padC[0xcc];
    Modules* modules;
};

extern const char lbl_27_data_69C0[];
extern const char lbl_27_data_248[];
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void fn_27_136F78(void*);

extern "C" void fn_27_174014(soNullable* self, Context* context) {
    if (!context->modules->work->slot17(0x22000010)) {
        if (!context->modules->work->slot17(0x22000012)) {
            int value = context->modules->work->slot4(0x20000000);
            int maximum = context->modules->work->slot4(0x20000001);
            if (value > maximum / 2) {
                fn_27_136F78(__dynamic_cast(context->owner, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1));
                context->modules->work->slot18(0x22000012);
            }
        }
    }
    if (!context->modules->work->slot17(0x1200002e)) {
        Vec3f pos = context->modules->posture->fn_27_25088();
        self->slot15(context, &pos);
    }
}
