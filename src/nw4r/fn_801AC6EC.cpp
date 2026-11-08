#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(int a, int b, void* c);
};

struct Owner {
    char pad[0x2888];
    Object_vptr_0* unk2888;
};

extern "C" {
Object_vptr_0* fn_801AC6EC(Owner* self) {
    Object_vptr_0* temp_r31 = self->unk2888;
    if (temp_r31 != 0) {
        temp_r31->slot1(0x10003, 0, self);
        self->unk2888 = 0;
    }
    return temp_r31;
}
}
