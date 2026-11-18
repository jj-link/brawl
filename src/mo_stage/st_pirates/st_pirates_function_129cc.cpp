#include <types.h>
#include <new>
#include <gr/gr_gimmick.h>
#include <so/collision/so_collision_attack_module_impl.h>
#include <so/so_array_vector_calculator.h>

#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
    extern char lbl_52_data_46F0[];
    extern char lbl_52_data_3E58[];
    extern char lbl_52_data_1A60[];
    extern char lbl_52_data_1910[];
    extern char lbl_52_data_1DA8[];
    extern char lbl_27_bss_398[];
    extern char lbl_27_bss_3DC[];
    extern char lbl_27_bss_598[];
    extern char lbl_27_bss_444[];
    extern unsigned char lbl_8040ABD8[];
    extern soEventObserverRegistrationDesc* lbl_27_data_54C60;

    void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
    void fn_27_262728(void*, void*, void*, void*, void*, void*, void*, void*);
    void fn_27_26320C(void*);
    void fn_27_2632F4(void*, void*, float, float);
    void fn_27_264D9C(void*, void*);
    void __construct_array(void*, void (*)(void*), void (*)(void*),
                           unsigned long, int);
    void fn_52_6E4C(void*);
    void __dt__21soCollisionAttackPartFv(void*);
    void __ct__16soCollisionGroupFv(void*);
    void fn_27_37D3C(void*);
}

struct InitialData {
    void* ground;
    void* model;
    int value;
    void* position;
    void* pair;
};


class ModelObject {
public:
    virtual bool matches(const void**);
};

struct Pair {
    void* first;
    void* second;

    Pair() : first(0), second(0) {}
};

class AttackArrayInterface : public soArrayVectorAbstract<soCollisionAttackPart> {
public:
    virtual bool isEmpty() const = 0;
};

struct ArrayBits {
    unsigned int top : 2;
    unsigned int last : 2;
    unsigned int size : 2;
    unsigned int full : 1;
    unsigned int rest : 25;
};

struct AttackStorage {
    void* vt;
    void* calc;
    unsigned int flags;
    char parts[0x90];
    void* groupVt;
    void* groupCalc;
    ArrayBits groupBits;
    char groups[0x78];
    void* absoluteVt;
    char impl[0xa0];
};

class AbsoluteArrayStorage {
    void* table;
public:
    AbsoluteArrayStorage() : table(lbl_52_data_1DA8) {}
};

struct PaddedData {
    char prefix[36];
    float a, b, c;
    char padding[56];
    PaddedData() {
        a = 1.0f;
        b = 1.0f;
        c = 1.0f;
    }
};

struct AttackPartStack {
    char part[0x90];
};

extern "C" void fn_52_129CC(grGimmick* self) {
    char* ground = reinterpret_cast<char*>(self);
    Pair* pair = static_cast<Pair*>(__nw__FUlQ25Heaps8HeapType(8, 15));
    if (pair)
        pair = new (pair) Pair;
    *reinterpret_cast<Pair**>(ground + 0x19c) = pair;
    pair->first = 0;
    (*reinterpret_cast<Pair**>(ground + 0x19c))->second = 0;

    InitialData data = {0, 0, 16, 0, 0};
    data.ground = self;
    ModelObject* model = **reinterpret_cast<ModelObject***>(ground + 0x44);
    bool valid = false;
    if (model) {
        const void* key = lbl_8040ABD8;
        if (model->matches(&key))
            valid = true;
    }
    data.model = valid ? model : 0;

    Vec3f position = self->getPos();
    data.position = &position;
    data.pair = *reinterpret_cast<Pair**>(ground + 0x19c);

    char* object = static_cast<char*>(__nw__FUlQ25Heaps8HeapType(0x52c, 15));
    if (object) {
        fn_27_262728(object, &data, lbl_52_data_46F0, object + 0x47c,
                     lbl_27_bss_398, lbl_27_bss_3DC, lbl_27_bss_598,
                     lbl_27_bss_444);

        *reinterpret_cast<void**>(object + 0x3c) = lbl_52_data_3E58;
        *reinterpret_cast<void**>(object + 0x40) = lbl_52_data_3E58 + 0x64;
        *reinterpret_cast<void**>(object + 0x48) = lbl_52_data_3E58 + 0x70;
        *reinterpret_cast<void**>(object + 0x54) = lbl_52_data_3E58 + 0x84;
        *reinterpret_cast<void**>(object + 0x64) = lbl_52_data_3E58 + 0xdc;

        gfTask::Category category = static_cast<gfTask::Category>(
            static_cast<u8>(*reinterpret_cast<u32*>(object + 0x2c) >> 7));
        AttackStorage* storage = reinterpret_cast<AttackStorage*>(object + 0x358);
        soEventObserverRegistrationDesc* desc = lbl_27_data_54C60;
        int id = *reinterpret_cast<int*>(object + 0x28);

        {
            AttackPartStack stack;
            new (stack.part) soCollisionAttackPart(
                static_cast<soCollision::Category>(7), false);
            storage->vt = lbl_52_data_1A60;
            storage->calc = lbl_52_data_1A60 + 0x48;
            storage->flags &= 0x01ffffff;
            __construct_array(storage->parts, fn_52_6E4C,
                              __dt__21soCollisionAttackPartFv, 0x90, 1);

            soArrayVectorAbstract<soCollisionAttackPart>* vec =
                reinterpret_cast<soArrayVectorAbstract<soCollisionAttackPart>*>(storage);
            int count = soArrayVectorCalculator::resize(
                *reinterpret_cast<soArrayVectorCalcInterface*>(&storage->calc),
                1, reinterpret_cast<AttackArrayInterface*>(storage)->isEmpty(),
                vec->isFull(), vec->capacity(), vec->getTopIndex(), vec->getLastIndex());
            for (int i = 0; i < count; ++i)
                reinterpret_cast<soArray<soCollisionAttackPart>*>(storage)->push(
                    *reinterpret_cast<soCollisionAttackPart*>(stack.part));
            reinterpret_cast<soCollisionAttackPart*>(stack.part)->~soCollisionAttackPart();
        }

        storage->groupVt = lbl_52_data_1910;
        storage->groupCalc = lbl_52_data_1910 + 0x48;
        storage->groupBits.top = 0;
        storage->groupBits.last = 0;
        storage->groupBits.size = 1;
        storage->groupBits.full = 0;
        __construct_array(storage->groups, __ct__16soCollisionGroupFv,
                          fn_27_37D3C, 0x78, 1);
        soArrayVectorCalculator::postInitialize(
            *reinterpret_cast<soArrayVectorCalcInterface*>(&storage->groupCalc),
            1, 1);

        PaddedData padded;
        soArray<soCollisionAttackAbsolute>* absolutes =
            reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(new (&storage->absoluteVt) AbsoluteArrayStorage);
        new (storage->impl) soCollisionAttackModuleImpl(
            reinterpret_cast<soModuleAccesser*>(object + 0xa8),
            id, category,
            reinterpret_cast<soArray<soCollisionAttackPart>*>(storage),
            reinterpret_cast<soArray<soCollisionGroup>*>(&storage->groupVt),
            absolutes,
            desc, true);

        fn_27_26320C(object);
        fn_27_2632F4(object, data.position, -1.0f, 0.0f);
        *reinterpret_cast<void**>(object + 0x51c) = 0;
        *reinterpret_cast<void**>(object + 0x520) = 0;
        *reinterpret_cast<void**>(object + 0x524) = 0;
        *reinterpret_cast<void**>(object + 0x528) = 0;
    }
    fn_27_264D9C(self, object);
}
