#pragma force_active on
struct stTriggerMng;
struct stTriggerData;
struct AnimationData { char pad[0x1c]; unsigned short frames; };
class Animation {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void setFrame(float);
    char pad[0x28];
    AnimationData* data;
};
struct Model { char pad[0xc]; Animation* animation; };
struct StageBase { char pad[0x3c]; };
class Stage : public StageBase {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void update(int);
    char pad40[8];
    Model** models;
    char pad4c[0x104];
    unsigned char* data;
};
extern "C" {
extern stTriggerMng* g_stTriggerMng;
bool getTriggerFlag__12stTriggerMngFP13stTriggerDatab(stTriggerMng*, stTriggerData*, bool);
void changeNodeAnim__9grGimmickFUlUl(Stage*, unsigned long, unsigned long);
void fn_27_273694(Stage* self) {
    if (!getTriggerFlag__12stTriggerMngFP13stTriggerDatab(g_stTriggerMng, (stTriggerData*)(self->data + 0x1d8), true)) {
        if (self->data[0x1da] & 1) self->update(0);
    } else {
        if (!(self->data[0x1da] & 1)) self->update(0);
    }
    if (getTriggerFlag__12stTriggerMngFP13stTriggerDatab(g_stTriggerMng, (stTriggerData*)(self->data + 0x1dc), false) == 1U) {
        changeNodeAnim__9grGimmickFUlUl(self, 0, 0);
        Animation* animation = (*self->models)->animation;
        animation->setFrame((float)animation->data->frames);
    }
}
}
