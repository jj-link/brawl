#pragma force_active on
struct ScnMdl {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void* removeAnmObj(int type); // 0x3C
    virtual void* getAnmObj(int type);    // 0x40
};

struct gfModelAnimation {
    char pad0[0x14];
    void* m_anmObjTexSrtRes; // 0x14
};

extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);

extern "C" void unbindTexSrtAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(gfModelAnimation* self, ScnMdl* sceneModel) {
    void* anmObj = sceneModel->getAnmObj(4);
    if (anmObj)
        sceneModel->removeAnmObj(4);
    if (self->m_anmObjTexSrtRes && self->m_anmObjTexSrtRes == anmObj) {
        Destroy__Q34nw4r3g3d6G3dObjFv(self->m_anmObjTexSrtRes);
        self->m_anmObjTexSrtRes = 0;
    }
}
