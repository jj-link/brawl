#include <types.h>
#include <so/so_value_accesser.h>
#include <nw4r/math/math_arithmetic.h>

#pragma force_active on

extern f32 lbl_27_rodata_2310;
extern f32 lbl_27_rodata_2314;

class InitialValue {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual u64 getValue(s16*);
};

struct Vec3 {
    f32 x, y, z;
};

struct FloatBase {
    u32 pad[2];
};

class FloatAccess : public FloatBase {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual Vec3 getFloat(u32, u32);
};

class Posture {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual Vec3 getPosition();
};

class ResultHandler {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void dispatch(s32, void*);
};

extern "C" void fn_27_177834(void*, u8* self, u8* config) {
    s32 result = -1;
    s16 one = 1;

    struct Pair {
        u32 x;
        u32 y;
    };

    Pair copy;
    u64 initialValue =
        (*(InitialValue**)(*(u8**)(self + 0xD8) + 0x7C))->getValue(&one);
    copy = *(Pair*)&initialValue;

    s32 constant = soValueAccesser::getConstantInt(
        (soModuleAccesser*)self, 0x59E2, 0);

    if (constant != 0) {
        FloatAccess* access =
            *(FloatAccess**)(*(u8**)(self + 0xD8) + 4);
        const Vec3& value = access->getFloat(constant, 0);

        if (value.y >= *(f32*)(config + 0xC) &&
            *(f32*)((u8*)&copy + 4) > lbl_27_rodata_2314) {
            if (config[0x20] == 0)
                result = 0x95;
        } else if (value.y <= *(f32*)(config + 0x18)) {
            result = 0xE;
        }
    }

    if (result == -1) {
        constant = soValueAccesser::getConstantInt(
            (soModuleAccesser*)self, 0x59E3, 0);

        if (constant != 0) {
            FloatAccess* access =
                *(FloatAccess**)(*(u8**)(self + 0xD8) + 4);
            const Vec3& value = access->getFloat(constant, 0);

            if (value.y >= *(f32*)(config + 0xC) &&
                *(f32*)((u8*)&copy + 4) > lbl_27_rodata_2314) {
                if (config[0x20] == 0)
                    result = 0x95;
            } else if (value.y <= *(f32*)(config + 0x18)) {
                result = 0xE;
            }
        }
    }

    if (result == -1) {
        const Vec3& position =
            (*(Posture**)(*(u8**)(self + 0xD8) + 0xC))->getPosition();
        if ((f32)(double)nw4r::math::FAbs(position.x - *(f32*)(config + 8)) >
            lbl_27_rodata_2310) {
            result = 0xE;
        }
    }

    if (result != -1) {
        (*(ResultHandler**)(*(u8**)(self + 0xD8) + 0x70))
            ->dispatch(result, self);
    }
}
