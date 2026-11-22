#include <types.h>
#include <ft/ft_common_data_accesser.h>
#include <ft/fighter.h>
#include <so/so_module_accesser.h>
#include <cm/cm_camera_controller.h>
#include <math.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int arg);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(int arg);
    virtual void slot13(float value, int arg);
};

class VtblAt3c {
    char pad[0x3c];

public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
    virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44();
    virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49();
    virtual void s50(); virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54();
    virtual void s55(); virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59();
    virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64();
    virtual void s65(); virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69();
    virtual void s70(); virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74();
    virtual void s75(); virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79();
    virtual void s80(); virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84();
    virtual void s85(); virtual void s86(); virtual void s87(); virtual void s88(); virtual void s89();
    virtual void s90(); virtual void s91(); virtual void s92(); virtual void s93(); virtual void s94();
    virtual void s95(); virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99();
    virtual void s100(); virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104();
    virtual void s105(); virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109();
    virtual void s110(); virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114();
    virtual void s115(); virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119();
    virtual void s120(); virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124();
    virtual void s125(); virtual void s126(); virtual void s127(); virtual void s128(); virtual void s129();
    virtual void s130(); virtual void s131(); virtual void s132(); virtual void s133(); virtual void s134();
    virtual void s135(); virtual void s136(); virtual void s137(); virtual void s138();
    virtual void s139(void*);
    virtual void s140(); virtual void s141(); virtual void s142(); virtual void s143(); virtual void s144();
    virtual void s145(); virtual void s146(); virtual void s147(); virtual void s148(); virtual void s149();
    virtual void s150(); virtual void s151(); virtual void s152(); virtual void s153(); virtual void s154();
    virtual void s155(); virtual void s156(); virtual void s157(); virtual void s158(); virtual void s159();
    virtual void s160(); virtual void s161(); virtual void s162(); virtual void s163(); virtual void s164();
    virtual void s165(); virtual void s166(); virtual void s167(); virtual void s168(); virtual void s169();
    virtual void s170(); virtual void s171(); virtual void s172(); virtual void s173(); virtual void s174();
    virtual void s175(); virtual void s176(); virtual void s177(); virtual void s178(); virtual void s179();
    virtual void s180(); virtual void s181(); virtual void s182(); virtual void s183(); virtual void s184();
    virtual int s185();
};

template <class T>
T at(const void* p, unsigned int off) {
    return *reinterpret_cast<const T*>(reinterpret_cast<const unsigned char*>(p) + off);
}

extern "C" {
extern const unsigned char lbl_114_data_3400[], lbl_114_data_3C7C[];
extern const float lbl_114_rodata_0[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(int);
float fn_114_B6DC(float, float);
float fn_114_C4CC(float);
int fn_114_C4D4(void*, const void*, float);
void fn_114_1E25C(void*, unsigned int, int, int, float);
CameraController* getInstance__16CameraControllerFv();
int randi__Fl(long);
float randf__Fv();
}

static inline float calcAngleInner(Vec2f v) {
    return fn_114_B6DC(-v.m_x, v.m_y);
}

static inline float calcAngle(Vec2f v, Vec2f& copy) {
    __memcpy(&copy, &v, sizeof(Vec2f));
    return fn_114_B6DC(-copy.m_x, copy.m_y);
}

extern "C" int fn_114_C158(void* arg0, soModuleAccesser* arg1) {
    const float* k;
    Object_vptr_0* obj;
    VtblAt3c* fighter;
    const void* par;

    k = lbl_114_rodata_0;
    obj = *reinterpret_cast<Object_vptr_0* const*>(
        reinterpret_cast<const char*>(arg1->m_enumerationStart) + 0x64);
    fighter = reinterpret_cast<VtblAt3c*>(
        __dynamic_cast(arg1->m_stageObject, 0x3c, lbl_114_data_3400,
                       lbl_114_data_3C7C, static_cast<short>(1)));
    par = *reinterpret_cast<const void* const*>(
        reinterpret_cast<const char*>(
            g_ftCommonDataAccesser.getData(static_cast<ftKind>(0x1a))) + 0x90);

    if (obj->slot4(0x10000040) == 0) {
        if (randi__Fl(2) == 0) {
            obj->slot13(k[1], 0x11000017);
        } else {
            obj->slot13(k[6], 0x11000017);
        }
    }

    CameraController* r29 = getInstance__16CameraControllerFv();
    float f31;
    float f30;
    float f29;

    if (randi__Fl(at<int>(par, 0x18)) == 0) {
        CameraController* r30 = getInstance__16CameraControllerFv();
        float value = obj->slot12(0x11000018);
        f31 = k[1];
        if (f31 == value) {
            f31 = k[6];
        }
        obj->slot13(f31, 0x11000018);

        if (k[1] == f31) {
            f29 = k[9] * fn_114_C4CC(
                *reinterpret_cast<const float*>(reinterpret_cast<const char*>(r29) + 0x14c) -
                *reinterpret_cast<const float*>(reinterpret_cast<const char*>(r30) + 0x15c));
            f30 = *reinterpret_cast<const float*>(
                reinterpret_cast<const char*>(r29) + 0x14c) + f29;
            f29 = k[1];
        } else {
            f29 = k[9] * fn_114_C4CC(
                *reinterpret_cast<const float*>(reinterpret_cast<const char*>(r29) + 0x148) -
                *reinterpret_cast<const float*>(reinterpret_cast<const char*>(r30) + 0x158));
            f30 = at<float>(r29, 0x148) - f29;
            f29 = k[6];
        }
    } else {
        f31 = obj->slot12(0x11000017);
        float t = k[9] * fn_114_C4CC(
            *reinterpret_cast<const float*>(reinterpret_cast<const char*>(r29) + 0x14c) -
            *reinterpret_cast<const float*>(reinterpret_cast<const char*>(r29) + 0x148));
        f30 = t + at<float>(r29, 0x148);
        f29 = f31 * (t * randf__Fv());
        float f1 = k[1];
        if (f1 == f31) {
            f1 = k[6];
        }
        obj->slot13(f1, 0x11000017);
    }

    float px = f30 +
        *reinterpret_cast<const float*>(reinterpret_cast<const char*>(par) + 0x4) * f29;
    float py = f30 +
        *reinterpret_cast<const float*>(reinterpret_cast<const char*>(par) + 0x8) * f29;
    Vec2f a(px, at<float>(r29, 0x150));
    Vec2f b(py, at<float>(r29, 0x154));
    Vec2f copy;
    float f29b = calcAngle(a - b, copy);

    int info[3];
    float out[3];
    unsigned int taskId = at<unsigned int>(fighter, 0x28);
    fn_114_1E25C(arg0, taskId, fn_27_111364(fighter->s185()),
                 fn_114_C4D4(out, &a, k[2]), f29b);

    info[0] = obj->slot4(0x10000041);
    info[1] = 0x3d;
    info[2] = 0;
    reinterpret_cast<VtblAt3c*>(arg0)->s139(info);
    return 0;
}
