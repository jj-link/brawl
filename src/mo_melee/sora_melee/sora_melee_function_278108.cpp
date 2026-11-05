#include <new>
class soCollisionAttackModule;
#include <so/collision/so_collision_hit_module_impl.h>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" char lbl_27_data_B620[];
struct GlobalObject {
    void* vtable;
    GlobalObject() { vtable = 0; vtable = lbl_27_data_B620; }
};

extern "C" {
extern char lbl_27_data_5A1F0[], lbl_27_bss_384[], lbl_27_bss_598[], lbl_27_bss_444[];
extern char lbl_27_data_59070[], lbl_27_data_39430[], lbl_27_data_46F8[], lbl_27_data_1E0A0[];
extern char lbl_27_data_1A108[], lbl_27_data_B620[], lbl_27_bss_63B0[], lbl_27_bss_5FF4[];
extern signed char lbl_27_bss_1088;
extern GlobalObject lbl_27_bss_108C;
extern soEventObserverRegistrationDesc* lbl_27_data_54C60;
extern float lbl_27_rodata_453C, lbl_27_rodata_4520;
void fn_27_262728(void*, void*, void*, void*, void*, void*, void*, void*);
void fn_27_26320C(void*);
void fn_27_2632F4(void*, int, float, float);
void fn_27_26F06C(void*, void*, void*, void*, void*, soEventObserverRegistrationDesc*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__18soCollisionHitPartFv(void*);
void __dt__18soCollisionHitPartFv(void*);
void __ct__16soCollisionGroupFv(void*);
void fn_27_37D3C(void*);
void __ct__19soCollisionHitGroupFv(void*);
void __dt__19soCollisionHitGroupFv(void*);
void fn_27_D3188(void*);
void fn_27_86D4C(void*);
void fn_27_7DC10(void*);
void __register_global_object(GlobalObject&, void*, void*);
}
struct Bits { unsigned int a:4, b:2, c:1, rest:25; };
class Class_14370 {
public:
    virtual void fn_27_93100();
    virtual void fn_27_9329C();
    virtual void fn_27_932A0();
    virtual void fn_27_93778();
    virtual bool fn_27_95264();
    virtual void fn_27_93860();
    virtual void fn_27_94198();
    virtual void fn_27_942B4();
    virtual void fn_27_943C4();
    virtual void fn_27_944D4();
    virtual void fn_27_94748(const soCollisionHitPart&);
    virtual void fn_27_9483C();
    virtual void fn_27_94930();
    virtual int fn_27_94E00();
    virtual bool fn_27_94C38();
    virtual void fn_27_93B80();
    virtual void fn_27_93F8C();
    virtual void fn_27_94A40();
    virtual void fn_27_94AA0();
    virtual void fn_27_94AD0();
    virtual void fn_27_94B00();
    virtual void fn_27_94B30();
    virtual void fn_27_94B60();
    virtual void fn_27_94B90();
    virtual void fn_27_94BC0();
    virtual void fn_27_94BF0();
    virtual void fn_27_94C20();
    virtual int fn_27_973EC();
    virtual int fn_27_973F4();
    void* calc; unsigned int flags; char parts[0x68];
    void* vt2; void* calc2; Bits bits2; char groups[0x78];
    void* vt3; void* calc3; Bits bits3; char hitgroups[0x38];
    char impl[0x68];
};
struct Storage {
    void* vt;
    void* calc;
    Bits bits;
    char elements[0xa0];
};
extern "C" void* fn_27_278108(char* self, char* arg) {
    fn_27_262728(self, arg, lbl_27_data_5A1F0, lbl_27_bss_384,
        self + 0x498, self + 0x5ac, lbl_27_bss_598, lbl_27_bss_444);
    *(void**)(self+0x3c) = lbl_27_data_59070;
    *(void**)(self+0x40) = lbl_27_data_59070+0x64;
    *(void**)(self+0x48) = lbl_27_data_59070+0x70;
    *(void**)(self+0x54) = lbl_27_data_59070+0x84;
    *(void**)(self+0x64) = lbl_27_data_59070+0xdc;
    gfTask::Category category = (gfTask::Category)(unsigned char)(*(unsigned int*)(self+0x2c)>>7);
    Class_14370* h = (Class_14370*)(self+0x35c);
    soEventObserverRegistrationDesc* desc = lbl_27_data_54C60;
    int id = *(int*)(self+0x28);
    {
        soCollisionHitPart part((soCollision::Category)6, 0x3ff);
        *(void**)h = lbl_27_data_39430;
        h->calc = lbl_27_data_39430+0x48;
        h->flags &= 0x01ffffff;
        __construct_array(h->parts, __ct__18soCollisionHitPartFv, __dt__18soCollisionHitPartFv, 0x68, 1);
        bool d;
        int c, b, a;
        a = h->fn_27_973F4();
        b = h->fn_27_973EC();
        c = h->fn_27_94E00();
        d = h->fn_27_94C38();
        bool e = h->fn_27_95264();
        int count = soArrayVectorCalculator::resize(*(soArrayVectorCalcInterface*)&h->calc, 1, e, d, c, b, a);
        for (int i=0; i<count; ++i) h->fn_27_94748(part);
    }
    h->vt2 = lbl_27_data_46F8;
    h->calc2 = lbl_27_data_46F8+0x48;
    h->bits2.a=0; h->bits2.b=1; h->bits2.c=0;
    __construct_array(h->groups, __ct__16soCollisionGroupFv, fn_27_37D3C, 0x78, 1);
    soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)&h->calc2, 1, 1);
    h->vt3 = lbl_27_data_1E0A0;
    h->calc3 = lbl_27_data_1E0A0+0x48;
    h->bits3.a=0; h->bits3.b=1; h->bits3.c=0;
    __construct_array(h->hitgroups, __ct__19soCollisionHitGroupFv, __dt__19soCollisionHitGroupFv, 0x38, 1);
    soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)&h->calc3, 1, 1);
    new (h->impl) soCollisionHitModuleImpl((soModuleAccesser*)(self+0xa8), id, category,
        (soArray<soCollisionHitPart>*)h, (soArray<soCollisionGroup>*)&h->vt2,
        (soArray<soCollisionHitGroup>*)&h->vt3, desc, true);
    Storage* s = (Storage*)(self+0x500);
    soEventObserverRegistrationDesc* desc2 = lbl_27_data_54C60;
    s->vt = lbl_27_data_1A108;
    s->calc = lbl_27_data_1A108+0x48;
    s->bits.a=0; s->bits.b=1; s->bits.c=0;
    __construct_array(s->elements, fn_27_D3188, fn_27_86D4C, 0xa0, 1);
    soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)&s->calc, 1, 1);
    if (!lbl_27_bss_1088) {
        GlobalObject* object = new (&lbl_27_bss_108C) GlobalObject;
        __register_global_object(*object, (void*)fn_27_7DC10, lbl_27_bss_63B0);
        lbl_27_bss_1088=1;
    }
    fn_27_26F06C((char*)s+0xac, self+0xa8, s, lbl_27_bss_5FF4, &lbl_27_bss_108C, desc2);
    fn_27_26320C(self);
    fn_27_2632F4(self, *(int*)(arg+0xc), lbl_27_rodata_453C, lbl_27_rodata_4520);
    return self;
}
