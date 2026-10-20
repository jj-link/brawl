#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_204D8[];
void fn_27_C93B8(void*);
void fn_27_C944C(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*),
                       unsigned long, int);
}

class Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void init();

    u32 flags;
    char array[0x108];
};

extern "C" Object* fn_27_C8730(Object* self) {
    *(void**)self = lbl_27_data_204D8;
    self->flags |= 0xFFFE0000;
    __construct_array(self->array, fn_27_C93B8, fn_27_C944C, 0x18, 11);
    self->init();
    return self;
}
