#include <ec/ec_mgr.h>

#pragma force_active on

struct IVec3 {
    int x, y, z;
};

struct Obj {
    char pad0[0x10];
    IVec3 pos;
    char pad1[0xc];
    u8 flag;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Obj* slot1(int);
    virtual void slot2();
    virtual int slot3();
};

struct Class_90D8_base {
    char pad[8];
};

class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
    virtual void fn_27_7B0B0();
    virtual int fn_27_7ABD8();
};

struct Inner {
    char pad[4];
    Class_90D8* mid;
};

struct Modules {
    char pad[0xd8];
    Inner* inner;
};

struct Self {
    char pad0[0x44];
    Modules* modules;
    char pad1[4];
    Object_vptr_0* list;
    char pad2[0xe4];
    u8 slow;
    u8 flags;

    void apply(int index, int a, int b, float f, u8& flag);
};

extern "C" int fn_27_97D84(Self*, int, Vec3f*);
extern "C" void fn_27_9FA90(Obj*, int, int, float, int);
extern "C" void fn_27_9FABC(Obj*, Modules*);
extern "C" const float lbl_27_rodata_C58;

inline void Self::apply(int index, int a, int b, float f, u8& flag) {
    flag = (bool)(flag & 1);
    fn_27_9FA90(list->slot1(index), a, b, f, flag);
}

extern "C" int fn_27_997C4(
    Self* self, int arg1, int arg2, u8 arg3, int arg4, float farg0
) {
    Vec3f sp20;

    if (self->modules->inner->mid->fn_27_7ABD8() != 0 && arg1 != 0) {
        if (arg4 == -1) {
            arg4 = 0;
            while (arg4 < self->list->slot3()) {
                if (self->list->slot1(arg4)->flag == 0) {
                    break;
                }
                arg4++;
            }
        }

        if (arg4 < 0 || !(arg4 < self->list->slot3())) {
            return -1;
        }

        arg2 = fn_27_97D84(self, arg2, &sp20);
        self->apply(arg4, arg1, arg2, farg0, arg3);

        if ((u32)((self->flags >> 6) & 1) == 1) {
            fn_27_9FABC(self->list->slot1(arg4), self->modules);
            Obj* o = self->list->slot1(arg4);
            IVec3 sp14 = o->pos;
            Vec3f sp8;
            sp8.m_x = lbl_27_rodata_C58;
            sp8.m_y = lbl_27_rodata_C58;
            sp8.m_z = lbl_27_rodata_C58;

            u32 res = g_ecMgr->setEffect(
                (EfID)arg1, (Vec3f*)&sp14, &sp20, &sp8
            );
            if (res != 0) {
                u8 slow = self->slow;
                if (slow != 1) {
                    g_ecMgr->setSlowRate(res, slow);
                }
            }
        }
    }

    return arg4;
}
