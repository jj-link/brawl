#include <types.h>
#include <gm/gm_global.h>
#include <gm/gm_global_mode_melee.h>
#include <it/it_manager.h>
#include <it/item.h>
#pragma force_active on

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_66_3AE4();
    virtual void fn_66_3C60();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_66_5490();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_66_2D00();
    virtual void startup();
    virtual void fn_66_3B58();
    virtual void fn_66_6BC();
    virtual void fn_66_2CF8();
    virtual void fn_66_2CF4();
    virtual void fn_66_2BF4();
    virtual void fn_66_2CEC();
    virtual void fn_66_2CE0();
    virtual void fn_66_2CD0();
    virtual void fn_66_BBC();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual s32 getNodePosition_2(Vec3f* out, u32 index, const char* name);
};

extern "C" {
extern const float lbl_66_rodata_D8;
extern char lbl_66_data_BD0[];
int fn_8005136C(int);
s32 fn_27_2A0DDC(void* unused, s32 idx);
f32 randf__Fv();

void fn_66_5678(Ground* self) {
    Vec3f pos;
    gmGlobalModeMelee* mode;
    BaseItem* item;
    itManager* mgr;

    mode = g_GameGlobal->m_modeMelee;
    if (mode != NULL && *(signed char*)((char*)mode + 0x16) != 0) {
        if (fn_8005136C(0x40) != 0) {
            mgr = itManager::getInstance();
            if (mgr != NULL) {
                s32 idx = fn_27_2A0DDC(mgr, 0x40);
                if (idx < 0) {
                    idx = 0;
                }
                item = mgr->createItem((itKind)0x40, (u32)(s32)((f32)idx * randf__Fv()), -1, NULL, 0, 0xffff, 0, 0xffff);
                if (item != NULL) {
                    self->getNodePosition_2(&pos, 0, lbl_66_data_BD0);
                    pos.m_y += lbl_66_rodata_D8;
                    item->warp(&pos);
                }
            }
        }
    }
}
}
