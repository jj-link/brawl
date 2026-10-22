#pragma force_active on

extern "C" {
int fn_800B61C0(void*);
void fn_16_AF8(void*);
void fn_14_39BC(void*, int);
void printIndex__5MuMsgFUlUlPv(void*, unsigned long, unsigned long, void*);
int fn_800B5854(void*, int, int, int, int);
}

class Scene {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void remove(int);

    char pad[0xE0];
    int count;
};

struct Menu {
    char pad0[0xB0];
    void* resource;
    char pad1[0x1FC - 0xB4];
    Scene* scene;
    char pad2[0x24C4 - 0x200];
    int ret;
    char pad3[4];
    void* msg;
    char pad4[0x2570 - 0x24D0];
    int state;
};

extern "C" int fn_14_8238(Menu* self) {
    if (fn_800B61C0(self->resource)) {
        if (self->state != 0) {
            fn_16_AF8(&self->state);
        }
        Scene* scene = self->scene;
        int n;
        while (n = scene->count) {
            if (n == 0)
                continue;
            scene->remove(n - 1);
        }
        fn_14_39BC(self, 0);
        printIndex__5MuMsgFUlUlPv(self->msg, 0x17, 0x13, 0);
        fn_800B5854(self->resource, 1, 1, 0, 0);
        return 0x12;
    }
    return self->ret;
}
