#include <gr/gr_yakumono.h>
#include <st/st_melee.h>
#include <sr/sr_common.h>

#pragma force_active on

class FamicomGround : public grYakumono {
public:
    virtual void setStageData(void*);
    virtual void disableCalcCollision();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119(Vec3f*);
    virtual void slot120(void*);
};

struct PowArea {
    stGimmickAreaData area;
    Vec3f pos;
    float power;
    float angle;
    char pad3c[4];
    unsigned char enabled;
    char pad41[7];
};

struct FamicomStage : public stMelee {
    char pad1d8[0x398 - 0x1d8];
    Vec3f position;
    int state;
    stTrigger* trigger;
    PowArea* pow;
};

extern "C" {
extern const float lbl_68_rodata_0[];
extern char lbl_68_data_170[];
extern char lbl_68_data_184[];

FamicomGround* fn_68_4054(int, const char*, const char*);
void fn_27_233898(stTrigger*, PowArea*);
}

extern "C" void fn_68_13FC(FamicomStage* input) {
    const float* rodata = lbl_68_rodata_0;
    FamicomGround* ground;
    stCollisionWork* work = (stCollisionWork*)((char*)input + 0x288);

    struct Context {
        FamicomStage* stage;
    };
    Context context = { input };
    FamicomStage* self = context.stage;

    ground = fn_68_4054(2, lbl_68_data_170, lbl_68_data_184);
    if (ground) {
        self->addGround(ground);
        ground->startup(self->m_fileData, 0, gfSceneRoot::Layer_Ground);
        ground->setStageData(self->m_stageData);
        ground->slot119(&self->position);
        ground->slot120(&self->state);
        self->createCollisionSelf(
            work, ground, lbl_68_data_170, lbl_68_data_170, 0x41a);
        ground->disableCalcCollision();

        void* data = self->m_stageData;
        if (data) {
            self->pow = (PowArea*)operator new(0x48, Heaps::StageInstance);
            if (self->pow) {
                memset(self->pow, 0, 0x48);

                PowArea* area = self->pow;
                area->pos.m_x = rodata[0];
                area->pos.m_y = rodata[0];
                area->pos.m_z = rodata[0];
                self->pow->power = *(float*)((char*)data + 0x10);
                self->pow->angle = rodata[1];
                self->pow->enabled = 1;

                area = self->pow;
                area->area.m_offsetPos.m_x = rodata[0];
                area->area.m_offsetPos.m_y = rodata[0];
                area->area.m_range.m_x = rodata[3];
                area->area.m_range.m_y = rodata[3];

                self->trigger =
                    g_stTriggerMng->createTrigger(Gimmick::Area_Pow, -1);
                fn_27_233898(self->trigger, self->pow);
                self->trigger->setAreaSleep(true);
            }
        }
    }
}
