#pragma force_active on
typedef unsigned int u32;

struct Interface {
    virtual void a();
    virtual void* get();
};

struct Object {
    char padding[0x58];
    Interface* member;
};

extern "C" u32 fn_27_422BC(void* self);

extern "C" u32 fn_27_43B78(Object self) {
    return fn_27_422BC(self.member->get());
}
