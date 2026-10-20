#pragma force_active on
typedef unsigned int u32;

class soSubObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(u32 a, u32 b);
    virtual void vf6();
    virtual void vf7();
};

struct soArgData {
    u32 a;
    u32 b;
};

struct soHolder {
    char pad[0x2aac];
    soSubObj sub;
};

extern "C" {
void fn_27_2851AC(soHolder* self, const soArgData* d) {
    self->sub.vf5(d->a, 0x1000001d);
    self->sub.vf5(d->b, 0x1000001e);
}
}
