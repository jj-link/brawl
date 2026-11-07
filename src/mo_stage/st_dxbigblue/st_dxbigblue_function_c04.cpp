#include <st/stage.h>
#include <gr/ground.h>
#pragma force_active on
#define D(n) virtual void v##n();
class BigBlueGround : public Ground {
public:
    virtual void setStageData(void*);
    virtual void initStageData();
    D(78) D(79) D(80) D(81) D(82) D(83) D(84) D(85) D(86) D(87)
    D(88) D(89) D(90) D(91) D(92) D(93) D(94) D(95) D(96) D(97)
    D(98) D(99) D(100) D(101) D(102) D(103) D(104) D(105) D(106) D(107)
    D(108) D(109) D(110) D(111) D(112) D(113) D(extra0) D(extra1)
    virtual void v114(void*);
    virtual void v115(void*);
    D(116)
    virtual void v117(void*);
};
#undef D
extern "C" {
extern char lbl_81_data_C8[];
extern char lbl_81_data_DC[];
BigBlueGround* fn_81_578C(int, const char*, const char*);
int fn_27_2249E0(Stage*);
void fn_81_C04(Stage* self, int kind) {
    BigBlueGround* ground;
    switch (kind) {
    case 0x11:
        ground = fn_81_578C(0xe, lbl_81_data_C8, lbl_81_data_DC);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        self->addGround(ground);
        ground->startup(*(gfArchive**)((char*)self + 0x1a0), 0, (gfSceneRoot::LayerType)0);
        ground->setStageData(self->m_stageData);
        ground->v117(*(void**)((char*)self + 0xbc));
        ground->v114((char*)self + 0x1e0);
        ground->v115((char*)self + 0xb9c);
        ground->setVisibility(fn_27_2249E0(self));
    }
}
}