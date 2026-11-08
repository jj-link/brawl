#include <ft/ft_manager.h>
#include <ft/ft_owner.h>
#include <so/so_value_accesser.h>

#pragma force_active on

struct EffectArg {
    int id;
    bool flag;
};

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
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16(int, EffectArg*, int);
    virtual void slot17();
    virtual void slot18(unsigned int);
    virtual void slot19(unsigned int);
};

struct Modules {
    char pad0[0x54];
    Object_vptr_0* effect;
    char pad58[0xc];
    Object_vptr_0* work;
};

struct Accesser {
    char pad0[0xd8];
    Modules* modules;
};

struct Object {
    char pad0[0x28];
    void* field28;
    char pad2c[0x10];
    void* vtable;
    char pad40[0x20];
    Accesser* accesser;
    char pad64[0xa8];
    int field10c;
};

extern "C" {
bool fn_27_112030(ftOwner*);
unsigned int fn_27_111F7C(ftOwner*);
unsigned int fn_27_111FAC(ftOwner*);
void fn_27_111FC8(ftOwner*, int);
unsigned char fn_27_111FDC(ftOwner*);
void fn_27_383A44(void*, int);
void fn_27_10D968(ftManager*, int, int, int, int, void*);
}

typedef ftOwner* (*GetOwner)(Object*);

extern "C" void fn_27_382B7C(Object* self, int arg) {
    Accesser* accesser = self->accesser;
    ftOwner* owner = ((Fighter*)self)->getOwner();

    accesser->modules->work->slot19(0x1200003e);

    if (*((unsigned char*)g_ftManager + 0x68) == 0) {
        if ((unsigned int)(*((unsigned char*)g_ftManager + 0x6d) != 0) == 1)
            return;

        if (*((unsigned char*)g_ftManager + 0x6a) == 1 &&
            owner->getStockCount() == 0) {
            accesser->modules->work->slot18(0x12000043);
            return;
        }

        unsigned int flag = (*((unsigned char*)g_ftManager + 0x6c) >> 5) & 1;
        if (((-flag | flag) >> 31) == 1)
            return;
    }

    if (!fn_27_112030(owner))
        return;

    if (fn_27_111F7C(owner) == 1 && fn_27_111FDC(owner) > 1) {
        fn_27_383A44(self, 0);
        if (fn_27_111FAC(owner) == 1)
            fn_27_111FC8(owner, arg);

        int entry = self->field10c;
        ftManager* manager = g_ftManager;
        int value = soValueAccesser::getConstantInt(
            (soModuleAccesser*)accesser, 0x5a38, 0);
        fn_27_10D968(manager, entry, 6, value, 0, self->field28);
    } else {
        EffectArg effect;
        effect.id = 0x838;
        effect.flag = false;
        self->accesser->modules->effect->slot16(-1, &effect, 0);
        self->accesser->modules->work->slot18(0x1200003d);
    }
}
