#include <new>
#include <gf/gf_task.h>
#include <types.h>
#include <so/collision/so_collision_attack_part.h>
#include <so/collision/so_collision_group.h>
#include <so/so_array_vector_calculator.h>

#pragma force_active on
#pragma use_simple_stdpnew on

struct Bits {
    unsigned int a : 8;
    unsigned int b : 4;
    unsigned int c : 1;
    unsigned int rest : 19;
};

class soModuleAccesser;
class soEventObserverRegistrationDesc;

class soCollisionAttackModuleImpl {
public:
    virtual ~soCollisionAttackModuleImpl();
    virtual void fn_27_39AA4();
    virtual void fn_27_39C34();
    virtual void fn_27_39C90();
    virtual bool fn_27_39D10();
    virtual void fn_27_39D80();
    virtual void fn_27_39E30();
    virtual void fn_27_39EF4();
    virtual void fn_27_3A0C4();
    virtual void fn_27_3A270();
    virtual int fn_27_3AF7C(soCollisionAttackPart&);
    virtual void fn_27_3B070();
    virtual void fn_27_3B120();
    virtual int fn_27_3A3C8();
    virtual bool fn_27_3A430();
    virtual void fn_27_3A4BC();
    virtual void fn_27_3A504();
    virtual void fn_27_3A600();
    virtual void fn_27_3A664();
    virtual void fn_27_3A6A4();
    virtual void fn_27_3A6D8();
    virtual void fn_27_3A718();
    virtual void fn_27_3AD40();
    virtual void fn_27_3ADDC();
    virtual void fn_27_3AF34();
    virtual void fn_27_3A75C();
    virtual void fn_27_3A920();
    virtual int fn_27_3A960();
    virtual int fn_27_3A994();

    soCollisionAttackModuleImpl(
        soModuleAccesser*, int, gfTask::Category,
        soArray<soCollisionAttackPart>*, soArray<soCollisionGroup>*,
        soArray<soCollisionAttackAbsolute>*, soEventObserverRegistrationDesc*, bool);
};

extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void* __ct__21soCollisionAttackPartFv(void*);
void* __ct__16soCollisionGroupFv(void*);
void* __dt__21soCollisionAttackPartFv(void*, int);
void* fn_27_37D3C(void*, int);

extern unsigned char lbl_27_data_38C70[];
extern unsigned char lbl_27_data_9A918[];
extern char lbl_27_data_125F0[];
extern const float lbl_27_rodata_7D68;
}

class AbsoluteArrayInitialization {
public:
    char* table;
    AbsoluteArrayInitialization() : table(lbl_27_data_125F0) {}
};

extern "C" void* fn_27_3929FC(
    void* object, soModuleAccesser* accesser, int taskId,
    gfTask::Category category, soEventObserverRegistrationDesc* desc)
{
    unsigned char* storage = static_cast<unsigned char*>(object);
    unsigned char attackPartStorage[0x1C8];

    new (attackPartStorage + 0x138) soCollisionAttackPart(
        static_cast<soCollision::Category>(0), false);

    *reinterpret_cast<unsigned char**>(storage) = lbl_27_data_38C70;
    *reinterpret_cast<unsigned char**>(storage + 4) = lbl_27_data_38C70 + 0x48;
    *reinterpret_cast<unsigned int*>(storage + 8) &= 0x7FFFF;

    __construct_array(
        storage + 0x0C,
        reinterpret_cast<void (*)(void*)>(__ct__21soCollisionAttackPartFv),
        reinterpret_cast<void (*)(void*)>(__dt__21soCollisionAttackPartFv),
        0x90, 7);

    soCollisionAttackModuleImpl* base = reinterpret_cast<soCollisionAttackModuleImpl*>(object);
    bool count3;
    int count2, count1, count0;
    count0 = base->fn_27_3A994();
    count1 = base->fn_27_3A960();
    count2 = base->fn_27_3A3C8();
    count3 = base->fn_27_3A430();
    bool count4 = base->fn_27_39D10();

    int count = soArrayVectorCalculator::resize(
        *reinterpret_cast<soArrayVectorCalcInterface*>(storage + 4),
        7, count4, count3, count2, count1, count0);

    for (int i = 0; i < count; ++i)
        base->fn_27_3AF7C(*reinterpret_cast<soCollisionAttackPart*>(attackPartStorage + 0x138));

    reinterpret_cast<soCollisionAttackPart*>(attackPartStorage + 0x138)
        ->~soCollisionAttackPart();

    Bits* groupFlags = reinterpret_cast<Bits*>(storage + 0x404);
    *reinterpret_cast<unsigned char**>(storage + 0x3FC) = lbl_27_data_9A918;
    *reinterpret_cast<unsigned char**>(storage + 0x400) = lbl_27_data_9A918 + 0x48;
    groupFlags->a = 0;
    groupFlags->b = 7;
    groupFlags->c = 0;

    __construct_array(
        storage + 0x408,
        reinterpret_cast<void (*)(void*)>(__ct__16soCollisionGroupFv),
        reinterpret_cast<void (*)(void*)>(fn_27_37D3C),
        0x78, 7);
    soArrayVectorCalculator::postInitialize(
        *reinterpret_cast<soArrayVectorCalcInterface*>(storage + 0x400), 7, 7);

    float one = lbl_27_rodata_7D68;
    AbsoluteArrayInitialization* absoluteArray =
        new (storage + 0x750) AbsoluteArrayInitialization;
    *reinterpret_cast<float*>(attackPartStorage + 0xf4) = one;
    *reinterpret_cast<float*>(attackPartStorage + 0x28) = one;
    *reinterpret_cast<float*>(attackPartStorage + 0x94) = one;

    new (storage + 0x754) soCollisionAttackModuleImpl(
        accesser, taskId, category,
        reinterpret_cast<soArray<soCollisionAttackPart>*>(storage),
        reinterpret_cast<soArray<soCollisionGroup>*>(storage + 0x3FC),
        reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(absoluteArray),
        desc, true);

    return object;
}
