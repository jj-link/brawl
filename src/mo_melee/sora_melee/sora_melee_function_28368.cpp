#pragma force_active on
struct Result {
    unsigned int unused;
    void* value;
};

struct Interface {
    virtual void slot0();
    virtual Result* get();
};

struct Object {
    char padding[0x28];
    Interface* interface;
};

extern "C" void fn_80137590(void*);

extern "C" void fn_27_28368(Object object) {
    fn_80137590(object.interface->get()->value);
}
