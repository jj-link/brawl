#include <types.h>
#include <so/so_value_accesser.h>
#pragma force_active on

struct Event {
    s32 kind;
    u8 flag;
    u8 pad5[3];
    s32 value;
    u8 b;
    s32 getValue() const { return value; }
};

class VtBig {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3(int, void*);
    virtual void s4(int, int);
    virtual void s5(int, u32);
    virtual void s6();
    virtual void s7();
    virtual void s8(int);
    virtual int s9(int);
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual int s16();
    virtual int s17(u32);
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual float s22();
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
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void* s42(int);
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60(int, int);
};

class VtStop {
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
    virtual void s16(int, u8);
};

class ArgBase {
public:
    char pad0[0x28];
    void* f28;
    s32 f2c;
    char pad1[0xc];
};

class ArgObj : public ArgBase {
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
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual int s40();
};

class ModelBase {
public:
    char pad[8];
};

class ModelObj : public ModelBase {
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
    virtual int s33(u32);
};

struct ModuleEnum {
    void* resource;
    ModelObj* model;
    void* motion;
    VtBig* posture;
    char p10[0x44 - 0x10];
    VtStop* stop;
    char p48[0x54 - 0x48];
    VtBig* link;
    char p58[0x5C - 0x58];
    VtBig* controller;
    char p60[0x64 - 0x60];
    VtBig* work;
    char p68[0x70 - 0x68];
    VtBig* status;
};

struct AccesserView {
    char pad[0xd8];
    ModuleEnum* en;
};

#define ENUM_OF(a) (((AccesserView*)(a))->en)

extern "C" float fn_27_8CAD0(void*);

extern "C" int fn_27_3580FC(void* arg0, Event* event, soModuleAccesser* accesser, ArgObj* obj) {
    VtBig* work = ENUM_OF(accesser)->work;
    VtBig* status = ENUM_OF(accesser)->status;
    VtBig* link = ENUM_OF(accesser)->link;
    void* f28;

    if ((((s32)(((u32)obj->f2c << 17) & 0xFF800000)) >> 24) == 0xC && obj->s40() == 0x60 &&
        link->s9(6) != 0 && ((f28 = obj->f28), 1) && link->s42(6) == f28) {
        switch (event->kind) {
        case 0x45C:
            if (ENUM_OF(accesser)->link->s9(7) != 0) {
                ENUM_OF(accesser)->link->s8(7);
            }
            if ((u32)(event->getValue() + 0x10000) != 0xFFFF) {
                ENUM_OF(accesser)->link->s4(7, event->value);
            }
            return 1;
        case 0x838:
            status->s3(0x124, accesser);
            return 1;
        case 0x839:
            status->s3(0x125, accesser);
            return 1;
        case 0x83A:
            status->s3(0x127, accesser);
            return 1;
        case 0x83B:
            status->s3(0x128, accesser);
            return 1;
        case 0x83C:
            status->s3(0x129, accesser);
            return 1;
        case 0x83D:
            work->s5(0x1ED, 0x20000000);
            work->s5(0x1ED, 0x20000001);
            status->s3(0x12C, accesser);
            return 1;
        case 0x83E:
            if (link->s9(6) != 0) {
                status->s3(0x126, accesser);
            }
            return 1;
        case 0x83F:
            if (link->s9(6) != 0) {
                work->s5(0x1F0, 0x20000000);
                work->s5(0x1F7, 0x20000001);
                status->s3(0x12C, accesser);
            }
            return 1;
        case 0x841:
            event->value = soValueAccesser::getConstantInt(accesser, 0x5A88, 0);
            return 1;
        case 0x842: {
            VtBig* ctrl = ENUM_OF(accesser)->controller;
            ctrl->s60(soValueAccesser::getConstantInt(accesser, 0x5A02, 0), 1);
            return 1;
        }
        case 0x843:
            ENUM_OF(accesser)->stop->s16(event->value, event->b);
            return 1;
        case 0:
            if (work->s17(0x12000041) == 0) {
                work->s5(0x1F0, 0x20000000);
                work->s5(0x1F7, 0x20000001);
                status->s3(0x12C, accesser);
            }
            goto done;
        }
    } else {
        switch (event->kind) {
        case 0x45C:
            if (ENUM_OF(accesser)->link->s9(7) != 0) {
                ENUM_OF(accesser)->link->s8(7);
            }
            if ((u32)(event->getValue() + 0x10000) != 0xFFFF) {
                ENUM_OF(accesser)->link->s4(7, event->value);
            }
            return 1;
        case 0x4:
            if (ENUM_OF(accesser)->link->s9(7) != 0) {
                void* g = obj->f28;
                if (ENUM_OF(accesser)->link->s42(7) == g) {
                    ENUM_OF(accesser)->link->s8(7);
                }
            }
            goto done;
        case 0x8:
            if (status->s16() == 0x112 || status->s16() == 0x117) {
                float f = fn_27_8CAD0(obj);
                if (f <= ENUM_OF(accesser)->posture->s22()) {
                    status->s3(0x119, accesser);
                    event->value = ENUM_OF(accesser)->model->s33(0x12C);
                    event->flag = 1;
                }
                return 1;
            }
            goto done;
        case 0xF:
            status->s3(0x11B, accesser);
            return 1;
        }
    }
done:
    return 0;
}
