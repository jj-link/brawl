#pragma force_active on
struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
union U { unsigned long long r; Vec2 v; };
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3 slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);
};
struct Mods { char pad[0xc]; Object_vptr_0* pos; char pad2[0x54]; Object_vptr_0* work; };
struct Acc { char pad[0xd8]; Mods* mods; };
extern "C" {
extern const float lbl_113_rodata_D8;
Vec2* fn_113_C30C(Vec2*, float, float);
unsigned long long fn_113_BFB0(const Vec2*, const Vec2*);
}
extern "C" int fn_113_236C0(void*, void*, void*, Acc* acc) {
    Vec2 pos;
    U diff;
    U result;
    Vec2 target;
    Object_vptr_0* posture = acc->mods->pos;
    fn_113_C30C(&pos, posture->slot4().x, posture->slot4().y);
    Object_vptr_0* work = acc->mods->work;
    float ty = work->slot12(0x11000005);
    result.r = fn_113_BFB0(fn_113_C30C(&target, work->slot12(0x11000004), ty), &pos);
    diff = result;
    return diff.v.x * acc->mods->pos->slot9() < lbl_113_rodata_D8;
}