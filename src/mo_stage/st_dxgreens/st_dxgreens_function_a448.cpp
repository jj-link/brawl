#pragma force_active on
struct DxGreensObject {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual bool check();
};

extern "C" bool fn_79_A448(DxGreensObject* object) {
    return !object->check();
}
