#pragma force_active on
struct Outer;
struct Interface {
    virtual void unused();
    virtual Outer* get();
};
struct Context {
    char pad[0x30];
    Interface* object;
};
extern "C" unsigned int fn_27_A75B0(Outer* self);
extern "C" unsigned int fn_27_A47C0(Context self) {
    return fn_27_A75B0(self.object->get());
}
