#include <new>
#include <types.h>
#include <gr/gr_gimmick.h>
#include <so/collision/so_collision_attack_part.h>
#include <so/collision/so_collision_attack_module_impl.h>
#include <so/so_array_vector_calculator.h>
#pragma force_active on
#pragma use_simple_stdpnew on

class IVirtual {
public:
    virtual int slot8(void*);
};
struct ObjectBase { char pad[0x3c]; };
class Object : public ObjectBase {
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
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
};
struct Ctx {
    void* self;
    void* unk4;
    int unk8;
    Vec3f* pos;
    void* unk10;
};
static inline const Ctx& getCtx(const void* p) { return *(const Ctx*)p; }
struct RodataConsts {
    void* w0;
    void* w4;
    int w8;
    void* wC;
    void* w10;
    float f14;
    float f18;
    float f1c;
};
struct GroupBits { unsigned int top:2, last:2, size:2, full:1, rest:25; };
struct AttackArray {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual bool v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(const soCollisionAttackPart&);
    virtual void v11(); virtual void v12();
    virtual int v13();
    virtual bool v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26();
    virtual int v27();
    virtual int v28();
    void* calc; unsigned int flags; char parts[0x90];
    void* vt2; void* calc2; GroupBits bits2; char groups[0x78];
    void* vt3; char impl[0xa0];
};
struct PaddedData {
    char prefix[36];
    float a,b,c;
    char padding[56];
    PaddedData(float value) { a=value; b=value; c=value; }
};
extern "C" char lbl_40_data_8520[], lbl_40_data_5028[], lbl_40_data_8698[];
class AbsoluteArrayStorage {
    void* table;
public:
    AbsoluteArrayStorage() : table(lbl_40_data_8698) {}
};
struct Global1 {
    void* vtable;
    Global1() { vtable = 0; vtable = lbl_40_data_8520; }
};
struct Global2 {
    void* vtable;
    Global2() { vtable = 0; vtable = lbl_40_data_5028; }
};
extern "C" {
extern RodataConsts lbl_40_rodata_448;
extern char lbl_40_data_88D8[], lbl_27_bss_398[], lbl_27_bss_444[], lbl_27_bss_598[], lbl_27_bss_5FF4[];
extern char lbl_40_data_7FB0[], lbl_40_data_83C0[], lbl_40_data_6B70[], lbl_40_data_8698[];
extern char lbl_40_data_8520[], lbl_40_data_5028[], lbl_40_bss_1668[], lbl_40_bss_1674[], lbl_8040ABD8[];
extern soEventObserverRegistrationDesc* lbl_27_data_54C60;
extern void* lbl_40_bss_11D4;
extern void* lbl_40_bss_CB4;
extern signed char lbl_40_bss_11D0, lbl_40_bss_CB0;
void fn_27_272E30(void*, void*, unsigned long, unsigned long);
void fn_27_262728(void*, void*, void*, void*, void*, void*, void*, void*);
void fn_27_26320C(void*);
void fn_27_2632F4(void*, void*, float, float);
void fn_27_264D9C(void*, void*);
void fn_27_26F06C(void*, void*, void*, void*, void*, void*);
void fn_40_2815C(void*);
void fn_27_37D3C(void*);
void __ct__16soCollisionGroupFv(void*);
void __dt__21soCollisionAttackPartFv(void*);
void fn_40_280DC(void*);
void fn_40_1CB1C(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __register_global_object(void*, void*, void*);
}
#pragma push
#pragma opt_propagation off
#pragma pool_data on
extern "C" void fn_40_2A628(void* arg0, void* archive, unsigned long x, unsigned long y)
{
    char* s = (char*)arg0;
    fn_27_272E30(arg0, archive, x, y);
    *(void**)(s + 0x154) = *(void**)(s + 0xBC);
    *(int*)(s + 0x158) = 0;
    *(int*)(s + 0x15C) = 0;
    void* r21;
    int r22 = 0;
    Ctx ctx = { 0, 0, 17, 0, 0 };
    ctx.self = arg0;
    r21 = *(void**)*(void**)(s + 0x44);
    if (r21 != 0) {
        void* key = lbl_8040ABD8;
        if (((IVirtual*)r21)->slot8(&key)) r22 = 1;
    }
    ctx.unk4 = r22 ? r21 : 0;
    Vec3f pos = ((grGimmick*)arg0)->getPos();
    ctx.pos = &pos;
    ctx.unk10 = s + 0x158;
    char* t = (char*)operator new(0x5D0, (Heaps::HeapType)0xF);
    if (t != 0) {
        fn_27_262728(t, &ctx, lbl_40_data_88D8, t + 0x47C, lbl_27_bss_398, t + 0x524, lbl_27_bss_598, lbl_27_bss_444);
        *(void**)(t + 0x3C) = lbl_40_data_7FB0;
        *(void**)(t + 0x40) = lbl_40_data_7FB0 + 0x64;
        *(void**)(t + 0x48) = lbl_40_data_7FB0 + 0x70;
        *(void**)(t + 0x54) = lbl_40_data_7FB0 + 0x84;
        *(void**)(t + 0x64) = lbl_40_data_7FB0 + 0xDC;
        unsigned char r29;
        AttackArray* h;
        soEventObserverRegistrationDesc* r27;
        int r26;
        h = (AttackArray*)(t + 0x358);
        r27 = lbl_27_data_54C60;
        r26 = *(int*)(t + 0x28);
        r29 = (unsigned char)((*(unsigned int*)(t + 0x2C)) >> 7);
        {
            soCollisionAttackPart part((soCollision::Category)6, false);
            *(void**)h = lbl_40_data_83C0;
            h->calc = lbl_40_data_83C0 + 0x48;
            h->flags &= 0x01FFFFFF;
            __construct_array(h->parts, fn_40_2815C, __dt__21soCollisionAttackPartFv, 0x90, 1);
            int count = soArrayVectorCalculator::resize(*(soArrayVectorCalcInterface*)&h->calc, 1,
                h->v4(), h->v14(), h->v13(), h->v27(), h->v28());
            for (int i = 0; i < count; i++) h->v10(part);
        }
        h->vt2 = lbl_40_data_6B70;
        h->calc2 = lbl_40_data_6B70 + 0x48;
        h->bits2.top=0; h->bits2.last=0; h->bits2.size=1; h->bits2.full=0;
        __construct_array(h->groups, __ct__16soCollisionGroupFv, fn_27_37D3C, 0x78, 1);
        soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)&h->calc2, 1, 1);
        PaddedData data(1.0f);
        soArray<soCollisionAttackAbsolute>* absolutes = (soArray<soCollisionAttackAbsolute>*)new (&h->vt3) AbsoluteArrayStorage;
        new (h->impl) soCollisionAttackModuleImpl((soModuleAccesser*)(t + 0xA8), r26, (gfTask::Category)r29,
            (soArray<soCollisionAttackPart>*)h, (soArray<soCollisionGroup>*)&h->vt2,
            absolutes, r27, true);
        void** global1;
        soEventObserverRegistrationDesc* desc2 = lbl_27_data_54C60;
        if (lbl_40_bss_11D0 == 0) {
            Global1* obj = new (&lbl_40_bss_11D4) Global1;
            __register_global_object(obj, (void*)fn_40_280DC, lbl_40_bss_1674);
            lbl_40_bss_11D0 = 1;
        }
        global1 = &lbl_40_bss_11D4;
        if (lbl_40_bss_CB0 == 0) {
            Global2* obj = new (&lbl_40_bss_CB4) Global2;
            __register_global_object(obj, (void*)fn_40_1CB1C, lbl_40_bss_1668);
            lbl_40_bss_CB0 = 1;
        }
        fn_27_26F06C(t + 0x524, t + 0xA8, global1, lbl_27_bss_5FF4, &lbl_40_bss_CB4, desc2);
        fn_27_26320C(t);
        fn_27_2632F4(t, ctx.pos, -1.0f, 0.0f);
    }
    fn_27_264D9C(arg0, t);
    ((Object*)arg0)->slot112();
}
#pragma pop