#include <new>
#include <types.h>
#include <so/so_array.h>
#include <so/collision/so_collision_attack_part.h>
#include <so/collision/so_collision_attack_module_impl.h>

#pragma force_active on
#pragma use_simple_stdpnew on

struct Bits {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 1;
    unsigned int rest : 25;
};

class AttackArrayView {
public:
    virtual void k0();
    virtual void k1();
    virtual void k2();
    virtual void k3();
    virtual int k4();
    virtual void k5();
    virtual void k6();
    virtual void k7();
    virtual void k8();
    virtual void k9();
    virtual void k10(soCollisionAttackPart*);
    virtual void k11();
    virtual void k12();
    virtual int k13();
    virtual int k14();
    virtual void k15();
    virtual void k16();
    virtual void k17();
    virtual void k18();
    virtual void k19();
    virtual void k20();
    virtual void k21();
    virtual void k22();
    virtual void k23();
    virtual void k24();
    virtual void k25();
    virtual void k26();
    virtual int k27();
    virtual int k28();
};

extern "C" {
extern unsigned char lbl_27_data_3B5B0[];
extern unsigned char lbl_27_data_46F8[];
extern unsigned char lbl_27_data_125F0[];
extern const float lbl_27_rodata_75B0;

void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__21soCollisionAttackPartFv(void*);
void __dt__21soCollisionAttackPartFv(void*, int);
void __ct__16soCollisionGroupFv(void*);
void fn_27_37D3C(void*, int);
int resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(
    void*, void*, int, int, int, int, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
    void*, void*, int);
}

class AbsoluteArrayStorage {
    void* table;
public:
    AbsoluteArrayStorage() : table(lbl_27_data_125F0) {}
};

struct PaddedData {
    char prefix[36];
    float slipChance;
    float hitStopFrame;
    float hitStopDelay;
    char padding[56];

    PaddedData() {
        slipChance = lbl_27_rodata_75B0;
        hitStopFrame = lbl_27_rodata_75B0;
        hitStopDelay = lbl_27_rodata_75B0;
    }
};

extern "C" AttackArrayView* fn_27_3278E0(
    AttackArrayView* self, soModuleAccesser* accesser, int taskId,
    gfTask::Category taskCategory, soEventObserverRegistrationDesc* observerDesc) {
    unsigned char* bytes = reinterpret_cast<unsigned char*>(self);
    unsigned int* words = reinterpret_cast<unsigned int*>(self);

    {
        soCollisionAttackPart part(static_cast<soCollision::Category>(0), 0);

        words[0] = reinterpret_cast<unsigned int>(lbl_27_data_3B5B0);
        words[1] = reinterpret_cast<unsigned int>(lbl_27_data_3B5B0 + 0x48);
        words[2] &= 0x3fffff;

        __construct_array(
            bytes + 0xC, __ct__21soCollisionAttackPartFv,
            reinterpret_cast<void (*)(void*)>(__dt__21soCollisionAttackPartFv),
            0x90, 2);

        int d, c, b, a;
        a = self->k28();
        b = self->k27();
        c = self->k13();
        d = self->k14();

        int count =
            resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(
                bytes + 4, reinterpret_cast<void*>(2), self->k4(), d, c, b, a);

        for (int i = 0; i < count; ++i) {
            self->k10(&part);
        }
    }

    words[0x12C / 4] = reinterpret_cast<unsigned int>(lbl_27_data_46F8);
    words[0x130 / 4] = reinterpret_cast<unsigned int>(lbl_27_data_46F8 + 0x48);

    Bits* flags = reinterpret_cast<Bits*>(bytes + 0x134);
    flags->a = 0;
    flags->b = 1;
    flags->c = 0;

    __construct_array(
        bytes + 0x138, __ct__16soCollisionGroupFv,
        reinterpret_cast<void (*)(void*)>(fn_27_37D3C), 0x78, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        bytes + 0x130, reinterpret_cast<void*>(1), 1);

    PaddedData x;
    soArray<soCollisionAttackAbsolute>* absolutes =
        reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(
            new (bytes + 0x1B0) AbsoluteArrayStorage);

    new (bytes + 0x1B4) soCollisionAttackModuleImpl(
        accesser, taskId, static_cast<gfTask::Category>(taskCategory),
        reinterpret_cast<soArray<soCollisionAttackPart>*>(self),
        reinterpret_cast<soArray<soCollisionGroup>*>(bytes + 0x12C),
        absolutes, observerDesc, true);

    return self;
}
