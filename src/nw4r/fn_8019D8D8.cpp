#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(unsigned int, int, Object_vptr_0*);
    virtual void slot2(int);

    Object_vptr_0* parent;
};

extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(Object_vptr_0* self) {
    Object_vptr_0* parent = self->parent;
    if (parent != 0) {
        parent->slot1(0x10001, 0, self);
    }
    if (self != 0) {
        self->slot2(1);
    }
}
