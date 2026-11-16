#include <it/it_manager.h>
#include <snd/snd_3d_generator.h>
#pragma force_active on

extern "C" const float lbl_56_rodata_80;
extern "C" const float lbl_56_rodata_114;

struct Point { float x, y, z; };
struct Point2 { float x, y; };
struct Sub { char pad[8]; Point pos; Point rot; };
struct Holder { int pad; Sub* sub; };

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void slot6();
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
    virtual void slot22();
    virtual void slot23();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(unsigned long);
    char pad2[0xD0 - 0x40];
    Holder holder;
    char pad3[0x16C - 0xD8];
    int field16C;
    float field170, field174, field178, field17C;
    char pad4[4];
    int field184, field188;
    float field18C;
    char pad5[0x1AC - 0x190];
    int itemId;
    unsigned char field1B0, field1B1;
    char pad6[0x1B8 - 0x1B2];
    snd3DGenerator generator;
    int soundId;
};

inline void removeId(int id) {
    if (id != 0) {
        itManager* manager = itManager::getInstance();
        if (manager != 0) {
            BaseItem* item = manager->getItemFromInstanceId(id);
            if (item != 0) manager->removeItem(item);
        }
    }
}

extern "C" void fn_56_4780(Object_vptr_3c* self) {
    Holder* holder = &self->holder;
    if (holder != 0) {
        self->field16C = 0;
        self->field18C = lbl_56_rodata_80;
        self->field184 = 0;
        self->field188 = 0;
        Point p = { lbl_56_rodata_80, lbl_56_rodata_114, lbl_56_rodata_80 };
        holder->sub->pos = p;
        Point r = { lbl_56_rodata_80, lbl_56_rodata_80, lbl_56_rodata_80 };
        holder->sub->rot = r;
        self->field170 = holder->sub->pos.x;
        self->field174 = holder->sub->pos.y;
        Point2 offset = { lbl_56_rodata_80, lbl_56_rodata_80 };
        self->field178 = offset.x;
        self->field17C = offset.y;
        self->setVisibility(0);
        if (self->soundId != -1) {
            self->generator.stopSE(self->soundId, 0);
            self->soundId = -1;
        }
        int id = self->itemId;
        self->field1B0 = 0;
        self->itemId = 0;
        self->field1B1 = 0;
        removeId(id);
    }
}
