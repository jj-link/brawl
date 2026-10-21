#pragma force_active on
typedef unsigned int u32;

struct Outer;

struct Interface {
    virtual void unused();
    virtual Outer* get();
};

struct Object {
    char pad[0x18];
    Interface* object;
};

extern "C" u32 fn_27_B1D98(Outer*);

extern "C" u32 fn_27_B2D80(Object self) {
    return fn_27_B1D98(self.object->get());
}
