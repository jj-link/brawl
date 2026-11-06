#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(void*, void*);
};
struct Ctx {
    char pad[0x14];
    Object_vptr_0* sub;
    char pad2[8];
    float x, y, z;
};
struct Vec {
    float x, y, z;
};
extern "C" void fn_802D107C(Ctx* self, void* arg1, Vec* out) {
    self->sub->slot10(arg1, out);
    out->x = out->x + self->x;
    out->y = out->y + self->y;
    out->z = out->z + self->z;
}
