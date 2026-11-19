#include <new>
#include <so/collision/so_collision_attack_module_impl.h>
#include <so/collision/so_collision_hit_module_impl.h>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" char lbl_40_data_5028[];
struct GlobalObject {
    void* vtable;
    GlobalObject() { vtable = 0; vtable = lbl_40_data_5028; }
};
extern "C" {
extern char lbl_40_data_14980[], lbl_27_bss_598[], lbl_27_bss_444[];
extern char lbl_40_data_126E4[], lbl_40_data_83C0[], lbl_40_data_6B70[];
extern char lbl_40_data_8698[], lbl_40_data_6C60[], lbl_40_data_6A78[];
extern char lbl_40_data_6990[], lbl_27_bss_5FF4[], lbl_40_bss_2628[];
extern signed char lbl_40_bss_CB0;
extern GlobalObject lbl_40_bss_CB4;
extern soEventObserverRegistrationDesc* lbl_27_data_54C60;
extern const float lbl_40_rodata_758[];
void fn_27_262728(void*, void*, void*, void*, void*, void*, void*, void*);
void fn_27_26320C(void*);
void fn_27_2632F4(void*, int, float, float);
void fn_27_26F06C(void*, void*, void*, void*, void*, soEventObserverRegistrationDesc*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_40_2815C(void*);
void __dt__21soCollisionAttackPartFv(void*);
void fn_40_1DE00(void*);
void __dt__18soCollisionHitPartFv(void*);
void __ct__16soCollisionGroupFv(void*);
void fn_27_37D3C(void*);
void __ct__19soCollisionHitGroupFv(void*);
void __dt__19soCollisionHitGroupFv(void*);
void fn_40_1E2D4(void*);
void fn_40_1E2F8(void*);
void fn_40_1CB1C(void*);
void __register_global_object(GlobalObject&, void*, void*);
}

struct Bits {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 1;
    unsigned int rest : 25;
};

template<class T>
class ArrayView {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(const T&);
    virtual void v11();
    virtual void v12();
    virtual int v13();
    virtual bool v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual int v27();
    virtual int v28();
    void* calc;
    unsigned int flags;
    char parts[sizeof(T)];
};

struct GroupStorage {
    void* vt;
    void* calc;
    Bits bits;
    char elements[0x78];
};

struct HitGroupStorage {
    void* vt;
    void* calc;
    Bits bits;
    char elements[0x38];
};

struct AttackStorage {
    ArrayView<soCollisionAttackPart> parts;
    GroupStorage groups;
    void* absolutes;
    char impl[0xa0];
};

struct HitStorage {
    ArrayView<soCollisionHitPart> parts;
    GroupStorage groups;
    HitGroupStorage hitgroups;
    char impl[0x68];
};

struct Storage {
    void* vt;
    void* calc;
    Bits bits;
    char elements[0xa0];
};

struct PaddedData {
    char prefix[36];
    float a, b, c;
    char padding[56];
    PaddedData(float value) { a = value; b = value; c = value; }
};

class AbsoluteArrayStorage {
    void* table;
public:
    AbsoluteArrayStorage() : table(lbl_40_data_8698) {}
};

extern "C" void* fn_40_39098(char* self, char* arg) {
    const float* values = lbl_40_rodata_758;
    fn_27_262728(self, arg, lbl_40_data_14980, self + 0x47c,
                  self + 0x658, self + 0x76c, lbl_27_bss_598, lbl_27_bss_444);

    *(void**)(self + 0x3c) = lbl_40_data_126E4;
    *(void**)(self + 0x40) = lbl_40_data_126E4 + 0x64;
    *(void**)(self + 0x48) = lbl_40_data_126E4 + 0x70;
    *(void**)(self + 0x54) = lbl_40_data_126E4 + 0x84;
    *(void**)(self + 0x64) = lbl_40_data_126E4 + 0xdc;

    gfTask::Category category =
        (gfTask::Category)(unsigned char)(*(unsigned int*)(self + 0x2c) >> 7);
    AttackStorage* a = (AttackStorage*)(self + 0x358);
    soEventObserverRegistrationDesc* desc = lbl_27_data_54C60;
    int id = *(int*)(self + 0x28);

    {
        soCollisionAttackPart part((soCollision::Category)6, false);
        *(void**)&a->parts = lbl_40_data_83C0;
        a->parts.calc = lbl_40_data_83C0 + 0x48;
        a->parts.flags &= 0x01ffffff;
        __construct_array(a->parts.parts, fn_40_2815C,
                          __dt__21soCollisionAttackPartFv, 0x90, 1);
        int count = soArrayVectorCalculator::resize(
            *(soArrayVectorCalcInterface*)&a->parts.calc, 1, a->parts.v4(),
            a->parts.v14(), a->parts.v13(), a->parts.v27(), a->parts.v28());
        for (int i = 0; i < count; i++) a->parts.v10(part);
    }

    a->groups.vt = lbl_40_data_6B70;
    a->groups.calc = lbl_40_data_6B70 + 0x48;
    a->groups.bits.a = 0;
    a->groups.bits.b = 1;
    a->groups.bits.c = 0;
    __construct_array(a->groups.elements, __ct__16soCollisionGroupFv,
                      fn_27_37D3C, 0x78, 1);
    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&a->groups.calc, 1, 1);

    PaddedData data(values[0x78 / 4]);
    soArray<soCollisionAttackAbsolute>* absolutes =
        (soArray<soCollisionAttackAbsolute>*)new (&a->absolutes) AbsoluteArrayStorage;
    new (a->impl) soCollisionAttackModuleImpl(
        (soModuleAccesser*)(self + 0xa8), id, category,
        (soArray<soCollisionAttackPart>*)&a->parts,
        (soArray<soCollisionGroup>*)&a->groups,
        absolutes, desc, true);

    soEventObserverRegistrationDesc* hitDesc = lbl_27_data_54C60;
    HitStorage* h = (HitStorage*)(self + 0x51c);
    gfTask::Category hitCategory =
        (gfTask::Category)(unsigned char)(*(unsigned int*)(self + 0x2c) >> 7);
    int hitId = *(int*)(self + 0x28);

    {
        soCollisionHitPart part((soCollision::Category)6, 0x3ff);
        *(void**)&h->parts = lbl_40_data_6C60;
        h->parts.calc = lbl_40_data_6C60 + 0x48;
        h->parts.flags &= 0x01ffffff;
        __construct_array(h->parts.parts, fn_40_1DE00,
                          __dt__18soCollisionHitPartFv, 0x68, 1);
        int count = soArrayVectorCalculator::resize(
            *(soArrayVectorCalcInterface*)&h->parts.calc, 1, h->parts.v4(),
            h->parts.v14(), h->parts.v13(), h->parts.v27(), h->parts.v28());
        for (int i = 0; i < count; i++) h->parts.v10(part);
    }

    h->groups.vt = lbl_40_data_6B70;
    h->groups.calc = lbl_40_data_6B70 + 0x48;
    h->groups.bits.a = 0;
    h->groups.bits.b = 1;
    h->groups.bits.c = 0;
    __construct_array(h->groups.elements, __ct__16soCollisionGroupFv,
                      fn_27_37D3C, 0x78, 1);
    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&h->groups.calc, 1, 1);

    h->hitgroups.vt = lbl_40_data_6A78;
    h->hitgroups.calc = lbl_40_data_6A78 + 0x48;
    h->hitgroups.bits.a = 0;
    h->hitgroups.bits.b = 1;
    h->hitgroups.bits.c = 0;
    __construct_array(h->hitgroups.elements, __ct__19soCollisionHitGroupFv,
                      __dt__19soCollisionHitGroupFv, 0x38, 1);
    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&h->hitgroups.calc, 1, 1);

    new (h->impl) soCollisionHitModuleImpl(
        (soModuleAccesser*)(self + 0xa8), hitId, hitCategory,
        (soArray<soCollisionHitPart>*)&h->parts,
        (soArray<soCollisionGroup>*)&h->groups,
        (soArray<soCollisionHitGroup>*)&h->hitgroups, hitDesc, true);

    Storage* s = (Storage*)(self + 0x6c0);
    soEventObserverRegistrationDesc* desc2 = lbl_27_data_54C60;
    s->vt = lbl_40_data_6990;
    s->calc = lbl_40_data_6990 + 0x48;
    s->bits.a = 0;
    s->bits.b = 1;
    s->bits.c = 0;
    __construct_array(s->elements, fn_40_1E2D4, fn_40_1E2F8, 0xa0, 1);
    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&s->calc, 1, 1);

    if (!lbl_40_bss_CB0) {
        GlobalObject* object = new (&lbl_40_bss_CB4) GlobalObject;
        __register_global_object(*object, (void*)fn_40_1CB1C, lbl_40_bss_2628);
        lbl_40_bss_CB0 = 1;
    }

    fn_27_26F06C((char*)s + 0xac, self + 0xa8, s, lbl_27_bss_5FF4,
                  &lbl_40_bss_CB4, desc2);
    fn_27_26320C(self);
    fn_27_2632F4(self, *(int*)(arg + 0xc),
                  values[0x88 / 4], values[0]);
    return self;
}
