#include <new>
class soCollisionAttackModule;
#include <so/collision/so_collision_hit_module_impl.h>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" char lbl_48_data_EE8[];
struct GlobalObject {
    void* vtable;
    GlobalObject() { vtable = 0; vtable = lbl_48_data_EE8; }
};

extern "C" {
extern char lbl_48_data_3200[], lbl_27_bss_384[], lbl_27_bss_598[], lbl_27_bss_444[];
extern char lbl_48_data_1CD8[], lbl_48_data_2A58[], lbl_48_data_2B40[];
extern char lbl_48_data_2C38[], lbl_48_data_2D28[], lbl_48_data_EE8[];
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
    unsigned int top : 6;
    unsigned int last : 6;
    unsigned int size : 6;
    unsigned int full : 1;
    unsigned int rest : 13;
};
struct HitStorage {
    void* vt;
    void* calc;
    unsigned int flags;
    char parts[0xA28];
    void* vt2;
    void* calc2;
    ArrayBits bits2;
    char groups[0xBB8];
    void* vt3;
    void* calc3;
    ArrayBits bits3;
    char hitgroups[0x578];
    char impl[0x68];
};
struct OtherStorage {
    void* vt;
    void* calc;
    ArrayBits bits;
    char elements[0xA00];
};

extern "C" void* fn_48_870C(char* self, char* arg) {
    fn_27_262728(self, arg, lbl_48_data_3200, lbl_27_bss_384,
                 self + 0x1ED8, self + 0x2EEC, lbl_27_bss_598, lbl_27_bss_444);
    *(void**)(self + 0x3C) = lbl_48_data_1CD8;
    *(void**)(self + 0x40) = lbl_48_data_1CD8 + 0x64;
    *(void**)(self + 0x48) = lbl_48_data_1CD8 + 0x70;
    *(void**)(self + 0x54) = lbl_48_data_1CD8 + 0x84;
    *(void**)(self + 0x64) = lbl_48_data_1CD8 + 0xDC;

    gfTask::Category category =
        (gfTask::Category)(unsigned char)(*(unsigned int*)(self + 0x2C) >> 7);
    HitStorage* h = (HitStorage*)(self + 0x35C);
    soEventObserverRegistrationDesc* desc = lbl_27_data_54C60;
    int id = *(int*)(self + 0x28);
    {
        soCollisionHitPart part((soCollision::Category)6, 0x3FF);
        h->vt = lbl_48_data_2D28;
        h->calc = lbl_48_data_2D28 + 0x48;
        h->flags &= 0x1FFF;
        __construct_array(h->parts, fn_48_39F0,
                          (void (*)(void*))__dt__18soCollisionHitPartFv, 0x68, 0x19);
        bool full;
        int capacity, top, last;
        last = ((soArrayVectorAbstract<soCollisionHitPart>*)h)->getLastIndex();
        top = ((soArrayVectorAbstract<soCollisionHitPart>*)h)->getTopIndex();
        capacity = ((soArrayVectorAbstract<soCollisionHitPart>*)h)->capacity();
        full = ((soArrayVectorAbstract<soCollisionHitPart>*)h)->isFull();
        bool empty = ((HitArrayInterface*)h)->isEmpty();
        int count = soArrayVectorCalculator::resize(
            *(soArrayVectorCalcInterface*)&h->calc, 0x19, empty, full, capacity, top, last);
        for (int i = 0; i < count; ++i) {
            ((soArray<soCollisionHitPart>*)h)->push(part);
        }
    }
    h->vt2 = lbl_48_data_2C38;
    h->calc2 = lbl_48_data_2C38 + 0x48;
    h->bits2.top = 0;
    h->bits2.last = 0;
    h->bits2.size = 0x19;
    h->bits2.full = 0;
    __construct_array(h->groups, (void (*)(void*))__ct__16soCollisionGroupFv,
                      fn_27_37D3C, 0x78, 0x19);
    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&h->calc2, 0x19, 0x19);
    h->vt3 = lbl_48_data_2B40;
    h->calc3 = lbl_48_data_2B40 + 0x48;
    h->bits3.top = 0;
    h->bits3.last = 0;
    h->bits3.size = 0x19;
    h->bits3.full = 0;
    __construct_array(h->hitgroups, (void (*)(void*))__ct__19soCollisionHitGroupFv,
                      (void (*)(void*))__dt__19soCollisionHitGroupFv, 0x38, 0x19);
    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&h->calc3, 0x19, 0x19);
    new (h->impl) soCollisionHitModuleImpl(
        (soModuleAccesser*)(self + 0xA8), id, category,
        (soArray<soCollisionHitPart>*)h, (soArray<soCollisionGroup>*)&h->vt2,
        (soArray<soCollisionHitGroup>*)&h->vt3, desc, true);

    OtherStorage* s = (OtherStorage*)(self + 0x1F40);
    soEventObserverRegistrationDesc* desc2 = lbl_27_data_54C60;
    s->vt = lbl_48_data_2A58;
    s->calc = lbl_48_data_2A58 + 0x48;
    s->bits.top = 0;
    s->bits.last = 0;
    s->bits.size = 0x19;
    s->bits.full = 0;
    __construct_array(s->elements, fn_48_3E2C, fn_48_3E50, 0xA0, 0x19);
    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&s->calc, 0x19, 0x19);
    if (!lbl_48_bss_48) {
        GlobalObject* object = new (&lbl_48_bss_4C) GlobalObject;
        __register_global_object(*object, (void*)fn_48_3040, lbl_48_bss_50);
        lbl_48_bss_48 = 1;
    }
    fn_27_26F06C((char*)s + 0xFAC, self + 0xA8, s, lbl_27_bss_5FF4,
                  &lbl_48_bss_4C, desc2);
    fn_27_26320C(self);
    fn_27_2632F4(self, *(int*)(arg + 0xC),
                  lbl_48_rodata_6C, lbl_48_rodata_48);
    return self;
}