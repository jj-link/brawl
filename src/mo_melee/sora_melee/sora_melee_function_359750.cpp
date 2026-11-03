#include <mt/mt_vector.h>
#include <so/so_enable.h>
#pragma force_active on

struct Accesser;
class soNullable {
public:
    virtual void isNull();
    virtual void slot1(Accesser*);
    virtual Vec2f slot2();
    virtual void slot3();
    virtual int slot4(unsigned long);
    virtual void slot5(int, unsigned long);
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
    virtual bool slot17(unsigned long);
    virtual void slot18();
    virtual void slot19(unsigned long);

    unsigned char pad4;
    soEnable flags;
    unsigned char suspended;
    unsigned char pad7;
    float x;
    float y;
};
struct Modules {
    char pad[0x64];
    soNullable* work;
};
struct Accesser {
    char pad[0xd8];
    Modules* modules;
};
extern "C" int fn_27_1922CC(Accesser*, unsigned long);
extern "C" float fn_27_192278(Accesser*, unsigned long);

extern "C" void fn_27_359750(soNullable* self, void*, Accesser* a) {
    soNullable* work = a->modules->work;
    int timer = fn_27_1922CC(a, 0x5dc0);
    if (work->slot4(0x20000003) >= timer) {
        if (a->modules->work->slot17(0x22000010)) {
            self->y = self->slot2().m_y + fn_27_192278(a, 0xfaa);
            a->modules->work->slot19(0x22000010);
            a->modules->work->slot5(0, 0x20000003);
        }
    }
    if (self->slot2().m_y > fn_27_192278(a, 0xfab)) {
        self->y = fn_27_192278(a, 0xfab);
    }
    if (self->flags.isEnable() == true && self->suspended == 0) {
        self->slot1(a);
    }
}
