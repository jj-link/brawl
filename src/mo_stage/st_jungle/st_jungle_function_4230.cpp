// CodeWarrior check reached 99.9%. Three instructions use r31 in place of
// r27, and two relocations reference the compiler's literal pool.

#include <new>
#include <types.h>
#include <sr/sr_common.h>
#include <gr/gr_gimmick.h>
#include <nw4r/g3d/g3d_obj.h>
#include <so/collision/so_collision_attack_module_impl.h>
#include <so/collision/so_collision_hit_module_impl.h>

#pragma force_active on
#pragma use_simple_stdpnew on

struct GlobalObject;

extern "C" {
typedef void (*ArrayCallback)(void*);

extern char lbl_51_data_2BF8[], lbl_51_data_145C[], lbl_51_data_2248[];
extern char lbl_51_data_20F8[], lbl_51_data_2538[], lbl_51_data_1FA0[];
extern char lbl_51_data_1E48[], lbl_51_data_1D08[], lbl_51_data_1738[];
extern char lbl_27_bss_598[], lbl_27_bss_444[], lbl_27_bss_5FF4[];
extern char lbl_51_bss_24[], lbl_8040ABD8[];
extern signed char lbl_51_bss_58;
extern GlobalObject lbl_51_bss_5C;
extern soEventObserverRegistrationDesc* lbl_27_data_54C60;

void __construct_array(void*, ArrayCallback, ArrayCallback, unsigned long, int);
void __register_global_object(GlobalObject&, void*, void*);
void fn_27_262728(void*, void*, void*, void*, void*, void*, void*, void*);
void fn_27_26320C(void*);
void fn_27_2632F4(void*, void*, float, float);
void fn_27_264D9C(void*, void*);
void fn_27_26F06C(void*, void*, void*, void*, void*, soEventObserverRegistrationDesc*);
void* __dt__21soCollisionAttackPartFv(void*, short);
void* __dt__18soCollisionHitPartFv(void*, short);
void* __ct__16soCollisionGroupFv(void*);
void* __ct__19soCollisionHitGroupFv(void*);
void* __dt__19soCollisionHitGroupFv(void*, short);

void* fn_27_37D3C(void*, short);
void* fn_51_59A8(void*, short);
void* fn_51_583C(void*, short);
void* fn_51_6254(void*, short);
void* fn_51_6278(void*, short);
void fn_51_4A00(void*);
}

struct GlobalObject {
    void* vtable;

    GlobalObject() : vtable(0) {
        vtable = lbl_51_data_1738;
    }
};

struct Bits {
    unsigned int top : 4;
    unsigned int last : 2;
    unsigned int full : 1;
    unsigned int rest : 25;
};

struct AttackArray : soArrayVectorAbstract<soCollisionAttackPart> {
    virtual bool isEmpty() const = 0;
};

struct HitArray : soArrayVectorAbstract<soCollisionHitPart> {
    virtual bool isEmpty() const = 0;
};

static inline u32 isModel(nw4r::g3d::G3dObj* object) {
    char* key = lbl_8040ABD8;
    return object->IsDerivedFrom((int*)&key);
}

struct AttackStorage {
    void* vt;
    void* calc;
    unsigned int flags;
    char elements[0x90];
    void* groupVt;
    void* groupCalc;
    Bits groupBits;
    char groups[0x78];
    void* absoluteVt;
};

struct HitStorage {
    void* vt;
    void* calc;
    unsigned int flags;
    char parts[0x68];
    void* groupVt;
    void* groupCalc;
    Bits groupBits;
    char groups[0x78];
    void* hitGroupVt;
    void* hitGroupCalc;
    Bits hitGroupBits;
    char hitGroups[0x38];
    char impl[0x68];
};

struct OtherStorage {
    void* vt;
    void* calc;
    Bits bits;
    char elements[0xa0];
};

struct Context {
    void* self;
    void* observer;
    int kind;
    void* pos;
    void* data;
};

struct PaddedData {
    char prefix[36];
    float slipChance;
    float hitStopFrame;
    float hitStopDelay;
    char padding[56];

    PaddedData() {
        slipChance = 1.0f;
        hitStopFrame = 1.0f;
        hitStopDelay = 1.0f;
    }
};

struct ObjView {
    char pad[0xA8];
    char accesser[4];
};

struct V3 {
    float v[3];
};

struct Shape {
    V3 a;
    V3 b;
    float c;
    unsigned char flag;
};

