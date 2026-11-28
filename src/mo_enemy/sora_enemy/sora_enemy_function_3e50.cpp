#include <types.h>
#include <em/em_info.h>
#include <so/so_value_accesser.h>
#include <so/stageobject.h>
#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>

#pragma force_active on

// The checked candidate has two differing assembly lines.

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void activate__11StageObjectFffP5Vec3fb(
    StageObject*, Vec3f*, float, float, bool);
s32 getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
f32 getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
s32 getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, u32, u32);
u32 getNodeNum__6emInfoF6emKind(void*, int);

void fn_41_A3C4(void*, int);
void fn_41_3ACC(void*);
void fn_41_3C04(void*);
void fn_41_3D00(void*);
f32 fn_41_3678(void*);
void fn_41_5558(void*);
void fn_41_51C4(void*, int);
void fn_41_28E64(void*);
void fn_41_2B630(void*, int);
u32 fn_41_B3DC(void*);

extern const u8 lbl_41_data_0;
extern const char lbl_41_data_F54[];
extern const char lbl_41_data_12A4[];
extern const f32 lbl_41_rodata_0[];
}

struct OneCall {
    virtual s32 call();
};

struct Prefix8 {
    char pad[8];
};

struct Factory : Prefix8 {
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void create(
        s32, u32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
};

struct Model {
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void setPair(float, float);
    virtual void unused10();
};

struct Callback {
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void setValue(s32, soValueAccesser*, float);
    virtual void c6();
    virtual void c7();
    virtual void setAccess(s32, s32, soValueAccesser*);
};

struct Work {
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void setInt(s32, u32);
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void setFloat(float, u32);
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void setFlag(u32);
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void w30();
    virtual void w31();
    virtual u32 status(u32);
    virtual void w33();
    virtual void w34();
    virtual void update(u32, soValueAccesser*);
};

struct Category {
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void setNode(u32, u32);
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void set(u32);
    virtual u32 get(u32);
};

struct VtableAt8 : Prefix8 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void run(void*, s32, s32, s32, s32, s32);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual s32 find(void*, s32, s32);
};

#define DECLARE_ENERGY_METHOD(n) virtual void e##n();

