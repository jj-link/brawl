#include <types.h>
#pragma force_active on

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
    Vec3() {}
};

class ObjC {
public:
    virtual void slot0();
    virtual void slot1();
    virtual s32 slot2();
};

class ObjB {
public:
    virtual void slot0();
    virtual void slot1();
    virtual ObjC* slot2();
};

class ObjA {
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
    virtual f32 slot9();
};

struct FtSub2 { char pad[0x34]; f32 fx; f32 fy; };
struct FtSub { char pad[0x84]; FtSub2* sub2; };
struct FtCast { char pad[0x1FF74]; FtSub* sub; };
struct Obj8 { char pad[0x28]; u32 taskId; };
struct D8 { char pad0[0xc]; ObjA* a; char pad1[8]; ObjB* b; };
struct Self { char pad0[8]; Obj8* obj8; char pad1[0xcc]; D8* d8; };

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_104_21A98(void*, u32, s32, Vec3*, f32);
extern const char lbl_104_data_76A0[];
extern const char lbl_104_data_2EDC[];
}

extern "C" int fn_104_1B508(void* arg0, Self* self) {
    FtCast* cast = static_cast<FtCast*>(__dynamic_cast(self->obj8, 0x3c, lbl_104_data_76A0, lbl_104_data_2EDC, short(1)));
    Vec3 v = self->d8->a->slot4();
    v.x += cast->sub->sub2->fx;
    v.y += cast->sub->sub2->fy;
    ObjB* b = self->d8->b;
    u32 taskId = self->obj8->taskId;
    f32 value = self->d8->a->slot9();
    s32 ownerId = b->slot2()->slot2();
    fn_104_21A98(arg0, taskId, ownerId, &v, value);
    return 0;
}
