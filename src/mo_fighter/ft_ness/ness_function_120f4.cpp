#pragma force_active on
struct NessCallbackObject {
    virtual void callback0();
    virtual void callback1();
    virtual void callback2();
    virtual void callback3();
};

extern "C" void fn_101_120F4(NessCallbackObject* object) {
    object->callback3();
}
