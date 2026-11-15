#include <types.h>
#include <nw4r/math.h>
#pragma force_active on
#pragma fp_contract off

struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
};

struct Self {
    u32 pad0;
    s32 state;
    u8 b8;
    u8 b9;
    u8 ba;
};

class CtrlVt {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(u32);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual f32 slot12(u32);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual u32 slot17(u32);
    virtual void slot18(u32);
    virtual void slot19(u32);
};

class UnitVt {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
    virtual Vec3f slot4();
    virtual void slot5(Vec3f*);
};

struct StageBase {
    char pad[0x3c];
};

class Stage : public StageBase {
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
    virtual void slot65(f32*, f32*, u8);
};

extern "C" {
void fn_27_388068(void* a, s32 b, s32 c, void* d);
void fn_27_388298(void* a, void* b, f32 x, f32 y, f32 z);
void fn_27_388674();
void fn_27_388FA8(void* a, s32 b, void* c);
void* getInstance__16CameraControllerFv();
}

extern void* lbl_27_bss_5668;
extern f32 lbl_27_rodata_7C8C;
extern f32 lbl_27_rodata_7CE8;

#define MODP(o) (*(char**)((char*)(o) + 0xd8))
#define CTRL(o) (*(CtrlVt**)(MODP(o) + 0x64))
#define UNIT14(o) (*(UnitVt**)(MODP(o) + 0x14))
#define UNIT0C(o) (*(UnitVt**)(MODP(o) + 0xc))

extern "C" void fn_27_38988C(Self* self, s32 arg1, s32 arg2, void* obj)
{
    Vec3f v;
    Vec3f w;
    Vec3f pos1;
    Vec3f pos2;
    Vec3f y;
    Vec3f x;
    f32 yy;
    f32 xx;
    f32 sx;
    f32 sy;
    f32 sz;

    switch (self->state) {
    case 1:
        CTRL(obj)->slot18(0x12000040);
        if (CTRL(obj)->slot17(0x1200003E) == 1) {
            fn_27_388068(self, arg1, arg2, obj);
        }
        if (lbl_27_bss_5668 != 0) {
            ((Stage*)lbl_27_bss_5668)->slot65(&x.x, &y.x, self->b9);
            fn_27_388298(self, obj, x.x, y.x, lbl_27_rodata_7C8C);
        }
        if (self->ba & 8) {
            ((Stage*)lbl_27_bss_5668)->slot65(&v.x, &v.x, self->b8);
            UNIT0C(obj)->slot5(&v);
            yy = CTRL(obj)->slot12(0x11000014);
            xx = CTRL(obj)->slot12(0x11000013);
            w.x = xx;
            w.y = yy;
            w.z = lbl_27_rodata_7C8C;
            if ((f32)(double)nw4r::math::FAbs(w.z - v.z) < lbl_27_rodata_7CE8) {
                if ((f32)(double)nw4r::math::FAbs(w.y - v.y) < lbl_27_rodata_7CE8) {
                    CTRL(obj)->slot19(0x1200003F);
                    return;
                }
            }
            CTRL(obj)->slot17(0x1200003F);
            CTRL(obj)->slot18(0x1200003F);
            return;
        }
        if (UNIT14(obj)->slot3() == 5) {
            pos1.x = CTRL(obj)->slot12(0x11000013);
            pos1.y = *(f32*)((char*)getInstance__16CameraControllerFv() + 0x150);
            if (CTRL(obj)->slot17(0x1200003F) == 1) {
                pos1.z = lbl_27_rodata_7C8C;
            } else {
                pos1.z = UNIT0C(obj)->slot4().z;
            }
            UNIT0C(obj)->slot5(&pos1);
            CTRL(obj)->slot18(0x1200003F);
            return;
        }
        CTRL(obj)->slot19(0x1200003F);
        return;
    case 2:
        fn_27_388674();
        if (UNIT14(obj)->slot3() == 5) {
            pos2.x = CTRL(obj)->slot12(0x11000013);
            pos2.y = *(f32*)((char*)getInstance__16CameraControllerFv() + 0x150);
            if (CTRL(obj)->slot17(0x1200003F) == 1) {
                pos2.z = lbl_27_rodata_7C8C;
            } else {
                pos2.z = UNIT0C(obj)->slot4().z;
            }
            UNIT0C(obj)->slot5(&pos2);
            CTRL(obj)->slot18(0x1200003F);
            return;
        }
        if (CTRL(obj)->slot4(0x10000044) > 0x78) {
            if (CTRL(obj)->slot17(0x12000040) == 0) {
                fn_27_388FA8(self, arg1, obj);
            }
        }
        CTRL(obj)->slot19(0x1200003F);
        return;
    }
}

