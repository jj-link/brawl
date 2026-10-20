#pragma force_active on
class fn27Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(int x);
    virtual void v5(int a, int b, int c, int d);
};

struct fn27Owner {
    char pad0[0x25a0];
    fn27Obj b;
    char pad1[0x2aac - 0x25a0 - sizeof(fn27Obj)];
    fn27Obj a;
};

extern "C" int fn_27_28B9A8(fn27Owner* self) {
    int r = self->a.v4(0x1000001a);
    if (r != 0) {
        self->b.v5(r, 0, 0, 0);
    }
    return 0;
}
