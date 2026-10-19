#pragma force_active on
struct soGeneralWorkBase {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual bool vf4();
};

extern "C" {
    bool fn_27_11B890(soGeneralWorkBase* work) {
        return !work->vf4();
    }
}
