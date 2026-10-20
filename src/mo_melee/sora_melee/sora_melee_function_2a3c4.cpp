#pragma force_active on
struct Outer;

struct Interface {
    virtual void unused();
    virtual Outer* get();
};

struct Context {
    char pad[0x28];
    Interface* object;
};

extern "C" int fn_27_30114(Outer* self);

extern "C" int fn_27_2A3C4(Context self) {
    return fn_27_30114(self.object->get());
}
