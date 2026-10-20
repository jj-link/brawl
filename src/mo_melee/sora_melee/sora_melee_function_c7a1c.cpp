#pragma force_active on
extern "C" {
extern unsigned char lbl_27_data_206B0[];
void fn_27_C8684(void*);
void* fn_27_C86F0(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int), unsigned long, int);
}

struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();

    unsigned int flags;
    unsigned char elements[0xC8];
};

extern "C" Object* fn_27_C7A1C(Object* self) {
    *(void**)self = lbl_27_data_206B0;
    self->flags |= 0xFFFE0000;
    __construct_array(self->elements, fn_27_C8684,
                      (void (*)(void*, int))fn_27_C86F0, 0x14, 10);
    self->v8();
    return self;
}
