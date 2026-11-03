#include <wn/wn_em_simple.h>
#include <so/so_module_accesser.h>
#include <so/so_array.h>
#pragma force_active on

class Team {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int getTeam();
};
class TeamModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Team* getTeam();
};
struct Params {
    char pad[0x5c];
    float value;
};
extern float lbl_41_rodata_1080;
extern float lbl_41_rodata_1084;
extern "C" void fn_41_4C934(wnemSimple* wn, soModuleAccesser* accesser) {
    Vec3f rot = accesser->getPostureModule().getRot(1);
    bool entering = wn->unk2214;
    wn->unk2214 = false;
    if (entering) {
        wn->setProcFnc_LifeZero(50);
        rot.m_z -= lbl_41_rodata_1084;
    }
    int node = ((soArrayFixed<int>*)&wn->unk2238[0])->at(0);
    rot.m_y += ((soArrayFixed<float>*)&wn->unk2238[0x14])->at(1);
    accesser->getPostureModule().setRot(&rot, 1);
    accesser->getModelModule().setNodeRotate(node, &rot);
    if (static_cast<TeamModule*>(accesser->m_enumerationStart->m_teamModule)->getTeam()->getTeam() != 10000) {
        Params* params = (Params*)wn->unk2184[0];
        if (params) {
            wn->unk2200 = lbl_41_rodata_1080;
            wn->unk2204 = params->value;
        }
    }
}
