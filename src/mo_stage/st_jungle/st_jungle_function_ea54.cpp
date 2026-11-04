#pragma force_active on

typedef unsigned int u32;

struct Vec3f {
    float x, y, z;
};

struct snd3DGenerator;

struct CallbackData {
    char pad00[4];
    u32 flags04;
    char pad08[0x2C - 0x08];
    Vec3f pos2C;
    char pad38[0x80 - 0x38];
    u32 id80;
    u32 flags84;
    char pad88[0xA0 - 0x88];
    Vec3f posA0;
};

struct Callback {
    void* vtable;
    CallbackData* data;
    void* owner;
    u32 state;
};

struct ObjectBase {
    char pad00[0x3C];
};

struct Object : ObjectBase {
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
    virtual void fn_51_E558();
    virtual void fn_51_E648();
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
    virtual void fn_51_33B4();
    virtual void startup();
    virtual void fn_51_EB2C();
    virtual void fn_51_994();
    virtual void fn_51_33AC();
    virtual void fn_51_33A8();
    virtual void fn_51_2830();
    virtual void fn_51_33A0();
    virtual void fn_51_3394();
    virtual void fn_51_3384();
    virtual void fn_51_3374();
    virtual void getNodeIndex();
    virtual void getNodePosition(Vec3f*, u32, u32, float);

    char pad40[0xD0 - 0x40];
    Callback callback;
    char padE0[0x19C - 0xE0];
    Vec3f pos19C;
    char pad1A8[0x1B8 - 0x1A8];
    Vec3f pos1B8;
    float scale1C4;
    u32 id1C8;
    char generator[4];
};

extern "C" void fn_51_3E64(Object*);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(snd3DGenerator*, Vec3f*);

extern "C" void fn_51_EA54(Object* self) {
    fn_51_3E64(self);

    Callback* callback = &self->callback;
    if (callback) {
        callback->data->flags04 |= 0x10;
        callback->data->pos2C = self->pos19C;
        callback->data->flags84 |= 4;
        callback->data->id80 = self->id1C8;
        callback->data->posA0 = self->pos1B8;
        float y = callback->data->posA0.y;
        callback->data->posA0.y = y * self->scale1C4;

        Vec3f position;
        self->getNodePosition(&position, 0, self->id1C8, y);
        setPos__14snd3DGeneratorFP5Vec3f(
            (snd3DGenerator*)self->generator, &position);
    }
}
