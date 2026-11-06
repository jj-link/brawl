#include <st/stage.h>
#include <gr/ground.h>
#pragma force_active on
#define D(n) virtual void v##n();
class PalutenaGround : public Ground {
public:
    virtual void setStageData(void*);
    virtual void initStageData();
    D(78) D(79) D(80) D(81) D(82) D(83) D(84) D(85) D(86) D(87)
    D(88) D(89) D(90) D(91) D(92) D(93) D(94) D(95) D(96) D(97)
    D(98) D(99) D(100) D(101) D(102) D(103) D(104) D(105) D(106) D(107)
    D(108) D(109) D(110) D(111) D(112) D(113) D(114) D(116) D(117)
    virtual void v115(void*);
};
#undef D
extern "C" {
extern char lbl_67_data_5F0[];
extern char lbl_67_data_5F8[];
PalutenaGround* fn_67_B10C(int, const char*, const char*);
void fn_67_10F4(Stage* self, int kind) {
    PalutenaGround* ground;
    switch (kind) {
    case 0x22:
        ground = fn_67_B10C(0x10, lbl_67_data_5F0, lbl_67_data_5F8);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        self->addGround(ground);
        ground->startup(*(gfArchive**)((char*)self + 0x1a0), 0, (gfSceneRoot::LayerType)0);
        ground->setStageData(self->m_stageData);
        ground->initStageData();
        ground->v115((char*)self + 0x1d8);
    }
}
}