struct EnergyAt8 : Prefix8 {
    DECLARE_ENERGY_METHOD(1)
    DECLARE_ENERGY_METHOD(2)
    DECLARE_ENERGY_METHOD(3)
    DECLARE_ENERGY_METHOD(4)
    DECLARE_ENERGY_METHOD(5)
    DECLARE_ENERGY_METHOD(6)
    virtual void play(void*, bool, s32, bool, bool, bool);
    DECLARE_ENERGY_METHOD(8)
    DECLARE_ENERGY_METHOD(9)
    DECLARE_ENERGY_METHOD(10)
    DECLARE_ENERGY_METHOD(11)
    DECLARE_ENERGY_METHOD(12)
    DECLARE_ENERGY_METHOD(13)
    DECLARE_ENERGY_METHOD(14)
    DECLARE_ENERGY_METHOD(15)
    DECLARE_ENERGY_METHOD(16)
    DECLARE_ENERGY_METHOD(17)
    DECLARE_ENERGY_METHOD(18)
    DECLARE_ENERGY_METHOD(19)
    DECLARE_ENERGY_METHOD(20)
    DECLARE_ENERGY_METHOD(21)
    DECLARE_ENERGY_METHOD(22)
    DECLARE_ENERGY_METHOD(23)
    DECLARE_ENERGY_METHOD(24)
    DECLARE_ENERGY_METHOD(25)
    DECLARE_ENERGY_METHOD(26)
    DECLARE_ENERGY_METHOD(27)
    DECLARE_ENERGY_METHOD(28)
    DECLARE_ENERGY_METHOD(29)
    DECLARE_ENERGY_METHOD(30)
    DECLARE_ENERGY_METHOD(31)
    DECLARE_ENERGY_METHOD(32)
    DECLARE_ENERGY_METHOD(33)
    DECLARE_ENERGY_METHOD(34)
    DECLARE_ENERGY_METHOD(35)
    DECLARE_ENERGY_METHOD(36)
    DECLARE_ENERGY_METHOD(37)
    DECLARE_ENERGY_METHOD(38)
    DECLARE_ENERGY_METHOD(39)
    DECLARE_ENERGY_METHOD(40)
    DECLARE_ENERGY_METHOD(41)
    DECLARE_ENERGY_METHOD(42)
    DECLARE_ENERGY_METHOD(43)
    DECLARE_ENERGY_METHOD(44)
    DECLARE_ENERGY_METHOD(45)
    DECLARE_ENERGY_METHOD(46)
    DECLARE_ENERGY_METHOD(47)
    DECLARE_ENERGY_METHOD(48)
    DECLARE_ENERGY_METHOD(49)
    DECLARE_ENERGY_METHOD(50)
    DECLARE_ENERGY_METHOD(51)
    DECLARE_ENERGY_METHOD(52)
    DECLARE_ENERGY_METHOD(53)
    DECLARE_ENERGY_METHOD(54)
    DECLARE_ENERGY_METHOD(55)
    DECLARE_ENERGY_METHOD(56)
    DECLARE_ENERGY_METHOD(57)
    DECLARE_ENERGY_METHOD(58)
    DECLARE_ENERGY_METHOD(59)
    DECLARE_ENERGY_METHOD(60)
    DECLARE_ENERGY_METHOD(61)
    DECLARE_ENERGY_METHOD(62)
    DECLARE_ENERGY_METHOD(63)
    DECLARE_ENERGY_METHOD(64)
    DECLARE_ENERGY_METHOD(65)
    DECLARE_ENERGY_METHOD(66)
    DECLARE_ENERGY_METHOD(67)
    DECLARE_ENERGY_METHOD(68)
    DECLARE_ENERGY_METHOD(69)
    DECLARE_ENERGY_METHOD(70)
    DECLARE_ENERGY_METHOD(71)
    DECLARE_ENERGY_METHOD(72)
    DECLARE_ENERGY_METHOD(73)
    DECLARE_ENERGY_METHOD(74)
    DECLARE_ENERGY_METHOD(75)
    DECLARE_ENERGY_METHOD(76)
    DECLARE_ENERGY_METHOD(77)
    DECLARE_ENERGY_METHOD(78)
    DECLARE_ENERGY_METHOD(79)
    DECLARE_ENERGY_METHOD(80)
    DECLARE_ENERGY_METHOD(81)
    DECLARE_ENERGY_METHOD(82)
    DECLARE_ENERGY_METHOD(83)
    DECLARE_ENERGY_METHOD(84)
    DECLARE_ENERGY_METHOD(85)
    DECLARE_ENERGY_METHOD(86)
    DECLARE_ENERGY_METHOD(87)
    DECLARE_ENERGY_METHOD(88)
    DECLARE_ENERGY_METHOD(89)
    DECLARE_ENERGY_METHOD(90)
    DECLARE_ENERGY_METHOD(91)
    DECLARE_ENERGY_METHOD(92)
    DECLARE_ENERGY_METHOD(93)
    DECLARE_ENERGY_METHOD(94)
    DECLARE_ENERGY_METHOD(95)
    DECLARE_ENERGY_METHOD(96)
    DECLARE_ENERGY_METHOD(97)
    DECLARE_ENERGY_METHOD(98)
    DECLARE_ENERGY_METHOD(99)
    DECLARE_ENERGY_METHOD(100)
    DECLARE_ENERGY_METHOD(101)
    DECLARE_ENERGY_METHOD(102)
    DECLARE_ENERGY_METHOD(103)
    DECLARE_ENERGY_METHOD(104)
    DECLARE_ENERGY_METHOD(105)
    DECLARE_ENERGY_METHOD(106)
    DECLARE_ENERGY_METHOD(107)
    DECLARE_ENERGY_METHOD(108)
    DECLARE_ENERGY_METHOD(109)
    DECLARE_ENERGY_METHOD(110)
    DECLARE_ENERGY_METHOD(111)
    DECLARE_ENERGY_METHOD(112)
    virtual void disable(s32);
    DECLARE_ENERGY_METHOD(114)
    DECLARE_ENERGY_METHOD(115)
    DECLARE_ENERGY_METHOD(116)
    DECLARE_ENERGY_METHOD(117)
    DECLARE_ENERGY_METHOD(118)
    DECLARE_ENERGY_METHOD(119)
    DECLARE_ENERGY_METHOD(120)
    DECLARE_ENERGY_METHOD(121)
    DECLARE_ENERGY_METHOD(122)
    DECLARE_ENERGY_METHOD(123)
    DECLARE_ENERGY_METHOD(124)
    DECLARE_ENERGY_METHOD(125)
    DECLARE_ENERGY_METHOD(126)
    DECLARE_ENERGY_METHOD(127)
    virtual void enable(s32);
};

#undef DECLARE_ENERGY_METHOD

struct EnemyObject : StageObject {
    char padding[0x78];
    soModuleAccesser access;
};

inline void activateStage(
    EnemyObject* self, Vec3f* pos, float arg1, float arg2) {
    activate__11StageObjectFffP5Vec3fb(self, pos, arg1, arg2, false);
}

