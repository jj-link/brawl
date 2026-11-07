#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#include <memory.h>
#include <math.h>
#pragma force_active on

struct TLParam {
    char pad0[4];
    int v4;
    int v8;
    float vc;
    float v10;
    float v14;
    char pad1[4];
    float v1c;
};

struct TLBase {
    unsigned char pad0[0x3c];
};

struct TLFighter : TLBase {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43();
    virtual void s44(); virtual void s45();
    unsigned char pad1[0x60 - 0x40];
    soModuleAccesser* accesser;
    unsigned char pad2[0x20e4 - 0x64];
    TLParam* param;
};

class TLCenterView {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43();
    virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47();
    virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51();
    virtual void s52();
    virtual unsigned long long getParentShapeCenterPos(unsigned int);
};

extern "C" {
extern const char lbl_121_data_8EF0[];
extern const char lbl_121_data_31F4[];
extern const float lbl_121_rodata_80;
extern const float lbl_121_rodata_88;

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1DA868(void*);
void fn_121_13E04(Vec2f*, float, float);
void fn_121_DAE8(Vec2f*, const Vec2f*);

void fn_121_13A84(void* self, float farg0, float farg1, unsigned int arg1);
}

extern "C" void fn_121_13A84(void* self, float farg0, float farg1, unsigned int arg1) {
    TLFighter* fighter = static_cast<TLFighter*>(self);
    float sn;
    float var_f30;
    float f29;

    Vec3f pos = fighter->accesser->getModelModule().getNodeGlobalPosition(3, false);
    pos.m_z = fighter->accesser->getGroundModule().getZ();
    Vec3f rot = fighter->accesser->getModelModule().getNodeGlobalRotation(3, false);
    rot.m_y = fighter->param->v14;
    fighter->accesser->getPostureModule().init(&pos, farg0);

    Vec2f shapePos;
    unsigned long long bits = reinterpret_cast<TLCenterView*>(
        fighter->accesser->m_enumerationStart->m_linkModule)->getParentShapeCenterPos(3);
    __memcpy(&shapePos, &bits, sizeof(shapePos));
    fighter->accesser->getGroundModule().setShapeSafePos(&shapePos, 0);
    fn_27_1DA868(self);

    int var_r4;
    if (arg1 == 1) {
        var_r4 = fighter->param->v8;
        var_f30 = fighter->param->v10;
    } else {
        var_r4 = fighter->param->v4;
        var_f30 = fighter->param->vc;
    }
    fighter->accesser->getWorkManageModule().setInt(var_r4, 0x10000005);
    fighter->accesser->getWorkManageModule().setFloat(farg1, 0x11000001);

    Vec3f rotA;
    rotA.m_x = lbl_121_rodata_80;
    rotA.m_y = lbl_121_rodata_80;
    rotA.m_z = lbl_121_rodata_88 * farg1;
    fighter->accesser->getPostureModule().setRot(&rotA, 0);
    fighter->accesser->getPostureModule().setRot(&rot, 1);

    fighter->s43();

    fighter->accesser->getStatusModule().changeStatusRequest(2, fighter->accesser);

    char* energy = static_cast<char*>(__dynamic_cast(
        fighter->accesser->getKineticModule().getEnergy(0), 0, lbl_121_data_8EF0, lbl_121_data_31F4, 1));
    f29 = fighter->param->v1c;

    sn = sin(farg1);
    float cs = cos(farg1);
    Vec2f v10;
    fn_121_13E04(&v10, var_f30 * cs, var_f30 * sn);
    fn_121_DAE8(reinterpret_cast<Vec2f*>(energy + 8), &v10);

    sn = sin(farg1);
    float cs2 = cos(farg1);
    Vec2f v8;
    fn_121_13E04(&v8, -f29 * cs2, -f29 * sn);
    fn_121_DAE8(reinterpret_cast<Vec2f*>(energy + 0x10), &v8);

    fighter->accesser->getWorkManageModule().onFlag(0x12000003);
    fighter->accesser->getWorkManageModule().offFlag(0x12000004);
}
