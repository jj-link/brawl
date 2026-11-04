#include <em/wnem/wnem_proc_common.h>
#include <wn/wn_em_simple.h>
#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern const char lbl_41_data_E64C[];
extern const float lbl_41_rodata_FA0;

extern "C" Vec3f* fn_41_5AC4(Vec3f*, float, float, float);
extern "C" void fn_41_534C(Vec3f*, const Vec3f*);

extern "C" void fn_41_44C40(wnemSimple* wn, soModuleAccesser* acc) {
    float* data = 0;
    if (wn->unk2234) {
        data = reinterpret_cast<float*>(wn->unk2234);
    }
    bool entering = wn->unk2214;
    wn->unk2214 = false;
    if (entering) {
        wnemCommonProc::Report(lbl_41_data_E64C);
        wn->unk2200 = lbl_41_rodata_FA0;
        wn->unk2204 = data[1];
        wn->unk21FC = lbl_41_rodata_FA0;
        wn->unk21F8 = lbl_41_rodata_FA0;
        wn->unk21B7[0] = 0;
        acc->getCollisionHitModule().setXluGlobal(0);
        acc->getCollisionAttackModule().clearAll();
        wn->setProcFnc_TouchGround(6);
    }
    Vec3f rot;
    fn_41_5AC4(&rot, lbl_41_rodata_FA0, lbl_41_rodata_FA0, lbl_41_rodata_FA0);
    Vec3f current = acc->getPostureModule().getRot(0);
    fn_41_534C(&rot, &current);
    rot.m_x += data[0];
    acc->getPostureModule().setRot(&rot, 0);
}
