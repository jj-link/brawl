#pragma force_active on

#include <nw4r/math/math_arithmetic.h>

extern "C" const float lbl_62_rodata_168;
extern "C" const float lbl_62_rodata_16C;

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Data {
    unsigned char pad[0xC4];
    float vel;
    float unused;
    float vel_rest;
    float dist;
    float vel1;
};

struct Ground_base {
    char pad[0x3C];
};

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
    virtual void fn_62_D478();
    virtual void fn_62_D4E0();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_62_DAC0();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_62_3114();
    virtual void startup();
    virtual void setNode();
    virtual void fn_62_A44();
    virtual Data* fn_62_310C();

    unsigned char pad_40[0x110];
    unsigned char a150;
    unsigned char pad_151[7];
    unsigned int a158;
    unsigned int a15c;
    float a160, a164, a168, a16c, a170, a174;
    unsigned int a178;
    unsigned char a17c;
    unsigned char pad_17d[3];
    float a180;
    unsigned int a184;
};

struct Stage_base {
    char pad[0x3C];
};

class Stage : public Stage_base {
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
    virtual void fn_62_258();
    virtual void fn_62_368();
    virtual void createObjPokeTrainer();
    virtual void fn_62_2A4C();
    virtual void fn_62_2A48();
    virtual void fn_62_2A3C();
    virtual void fn_62_2A34();
    virtual void fn_62_2A2C();
    virtual void fn_62_28A8();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_62_360();
    virtual void process();
    virtual void updateStagePositions();
};

extern "C" void fn_62_D890(Ground* self, float delta) {
        float value;
        float z;
        float x;
    if (self->a158 == 0)
        return;
    if (self->a184 == 0)
        return;

    Data* data = self->fn_62_310C();
    if (data == 0)
        return;

    self->a180 -= delta;
    if (self->a180 < lbl_62_rodata_168)
        self->a180 = lbl_62_rodata_168;

    if (self->a17c == 1) {
        float* src = (float*)(self->a158 + 0x0C);
        value = self->a170 - data->vel1 * delta;
        self->a170 = value;
        Vec3 pos;
        z = src[8];
        pos.y = src[4];
        x = src[0];
        pos.x = x;
        pos.z = z;
        self->a164 = pos.y;
        if (value < (*(float*)(self->a184 + 0x10) - lbl_62_rodata_16C)) {
            *(unsigned char*)(self->a178) = 0x0E;
            self->a150 = 0;
        }
    } else if (lbl_62_rodata_168 == self->a180) {
        self->a170 += data->vel_rest * delta;
        if (self->a170 > lbl_62_rodata_168)
            self->a170 = lbl_62_rodata_168;
    } else {
        self->a170 -= data->vel * delta;
        if (nw4r::math::FAbs(self->a170) >= data->dist)
            self->a17c = 1;
    }
}
