#pragma force_active on
struct fn27Obj {
    unsigned char pad[0xb2];
    unsigned char unkB2;
};

class fn27Sub {
public:
    virtual void vf2();
    virtual fn27Obj* vf3(unsigned int p);
};

struct fn27Self {
    unsigned char pad[0x48];
    fn27Sub* sub;
};

extern "C" void fn_27_49490(fn27Self* self, unsigned char a, unsigned int b) {
    fn27Obj* obj = self->sub->vf3(b);
    obj->unkB2 = a;
}
