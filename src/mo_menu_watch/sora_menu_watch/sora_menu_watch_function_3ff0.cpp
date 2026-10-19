#pragma force_active on
extern "C" int fn_800B61C0(void*);

struct Watch {
    unsigned char pad_000[0x108];
    void* resource;
    unsigned char pad_10c[0x94];
    struct Object* object;
    unsigned char pad_1a4[0x360];
    int fallback;
    unsigned char pad_508[0x40];
    int flag;
    unsigned char pad_54c[0x80c];
    unsigned char state;
};

struct Object {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13(void*);
};

extern "C" int fn_15_3FF0(Watch* self) {
    int result;
    if (fn_800B61C0(self->resource)) {
        self->object->f13(*(void**)((char*)self->resource + 0x10));
        if (self->state) {
            if (self->flag) {
                result = 4;
            } else {
                result = 6;
            }
        } else {
            result = 6;
        }
    } else {
        result = self->fallback;
    }
    return result;
}
