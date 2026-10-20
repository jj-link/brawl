#pragma force_active on
struct fn27Outer;
struct fn27Interface {
    virtual void unused();
    virtual fn27Outer* get();
};
struct fn27Object {
    char pad[0x28];
    fn27Interface* object;
};
extern "C" int fn_27_2EF90(fn27Outer* self);
extern "C" int fn_27_27184(fn27Object self) {
    return fn_27_2EF90(self.object->get());
}
