#pragma force_active on
typedef unsigned char u8;
struct Parameters { char pad[4]; float value; char pad08[0x68]; float scale0, scale1, scale2; };
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_74_3B38();
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
    virtual void fn_74_3A48();
    virtual void fn_74_3BB4();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_74_4F98();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_74_2F84();
    virtual void startup();
    virtual void fn_74_4B64();
    virtual void fn_74_EFC();
    virtual Parameters* fn_74_2F7C();
};
struct State { char pad[0x20]; u8 count; u8 state; };
struct Object : Ground {
    char pad40[0x118];
    State* state;
    char pad15c[0xc];
    float value;
    char pad16c[4];
    float value170;
    char pad174[0x24];
    u8 enabled;
};
struct GameInfo { char pad[0xe]; u8 scale : 3; u8 rest : 5; };
struct GameGlobal { char pad[8]; GameInfo* info; };
extern "C" GameGlobal* g_GameGlobal;
extern "C" float lbl_74_rodata_F4;
extern "C" void fn_74_4994(Object* self) {
    if (self->state && self->state->state == 0) {
        Parameters* p = self->fn_74_2F7C();
        if (p) {
            self->value170 = lbl_74_rodata_F4;
            self->state->count++;
            if (self->state->count >= 15)
                self->state->count = 14;
            float v = p->value;
            self->value = v;
            if (self->enabled == 1) {
                GameInfo* info = g_GameGlobal->info;
                if (!info) return;
                switch (info->scale) {
                case 0: self->value = v * p->scale0; break;
                case 1: self->value = v * p->scale1; break;
                case 2: self->value = v * p->scale2; break;
                }
            }
            self->state->state = 3;
        }
    }
}