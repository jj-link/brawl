#pragma force_active on
struct Object {
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
    virtual void callback(void**);
};

extern "C" void fn_126_6C4C(Object* object, void** values, int count) {
    if (values == 0 || count <= 0) {
        return;
    }
    for (int i = 0; i < count; ++i) {
        object->callback(values + i);
    }
}
