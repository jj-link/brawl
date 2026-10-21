#pragma force_active on
typedef unsigned int u32;
class Accessor {
public:
    virtual void unused();
    virtual void* get();
};
struct Object {
    unsigned char padding[0x58];
    Accessor* accessor;
};
extern "C" u32 fn_27_42898(void* self);
extern "C" u32 fn_27_44E7C(Object self) {
    return fn_27_42898(self.accessor->get());
}
