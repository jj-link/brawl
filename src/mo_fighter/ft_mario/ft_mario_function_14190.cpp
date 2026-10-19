#pragma force_active on
struct MarioDispatch {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void dispatch();
};

struct MarioObject {
    unsigned char prefix[0x1478];
    MarioDispatch dispatchObject;
};

extern "C" void fn_91_14190(MarioObject* object) {
    object->dispatchObject.dispatch();
}
