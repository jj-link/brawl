#include <gf/gf_model.h>
#include <gr/gr_gimmick.h>
#pragma force_active on

struct grYakumono_base { char pad[0x3c]; };
class grYakumono : public grYakumono_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void setNodeVisibilityAll();
    virtual void isNodeVisible();
    virtual void setNodeCollision();
    virtual void setNodeCollision_2();
    virtual void getNodeScale();
    virtual void getNodeScale_2();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void setGimmickData();
    virtual void getGimmickData();
    virtual void changeNodeAnim(const unsigned short*, unsigned long);
    char pad40[4];
    nw4r::g3d::ScnMdl** models;
    gfModelAnimation** animations;
    char pad4c[0x124];
    int state;
    char pad174[8];
    float timer;
    const unsigned short* anim;
    int index;
    unsigned char busy;
};

extern "C" {
extern const unsigned short* lbl_40_data_9550;
extern const unsigned short* lbl_40_data_9554;
extern const float lbl_40_rodata_468[];
void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void fn_27_273B60(grYakumono*);
void fn_27_273BC8(grYakumono*);

void fn_40_2C1F8(grYakumono* self) {
    self->busy = 0;
    self->anim = lbl_40_data_9550 + self->index;
    (*self->animations)->unbindNodeAnim(*self->models);
    self->anim = lbl_40_data_9554 + self->index;
    self->changeNodeAnim(self->anim, 0);
    ((grGimmick*)self)->changeTexSrtAnim(0, 0);
    setFrame__16gfModelAnimationFd(*self->animations, lbl_40_rodata_468[0]);
    fn_27_273B60(self);
    fn_27_273BC8(self);
    self->state = 0;
    self->timer = lbl_40_rodata_468[0];
}
}