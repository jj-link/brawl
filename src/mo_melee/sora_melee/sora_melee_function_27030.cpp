#pragma force_active on
extern "C" void fn_27_2EF48(void* arg0, unsigned char value);

class sora_melee_inner {
public:
    virtual void* vf0();
    virtual void* vf1(int a);
};

class sora_melee_outer {
public:
    char pad[0x28];
    sora_melee_inner* inner;
};

extern "C" {
void fn_27_27030(sora_melee_outer* self, unsigned char value, int b) {
    fn_27_2EF48(self->inner->vf1(b), value);
}
}
