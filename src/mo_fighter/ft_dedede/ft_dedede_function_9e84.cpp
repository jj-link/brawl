#pragma force_active on
extern "C" void* fn_117_946C();
extern "C" void fn_27_135EDC(void*, void*, void*);

namespace {
struct DededeDispatch {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(void*, void*);
};
}

extern "C" void fn_117_9E84(void* self, void* a, void* b) {
    DededeDispatch* obj = static_cast<DededeDispatch*>(fn_117_946C());
    obj->slot10(a, b);
    fn_27_135EDC(self, a, b);
}
