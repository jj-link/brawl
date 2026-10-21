#pragma force_active on
typedef unsigned int u32;

struct Result {
    u32 unused;
    void* data;
};

struct Interface {
    virtual void func0();
    virtual Result* get(void* arg);
};

struct Object {
    u32 padding[10];
    Interface* iface;
};

extern "C" void fn_80134250(void*, void*);
extern "C" void fn_801341D8(void*, void*);

extern "C" void fn_27_2ABEC(Object* self, void* arg1, void* arg2, void* arg3) {
    void* data = self->iface->get(arg3)->data;
    fn_80134250(data, arg1);
    data = self->iface->get(arg3)->data;
    fn_801341D8(data, arg2);
}
