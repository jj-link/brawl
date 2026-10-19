#pragma force_active on
// Placeholder polymorphic type. The original loads the vtable pointer from
// offset 0 and calls the entry at offset 0xC with no other arguments. In this
// layout, two vtable entries precede the first declared method, so vf1 sits
// at offset 0xC. The real class behind this pointer has not been identified.
class fn_41_C558_Object {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

extern "C" void fn_41_C558(fn_41_C558_Object* obj) {
    obj->vf1();
}