extern "C" void fn_51_4230(void* self) {
    ObjView* obj;
    soEventObserverRegistrationDesc* attackDesc;
    AttackStorage* attack;
    gfTask::Category attackCategory;
    int found;
    *(void**)((char*)self + 0x180) = operator new(0x20, Heaps::StageInstance);
    *(void**)((char*)self + 0x184) = operator new(0x28, Heaps::StageInstance);
    *(void**)((char*)self + 0x188) = operator new(8, Heaps::StageInstance);

    void* p = operator new(0xC, Heaps::StageInstance);
    if (p) {
        *(int*)p = 0;
        *(int*)((char*)p + 4) = 0;
        *(int*)((char*)p + 8) = 0;
    }
    *(void**)((char*)self + 0x18C) = p;

    p = operator new(8, Heaps::StageInstance);
    if (p) {
        *(int*)p = 0;
        *(int*)((char*)p + 4) = 0;
    }
    *(void**)((char*)self + 0x190) = p;

    (*(Shape**)((char*)self + 0x180))->a.v[0] = 0.0f;
    (*(Shape**)((char*)self + 0x180))->a.v[1] = 0.0f;
    (*(Shape**)((char*)self + 0x180))->a.v[2] = 0.0f;
    (*(Shape**)((char*)self + 0x180))->b.v[0] = 0.0f;
    (*(Shape**)((char*)self + 0x180))->b.v[1] = 0.0f;
    (*(Shape**)((char*)self + 0x180))->b.v[2] = 0.0f;
    (*(Shape**)((char*)self + 0x180))->c = 1.0f;
    (*(Shape**)((char*)self + 0x180))->flag |= 0x80;

    **(Shape**)((char*)self + 0x184) = **(Shape**)((char*)self + 0x180);
    *(int*)((char*)*(void**)((char*)self + 0x184) + 0x20) = 1;
    *(int*)((char*)*(void**)((char*)self + 0x184) + 0x24) = *(int*)((char*)self + 0x198);
    *(void**)*(void**)((char*)self + 0x188) = *(void**)((char*)self + 0x184);
    *(int*)((char*)*(void**)((char*)self + 0x188) + 4) = 1;
    *(void**)((char*)*(void**)((char*)self + 0x18C) + 4) =
        *(void**)((char*)self + 0x188);
    *(int*)*(void**)((char*)self + 0x18C) = 0;
    *(int*)*(void**)((char*)self + 0x190) = 1;
    *(void**)((char*)*(void**)((char*)self + 0x190) + 4) =
        *(void**)((char*)self + 0x18C);

    Context context = {0, 0, 16, 0, 0};
    context.self = self;

    nw4r::g3d::G3dObj* model = **(nw4r::g3d::G3dObj***)((char*)self + 0x44);
    found = 0;
    if (model != 0) {
        if (isModel(model)) found = 1;
    }
    context.observer = found ? model : 0;

    Vec3f pos = ((grGimmick*)self)->getPos();
    context.pos = &pos;
    context.data = *(void**)((char*)self + 0x190);

    obj = (ObjView*)operator new(0x818, Heaps::StageInstance);
    if (obj) {
        fn_27_262728(obj, &context, lbl_51_data_2BF8,
                     (char*)obj + 0x47C, (char*)obj + 0x658,
                     (char*)obj + 0x76C, lbl_27_bss_598, lbl_27_bss_444);

        *(void**)((char*)obj + 0x3C) = lbl_51_data_145C;
        *(void**)((char*)obj + 0x40) = lbl_51_data_145C + 0x64;
        *(void**)((char*)obj + 0x48) = lbl_51_data_145C + 0x70;
        *(void**)((char*)obj + 0x54) = lbl_51_data_145C + 0x84;
        *(void**)((char*)obj + 0x64) = lbl_51_data_145C + 0xDC;

        u32 hitPartStorage[sizeof(soCollisionHitPart) / sizeof(u32)];
        {
            attackDesc = lbl_27_data_54C60;
            attack = (AttackStorage*)((char*)obj + 0x358);
            attackCategory =
                (gfTask::Category)(unsigned char)(*(unsigned int*)((char*)obj + 0x2C) >> 7);
            int attackId = *(int*)((char*)obj + 0x28);

            {
                soCollisionAttackPart part((soCollision::Category)6, false);
                attack->vt = lbl_51_data_2248;
                attack->calc = lbl_51_data_2248 + 0x48;
                attack->flags &= 0x01FFFFFF;
                __construct_array(attack->elements, (ArrayCallback)fn_51_59A8,
                                  (ArrayCallback)__dt__21soCollisionAttackPartFv, 0x90, 1);

                AttackArray* array = (AttackArray*)attack;
                s32 count = soArrayVectorCalculator::resize(
                    *(soArrayVectorCalcInterface*)&attack->calc, 1, array->isEmpty(),
                    array->isFull(), array->capacity(), array->getTopIndex(), array->getLastIndex());
                for (s32 i = 0; i < count; ++i)
                    ((soArray<soCollisionAttackPart>*)attack)->push(part);
            }

            attack->groupVt = lbl_51_data_20F8;
            attack->groupCalc = lbl_51_data_20F8 + 0x48;
            attack->groupBits.top = 0;
            attack->groupBits.last = 1;
            attack->groupBits.full = 0;
            __construct_array(attack->groups, (ArrayCallback)__ct__16soCollisionGroupFv,
                              (ArrayCallback)fn_27_37D3C, 0x78, 1);
            soArrayVectorCalculator::postInitialize(
                *(soArrayVectorCalcInterface*)&attack->groupCalc, 1, 1);

            soArray<soCollisionAttackAbsolute>* absolute =
                (soArray<soCollisionAttackAbsolute>*)&attack->absoluteVt;
            *(void**)absolute = lbl_51_data_2538;
            PaddedData x;
            new ((char*)attack + 0x124) soCollisionAttackModuleImpl(
                (soModuleAccesser*)obj->accesser, attackId, attackCategory,
                (soArray<soCollisionAttackPart>*)attack,
                (soArray<soCollisionGroup>*)&attack->groupVt,
                absolute,
                attackDesc, true);
        }

        {
            soEventObserverRegistrationDesc* hitDesc = lbl_27_data_54C60;
            HitStorage* hit = (HitStorage*)((char*)obj + 0x51C);
            gfTask::Category hitCategory =
                (gfTask::Category)(unsigned char)(*(unsigned int*)((char*)obj + 0x2C) >> 7);
            int hitId = *(int*)((char*)obj + 0x28);

            {
                new (hitPartStorage) soCollisionHitPart((soCollision::Category)6, 0x3FF);
                hit->vt = lbl_51_data_1FA0;
                hit->calc = lbl_51_data_1FA0 + 0x48;
                hit->flags &= 0x01FFFFFF;
                __construct_array(hit->parts, (ArrayCallback)fn_51_583C,
                                  (ArrayCallback)__dt__18soCollisionHitPartFv, 0x68, 1);

                HitArray* array = (HitArray*)hit;
                s32 count = soArrayVectorCalculator::resize(
                    *(soArrayVectorCalcInterface*)&hit->calc, 1, array->isEmpty(),
                    array->isFull(), array->capacity(), array->getTopIndex(), array->getLastIndex());
                for (s32 i = 0; i < count; ++i)
                    ((soArray<soCollisionHitPart>*)hit)->push(*(soCollisionHitPart*)hitPartStorage);
                ((soCollisionHitPart*)hitPartStorage)->~soCollisionHitPart();
            }

            hit->groupVt = lbl_51_data_20F8;
            hit->groupCalc = lbl_51_data_20F8 + 0x48;
            hit->groupBits.top = 0;
            hit->groupBits.last = 1;
            hit->groupBits.full = 0;
            __construct_array(hit->groups, (ArrayCallback)__ct__16soCollisionGroupFv,
                              (ArrayCallback)fn_27_37D3C, 0x78, 1);
            soArrayVectorCalculator::postInitialize(
                *(soArrayVectorCalcInterface*)&hit->groupCalc, 1, 1);

            hit->hitGroupVt = lbl_51_data_1E48;
            hit->hitGroupCalc = lbl_51_data_1E48 + 0x48;
            hit->hitGroupBits.top = 0;
            hit->hitGroupBits.last = 1;
            hit->hitGroupBits.full = 0;
            __construct_array(hit->hitGroups, (ArrayCallback)__ct__19soCollisionHitGroupFv,
                              (ArrayCallback)__dt__19soCollisionHitGroupFv, 0x38, 1);
            soArrayVectorCalculator::postInitialize(
                *(soArrayVectorCalcInterface*)&hit->hitGroupCalc, 1, 1);

            new (hit->impl) soCollisionHitModuleImpl(
                (soModuleAccesser*)obj->accesser, hitId, hitCategory,
                (soArray<soCollisionHitPart>*)hit,
                (soArray<soCollisionGroup>*)&hit->groupVt,
                (soArray<soCollisionHitGroup>*)&hit->hitGroupVt,
                hitDesc, true);
        }

        OtherStorage* other = (OtherStorage*)((char*)obj + 0x6C0);
        soEventObserverRegistrationDesc* otherDesc = lbl_27_data_54C60;
        other->vt = lbl_51_data_1D08;
        other->calc = lbl_51_data_1D08 + 0x48;
        other->bits.top = 0;
        other->bits.last = 1;
        other->bits.full = 0;
        __construct_array(other->elements, (ArrayCallback)fn_51_6254,
                          (ArrayCallback)fn_51_6278, 0xA0, 1);
        soArrayVectorCalculator::postInitialize(
            *(soArrayVectorCalcInterface*)&other->calc, 1, 1);

        if (!lbl_51_bss_58) {
            GlobalObject* object = new (&lbl_51_bss_5C) GlobalObject;
            __register_global_object(*object, (void*)fn_51_4A00, lbl_51_bss_24);
            lbl_51_bss_58 = 1;
        }

        fn_27_26F06C((char*)other + 0xAC, obj->accesser, other,
                     lbl_27_bss_5FF4, &lbl_51_bss_5C, otherDesc);
        fn_27_26320C(obj);
        fn_27_2632F4(obj, context.pos, -1.0f, 0.0f);
    }

    fn_27_264D9C(self, obj);
}
