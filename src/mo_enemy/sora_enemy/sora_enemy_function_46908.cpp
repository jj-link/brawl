#include <wn/wn_em_simple.h>
#include <em/wnem/wnem_proc_common.h>
#include <mt/mt_vector.h>
#pragma force_active on
#define V10(n) \
    virtual void m##n##a(); \
    virtual void m##n##b(); \
    virtual void m##n##c(); \
    virtual void m##n##d(); \
    virtual void m##n##e(); \
    virtual void m##n##f(); \
    virtual void m##n##g(); \
    virtual void m##n##h(); \
    virtual void m##n##i(); \
    virtual void m##n##j();
class WnemPorky {
    char pad[0x3C];
public:
    V10(0) V10(1) V10(2) V10(3) V10(4)
    V10(5) V10(6) V10(7) V10(8) V10(9)
    virtual void m10a();
    virtual void m10b();
    virtual void m10c();
    virtual void m10d();
    virtual void m10e();
    virtual void m10f();
    virtual void call1b0(s32 p1, bool p2);
};
#undef V10
struct SimpleData {
    float f0;
    float f4;
    char pad8[0x10];
    s32 i18;
    s32 i1c;
};
class PostureLike {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3f slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10(float p);
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
};
struct Modules { char pad[0xc]; PostureLike* posture; };
struct Accesser { char pad[0xd8]; Modules* modules; };
extern "C" {
extern char lbl_41_data_EAB0[];
extern char lbl_41_data_EACF[];
extern const float lbl_41_rodata_FE0[];
void* fn_41_2C7C4(Vec3f*, float);
void getHipPos__23ftExternalValueAccesserFP7Fighter(Vec3f*, void*);
void fn_41_534C(Vec3f*, const Vec3f*);
void fn_41_46908(wnemSimple* wn, Accesser* acc) {
    const float* c = lbl_41_rodata_FE0;
    SimpleData* data = 0;
    if (wn->unk2234) {
        data = reinterpret_cast<SimpleData*>(wn->unk2234);
    }
    float f31 = data->f0;
    float f30 = data->f4;
    bool entering = wn->unk2214;
    wn->unk2214 = false;
    if (entering) {
        wnemCommonProc::Report(lbl_41_data_EAB0);
        wn->setProcFnc_LifeZero(0x2B);
        WnemPorky* proc = reinterpret_cast<WnemPorky*>((char*)wn + 0xc);
        proc->call1b0(0, 0);
        if (data->i18) {
            wn->executeAnimCmd(data->i18, 4, 1);
        }
        Vec3f pos = acc->modules->posture->slot4();
        void* fighter = fn_41_2C7C4(&pos, c[0]);
        if (fighter) {
            Vec3f target;
            Vec3f hip;
            getHipPos__23ftExternalValueAccesserFP7Fighter(&hip, fighter);
            fn_41_534C(&target, &hip);
            wn->unk21FC = c[1];
            wn->unk21F8 = c[1];
            wn->unk2204 = c[1];
            wn->unk2200 = c[1];
            if (pos.m_x <= target.m_x) {
                wn->unk2200 = f31;
                acc->modules->posture->slot10(c[2]);
            } else {
                wn->unk2200 = -f31;
                acc->modules->posture->slot10(c[3]);
            }
            acc->modules->posture->slot19();
        } else {
            wn->unk21FC = c[1];
            wn->unk21F8 = c[1];
            wn->unk2204 = c[1];
            wn->unk2200 = c[1];
            if (acc->modules->posture->slot9() == c[2]) {
                wn->unk2200 = f31;
            } else {
                wn->unk2200 = -f31;
            }
        }
        if (data->i1c) {
            wn->executeAnimCmd(data->i1c, 4, 1);
        }
    }
    if (wn->unk2218) {
        wnemCommonProc::Report(lbl_41_data_EACF);
        wn->changeProcFnc(0x2A, 1);
        return;
    }
    float f1 = wn->unk21F8;
    if (f1 >= f30) {
        wn->unk21F8 = f30;
        wn->unk2200 = c[1];
    } else if (f1 <= -f30) {
        wn->unk21F8 = -f30;
        wn->unk2200 = c[1];
    }
}
}