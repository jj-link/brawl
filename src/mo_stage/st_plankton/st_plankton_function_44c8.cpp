#include <nw4r/g3d/g3d_scnmdl.h>
#include <nw4r/g3d/g3d_resmdl.h>

#pragma force_active on

struct Parameters {
    char pad0[4];
    float speed;
    char pad8[0x70 - 8];
    float scales[3];
    GXColor colors1[15];
    GXColor colors2[15];
};

struct Position {
    char pad[0x20];
    unsigned char count;
};

struct GameMode {
    char pad[0xE];
    unsigned char flags;
};

struct Global {
    char pad[8];
    GameMode* mode;
};

struct Ground_base {
    char pad[0x3C];
};

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

    char pad40[4];
    nw4r::g3d::ScnMdl** model;
    char pad48[0x158 - 0x48];
    Position* position;
    char pad15C[8];
    unsigned char previousCount;
    char pad165[3];
    float timer;
    char pad16C[0x198 - 0x16C];
    unsigned char scaleEnabled;
};

struct ExtendedCopiedMatAccess : nw4r::g3d::ScnMdl::CopiedMatAccess {
    char padding[16];

    ExtendedCopiedMatAccess(nw4r::g3d::ScnMdl* scn, unsigned long id)
        : nw4r::g3d::ScnMdl::CopiedMatAccess(scn, id) {}
};

extern "C" {
extern const float lbl_74_rodata_D0;
extern char lbl_74_data_D60[];
extern Global* g_GameGlobal;
void fn_80190A3C(nw4r::g3d::ResMatTevColor*, bool);
}

extern "C" void fn_74_44C8(Ground* self, float delta) {
    Parameters* param = self->fn_74_2F7C();
    if (param == 0)
        return;

    self->timer -= delta;
    if (self->timer < lbl_74_rodata_D0)
        self->timer = lbl_74_rodata_D0;

    Position* position = self->position;
    unsigned char count = position->count;
    if (count == self->previousCount) {
        if (lbl_74_rodata_D0 == self->timer && count != 0)
            position->count = count - 1;
        return;
    }

    nw4r::g3d::ResMdl mdl;
    nw4r::g3d::ResMat mat;
    nw4r::g3d::ResMatTevColor tev;
    nw4r::g3d::ScnMdl* scn = *self->model;
    if (!scn)
        return;

    mdl = nw4r::g3d::ResMdl(*(void**)((char*)scn + 0xE8));
    if (!mdl.IsValid())
        return;

    mat = mdl.GetResMat(lbl_74_data_D60);
    if (!mat.IsValid())
        return;

    ExtendedCopiedMatAccess access(scn, mat.ref().m_id);
    tev = access.GetResMatTevColor(false);
    if (!tev.IsValid())
        return;

    unsigned char index = self->position->count;
    if (index >= 15)
        index = 14;

    GXColor color;
    color.r = param->colors1[index].r;
    color.g = param->colors1[index].g;
    color.b = param->colors1[index].b;
    color.a = param->colors1[index].a;
    tev.GXSetTevColor(1, color);

    color.r = param->colors2[index].r;
    color.g = param->colors2[index].g;
    color.b = param->colors2[index].b;
    color.a = param->colors2[index].a;
    tev.GXSetTevColor(2, color);

    fn_80190A3C(&tev, false);
    mat.DCStore(false);

    self->previousCount = self->position->count;
    self->timer = param->speed;
    if (self->scaleEnabled == 1) {
        GameMode* mode = g_GameGlobal->mode;
        if (mode) {
            switch ((int)((mode->flags >> 5) & 7)) {
            case 0:
                self->timer *= param->scales[0];
                break;
            case 1:
                self->timer *= param->scales[1];
                break;
            case 2:
                self->timer *= param->scales[2];
                break;
            }
        }
    }
}
