#pragma force_active on

extern "C" int fn_8018BC7C(void* self, unsigned int key);

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int process(int arg);
};

struct Owner {
    char pad[0x28];
    Obj* m28;
};

extern "C" int fn_801832FC(Owner* self, int arg) {
    int r = fn_8018BC7C((char*)self + 0x1C, arg);
    if (r != 0) {
        return r;
    }
    Obj* obj = self->m28;
    if (obj != 0) {
        int r2 = obj->process(arg);
        if (r2 != 0) {
            return r2;
        }
    }
    return 0;
}
