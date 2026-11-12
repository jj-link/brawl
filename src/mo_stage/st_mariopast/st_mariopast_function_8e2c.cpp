#include <new>
class soCollisionAttackModule;
#include <so/collision/so_collision_hit_module_impl.h>

#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" char lbl_48_data_EE8[];

struct GlobalObject {
    void* vtable;
    GlobalObject() {
        vtable = 0;
        vtable = lbl_48_data_EE8;
    }
};

extern "C" {
extern char lbl_48_data_31E8[], lbl_27_bss_384[], lbl_27_bss_598[], lbl_27_bss_444[];
extern char lbl_48_data_1908[], lbl_48_data_2598[], lbl_48_data_24A0[];
extern char lbl_48_data_23A8[], lbl_48_data_22B8[];
extern char lbl_48_bss_50[], lbl_27_bss_5FF4[];
extern signed char lbl_48_bss_48;
extern GlobalObject lbl_48_bss_4C;
extern soEventObserverRegistrationDesc* lbl_27_data_54C60;
extern float lbl_48_rodata_48, lbl_48_rodata_6C;

void fn_27_262728(void*, void*, void*, void*, void*, void*, void*, void*);
void fn_27_26320C(void*);
void fn_27_2632F4(void*, int, float, float);
void fn_27_26F06C(void*, void*, void*, void*, void*, soEventObserverRegistrationDesc*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_48_39F0(void*);
void __dt__18soCollisionHitPartFv(void*);
void __ct__16soCollisionGroupFv(void*);
void fn_27_37D3C(void*);
void __ct__19soCollisionHitGroupFv(void*);
void __dt__19soCollisionHitGroupFv(void*);
void fn_48_3E2C(void*);
void fn_48_3E50(void*);
void fn_48_3040(void*);
void __register_global_object(GlobalObject&, void*, void*);
}

class HitArrayInterface : public soArrayVectorAbstract<soCollisionHitPart> {
public:
    virtual bool isEmpty() const = 0;
};

struct ArrayBits {
    unsigned int top : 9;
    unsigned int last : 9;
    unsigned int size : 9;
    unsigned int full : 1;
    unsigned int rest : 4;
};

struct HitStorage {
    void* vt;
    void* calc;
    unsigned int flags;
    char parts[0x5348];
    void* vt2;
    void* calc2;
    ArrayBits bits2;
    char groups[0x6018];
    void* vt3;
    void* calc3;
    ArrayBits bits3;
    char hitgroups[0x2cd8];
    char impl[0x68];
};

struct ThirdStorage {
    void* vt;
    void* calc;
    ArrayBits bits;
    char hitgroups[0x2cd8];
    char impl[0x68];
};

struct OtherStorage {
    void* vt;
    void* calc;
    ArrayBits bits;
    char elements[0x8020];
};

extern "C" void* fn_48_8E2C(char* self, char* arg) {
    OtherStorage* s;
    fn_27_262728(self, arg, lbl_48_data_31E8, lbl_27_bss_384,
                 self + 0xe3b8, self + 0x1644c, lbl_27_bss_598,
                 lbl_27_bss_444);

    *(void**)(self + 0x3c) = lbl_48_data_1908;
    *(void**)(self + 0x40) = lbl_48_data_1908 + 0x64;
    *(void**)(self + 0x48) = lbl_48_data_1908 + 0x70;
    *(void**)(self + 0x54) = lbl_48_data_1908 + 0x84;
    *(void**)(self + 0x64) = lbl_48_data_1908 + 0xdc;

    gfTask::Category category =
        (gfTask::Category)(unsigned char)(*(unsigned int*)(self + 0x2c) >> 7);
    HitStorage* h = (HitStorage*)(self + 0x35c);
    soEventObserverRegistrationDesc* desc = lbl_27_data_54C60;
    int id = *(int*)(self + 0x28);

    {
        soCollisionHitPart part((soCollision::Category)6, 0x3ff);
        h->vt = lbl_48_data_2598;
        h->calc = lbl_48_data_2598 + 0x48;
        h->flags &= 0xf;
        __construct_array(h->parts, fn_48_39F0, __dt__18soCollisionHitPartFv,
                          0x68, 0xcd);

        bool full;
        int capacity, top, last;
        last = ((soArrayVectorAbstract<soCollisionHitPart>*)h)->getLastIndex();
        top = ((soArrayVectorAbstract<soCollisionHitPart>*)h)->getTopIndex();
        capacity = ((soArrayVectorAbstract<soCollisionHitPart>*)h)->capacity();
        full = ((soArrayVectorAbstract<soCollisionHitPart>*)h)->isFull();
        bool empty = ((HitArrayInterface*)h)->isEmpty();
        int count = soArrayVectorCalculator::resize(
            *(soArrayVectorCalcInterface*)&h->calc, 0xcd, empty, full,
            capacity, top, last);
        for (int i = 0; i < count; ++i)
            ((soArray<soCollisionHitPart>*)h)->push(part);
    }

    h->vt2 = lbl_48_data_24A0;
    h->calc2 = lbl_48_data_24A0 + 0x48;
    h->bits2.top = 0;
    h->bits2.last = 0;
    h->bits2.size = 0xcd;
    h->bits2.full = 0;
    __construct_array(h->groups, __ct__16soCollisionGroupFv, fn_27_37D3C,
                      0x78, 0xcd);
    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&h->calc2, 0xcd, 0xcd);

    char* third = (char*)h + 0x10000;
    ((ThirdStorage*)(third - 0x4c88))->vt = lbl_48_data_23A8;
    ((ThirdStorage*)(third - 0x4c88))->calc = lbl_48_data_23A8 + 0x48;
    ((ThirdStorage*)(third - 0x4c88))->bits.top = 0;
    ((ThirdStorage*)(third - 0x4c88))->bits.last = 0;
    ((ThirdStorage*)(third - 0x4c88))->bits.size = 0xcd;
    ((ThirdStorage*)(third - 0x4c88))->bits.full = 0;
    __construct_array(third - 0x4c7c, __ct__19soCollisionHitGroupFv,
                      __dt__19soCollisionHitGroupFv, 0x38, 0xcd);
    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)(third - 0x4c84), 0xcd, 0xcd);

    new (h->impl) soCollisionHitModuleImpl(
        (soModuleAccesser*)(self + 0xa8), id, category,
        (soArray<soCollisionHitPart>*)h,
        (soArray<soCollisionGroup>*)&h->vt2,
        (soArray<soCollisionHitGroup>*)&h->vt3, desc, true);

    char* base = self + 0x10000;
    soEventObserverRegistrationDesc* desc2 = lbl_27_data_54C60;
    ((OtherStorage*)(base - 0x1be0))->vt = lbl_48_data_22B8;
    ((OtherStorage*)(base - 0x1be0))->calc = lbl_48_data_22B8 + 0x48;
    ((OtherStorage*)(base - 0x1be0))->bits.top = 0;
    ((OtherStorage*)(base - 0x1be0))->bits.last = 0;
    ((OtherStorage*)(base - 0x1be0))->bits.size = 0xcd;
    ((OtherStorage*)(base - 0x1be0))->bits.full = 0;
    __construct_array((base -= 0x1be0) + 0xc, fn_48_3E2C, fn_48_3E50, 0xa0, 0xcd);
    s = (OtherStorage*)base;
    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&s->calc, 0xcd, 0xcd);

    if (!lbl_48_bss_48) {
        GlobalObject* object = new (&lbl_48_bss_4C) GlobalObject;
        __register_global_object(*object, (void*)fn_48_3040, lbl_48_bss_50);
        lbl_48_bss_48 = 1;
    }

    fn_27_26F06C((char*)s + 0x802c, self + 0xa8, s, lbl_27_bss_5FF4,
                 &lbl_48_bss_4C, desc2);
    fn_27_26320C(self);
    fn_27_2632F4(self, *(int*)(arg + 0xc), lbl_48_rodata_6C,
                 lbl_48_rodata_48);
    return self;
}