inline void* enemyResource(EnemyObject* self) {
    void* resource = *(void**)((char*)self + 0x91C);
    return *(void**)((char*)resource + 4);
}

inline void initializeCallback(EnemyObject* self, const f32* constants) {
    Callback* callback =
        (Callback*)*(void**)((char*)*(void**)((char*)self + 0x1B4) + 0x6C);
    s32 constant =
        getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(
            &self->access, 0xA810, 0);
    if (constant != 0) {
        callback->setAccess(0, constant, (soValueAccesser*)&self->access);
        callback->setValue(0, (soValueAccesser*)&self->access, constants[5]);
        callback->setAccess(0, 0, (soValueAccesser*)&self->access);
    }
}

extern "C" void fn_41_3E50(
    EnemyObject* self, Vec3f* pos, float arg1, float arg2, u32 index) {
    f32 saved1 = arg1;
    f32 saved2 = arg2;
    const f32* constants = lbl_41_rodata_0;
    emInfo* info = emInfo::getInstance();

    if (index >= info->getStatusNum(*(s32*)((char*)self + 0xAC))) {
        return;
    }
    {
        activateStage(self, pos, arg1, arg2);

        void* factoryObj;
        s32 flags = getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
            &self->access, 0x59F9, 0) | 0x10;

        void* object = *(void**)((char*)self + 0x60);
        object = *(void**)((char*)object + 0xD8);
        OneCall* call = (OneCall*)*(void**)((char*)object + 0xAC);
        if (call->call() == 0) {
            flags |= 0x108;
        }

        factoryObj =
            *(void**)((char*)*(void**)((char*)self + 0x1B4) + 4);
        s32 kind = getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
            &self->access, 0x59E5, 0);
        s32 zero = 0;
        ((Factory*)factoryObj)->create(
            kind, flags, 1, 1, zero, zero, zero,
            0xFFFF, zero, (s32)lbl_41_data_0, zero);

        getNodeNum__6emInfoF6emKind(
            emInfo::getInstance(), *(s32*)((char*)self + 0xAC));
        getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            &self->access, 0xBFE, 0);

        ((Model*)*(void**)((char*)*(void**)((char*)self + 0x1B4) + 0xA4))
            ->unused10();
        ((Model*)*(void**)((char*)*(void**)((char*)self + 0x1B4) + 0xA4))
            ->setPair(constants[6], constants[8]);

        *(u8*)((char*)self + 0x113C) = 0;
        for (s32 i = 0; i < 4; ++i) {
            fn_41_A3C4(self, i);
        }

        *(f32*)((char*)self + 0xC0) = constants[6];
        *(s32*)((char*)self + 0xC4) = 0;
        fn_41_5558(self);

        Work* work =
            (Work*)*(void**)((char*)*(void**)((char*)self + 0x1B4) + 0x64);
        work->setFloat(constants[6], 0x11000009);
        work->setFloat(constants[4], 0x11000001);
        work->setFloat(constants[4], 0x1100000E);
        work->setFloat(constants[6], 0x11000002);
        work->setFloat(constants[6], 0x11000005);
        work->setFloat(constants[6], 0x11000007);
        work->setFloat(constants[6], 0x11000008);
        work->setFloat(constants[6], 0x11000004);
        f32 magnitude = (f32)(double)nw4r::math::FAbs(
            getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                &self->access, 0xBE9, 0));
        work->setFloat(magnitude, 0x11000006);
        work->setFloat(constants[9], 0x1100000A);
        work->setFloat(constants[9], 0x1100000B);
        work->setFloat(constants[9], 0x1100000D);
        work->setFloat(constants[6], 0x1100000F);

        work->setFlag(0x12000000);
        work->setFlag(0x1200000F);
        work->setFlag(0x12000010);
        work->setFlag(0x12000011);
        work->setFlag(0x12000001);
        work->setFlag(0x12000002);
        work->setFlag(0x12000003);
        work->setFlag(0x12000004);
        work->setFlag(0x12000005);
        work->setFlag(0x1200000E);
        work->setFlag(0x12000009);
        work->setFlag(0x1200000A);
        work->setFlag(0x12000006);
        work->setFlag(0x12000007);
        work->setFlag(0x12000008);
        work->setFlag(0x1200000B);
        work->setFlag(0x1200000C);
        work->setFlag(0x1200000D);
        work->setFlag(0x12000012);
        work->setFlag(0x12000013);

        work->setInt(-1, 0x10000000);
        work->setInt(0, 0x10000002);
        work->setInt(0, 0x1000000C);
        work->setInt(0, 0x1000000D);
        work->setInt(0, 0x1000000E);
        work->setInt(0, 0x1000000F);
        work->setInt(-1, 0x10000003);
        work->setInt(-1, 0x10000004);
        work->setInt(0, 0x10000005);
        work->setInt(-1, 0x10000006);
        work->setInt(0, 0x10000007);
        work->setInt(-1, 0x10000008);
        work->setInt(-1, 0x10000009);
        work->setInt(0, 0x1000000A);
        work->setInt(-1, 0x1000000B);
        work->setInt(-1, 0x10000001);
        work->setInt(-1, 0x10000010);
        work->setInt(-1, 0x10000011);
        work->setInt(-1, 0x10000012);
        work->setInt(-1, 0x10000013);
        work->setInt(-1, 0x10000014);
        work->setInt(-1, 0x10000015);
        work->setInt(-1, 0x10000016);
        work->setInt(-1, 0x10000017);
        work->setInt(-1, 0x10000018);
        work->setInt(-1, 0x10000019);
        work->setInt(-1, 0x1000001A);

        work->setFlag(0x22000000);
        work->setFlag(0x22000001);
        work->setFlag(0x22000002);
        work->setFlag(0x22000003);
        work->setFlag(0x22000004);
        work->setFlag(0x22000005);
        work->setFlag(0x22000006);
        work->setFlag(0x22000007);
        work->setFlag(0x22000008);

        work->setInt(-1, 0x20000000);
        work->setInt(-1, 0x20000001);
        work->setInt(-1, 0x20000002);
        work->setInt(-1, 0x20000003);
        work->setInt(-1, 0x20000004);
        work->setInt(-1, 0x20000005);
        work->setFloat(constants[6], 0x21000000);
        work->setInt(0, 0x20000006);

        fn_41_3ACC(self);
        u32 nodeCount = getNodeNum__6emInfoF6emKind(
            emInfo::getInstance(), *(s32*)((char*)self + 0xAC));
        fn_41_51C4(self, nodeCount);

        f32 factor = fn_41_3678(self);
        f32 value = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            &self->access, 0xBF4, 0);
        f32 add = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            &self->access, 0xBF5, 0);
        if (constants[4] != value && constants[6] != add) {
            value += add * factor;
        }

        work->setFloat(value, 0x11000001);
        work->setFloat(value, 0x1100000E);
        work->setFloat(value, 0x11000003);

        fn_41_3C04(self);
        fn_41_28E64((char*)self + 0x1108);

        if ((u8)((Work*)*(void**)((char*)*(void**)((char*)self + 0x1B4) + 0x70))
                    ->status(index) != 5 &&
            (u8)((Work*)*(void**)((char*)*(void**)((char*)self + 0x1B4) + 0x70))
                    ->status(index) != 6) {
            void* kinetic =
                *(void**)((char*)*(void**)((char*)self + 0x1B4) + 0x10);
            ((EnergyAt8*)kinetic)->disable(0);
        }

        void* manager = *(void**)*(void**)((char*)self + 0x1B4);
        VtableAt8* finder = (VtableAt8*)manager;
        if (finder->find(enemyResource(self), 0, -1) != 0) {
            bool one = true;
            EnergyAt8* energy = (EnergyAt8*)__dynamic_cast(
                *(void**)((char*)*(void**)((char*)self + 0x1B4) + 0x10),
                8, lbl_41_data_F54, lbl_41_data_12A4, one);
            if (getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(
                    &self->access, 0xA813, 0) == 0) {
                energy->play(
                    enemyResource(self), false, 0x25, false, one, false);
            } else {
                energy->play(
                    enemyResource(self), false, 0x25, one, one, false);
                fn_41_2B630(energy, one);
            }
            energy->enable(1);
        }

        fn_41_3D00(self);
        work->setInt(
            getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
                &self->access, 0x59EB, 0),
            0x10000016);
        work->setInt(0, 0x10000017);

        u32 node = fn_41_B3DC(self);
        if (node != 0xFFFFFFFF) {
            if (((Category*)*(void**)((char*)*(void**)((char*)*(void**)(
                    (char*)self + 0x60) + 0xD8) + 0x54))->get(3) == 1) {
                ((Category*)*(void**)((char*)*(void**)((char*)*(void**)(
                    (char*)self + 0x60) + 0xD8) + 0x54))->set(3);
            }
            ((Category*)*(void**)((char*)*(void**)((char*)*(void**)(
                (char*)self + 0x60) + 0xD8) + 0x54))->setNode(3, node);
        }

        initializeCallback(self, constants);

        ((Work*)*(void**)((char*)*(void**)((char*)self + 0x1B4) + 0x70))
            ->update(index, (soValueAccesser*)&self->access);
        *(u8*)((char*)self + 0xD8) = 1;
    }
}
