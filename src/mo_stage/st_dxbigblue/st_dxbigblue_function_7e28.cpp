#pragma force_active on
#pragma fp_contract off
#include <mt/mt_vector.h>

extern "C" const float lbl_81_rodata_100[];
extern "C" char lbl_81_data_1D40[];

struct Params { char pad[0x6c]; float speed; };
struct Flags {
    char pad[0x54];
    unsigned char a : 1;
    unsigned char b : 1;
    unsigned char unused : 1;
    unsigned char c : 1;
    unsigned char rest : 4;
};
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_81_7A38();
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
    virtual void fn_81_79E0();
    virtual void fn_81_495C();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void getModelCount();
    virtual void startup();
    virtual void fn_81_8234();
    virtual void setStageData();
    virtual Params* getStageData();
    virtual void initStageData();
    virtual void setMdlIndex();
    virtual void getMdlIndex();
    virtual void isEnableCalcCollision();
    virtual void enableCalcCollision();
    virtual void disableCalcCollision();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2(Vec3f*, unsigned long, const char*);

    char pad40[0x110];
    unsigned char state;
    char pad151[3];
    float timer;
    float position;
    char pad15c[0x14];
    Vec3f* rotation;
    unsigned char index;
    char pad175[3];
    unsigned char* selected;
    char pad17c[0x18];
    float ratio;
    char pad198[0xc];
    unsigned char flag;
    char pad1a5[3];
    Flags* first;
    Flags* second;
};

extern "C" void fn_81_7E28(Ground* self, float delta) {
    const float* c = lbl_81_rodata_100;
    Params* p = self->getStageData();
    if (p) {
        self->timer -= delta;
        if (self->timer < c[0])
            self->timer = c[0];
        switch (self->state) {
        case 2:
            if (*self->selected == self->index) {
                Vec3f pos;
                self->getNodePosition_2(&pos, 0, lbl_81_data_1D40);
                if (pos.m_x < c[0] && c[1] != self->rotation->m_z) {
                    self->rotation->m_z += c[2] * delta;
                    if (self->rotation->m_z < c[0])
                        self->rotation->m_z = c[0];
                    if (self->rotation->m_z > c[1])
                        self->rotation->m_z = c[1];
                    if (c[1] == self->rotation->m_z)
                        self->flag = 1;
                    else
                        self->flag = 0;
                }
                if (!(pos.m_x < c[0]) || c[1] == self->rotation->m_z) {
                    float old = self->position;
                    float amount = p->speed * delta;
                    self->timer = c[3];
                    self->position = old - amount;
                }
                self->ratio = self->rotation->m_z / c[4];
                if (self->ratio < c[0])
                    self->ratio = c[0];
                if (self->ratio > c[5])
                    self->ratio = c[5];
            } else {
                self->position -= p->speed * delta;
            }
            if (self->rotation->m_z < c[6]) {
                Flags* f = self->first;
                f->c = 1;
                f->b = f->c;
            } else {
                Flags* f = self->first;
                f->a = 0;
                f->c = f->a;
                f->b = f->c;
            }
            if (self->rotation->m_z > c[7]) {
                Flags* g = self->second;
                g->c = 1;
                g->b = g->c;
            } else {
                Flags* g = self->second;
                g->a = 0;
                g->c = g->a;
                g->b = g->c;
            }
            break;
        }
    }
}
