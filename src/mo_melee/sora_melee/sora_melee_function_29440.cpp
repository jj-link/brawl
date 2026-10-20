#pragma force_active on
struct Result {
    unsigned int unused;
    void* value;
};

struct Interface {
    virtual void unused();
    virtual Result* get();
};

struct Object {
    unsigned char padding[0x28];
    Interface* interface;
};

extern "C" void fn_80134534(void*, int);

extern "C" void fn_27_29440(Object* __restrict object) {
    fn_80134534(object->interface->get()->value, 5);
}
