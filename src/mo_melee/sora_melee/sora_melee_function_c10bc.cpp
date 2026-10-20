#pragma force_active on
class Object {
    unsigned char padding[0x38];

public:
    virtual void method0();
    virtual void method1();
};

extern "C" void* lbl_27_data_179B0[4];

extern "C" Object* fn_27_C10BC(Object* self) {
    *(void**)((unsigned char*)self + 0x38) = lbl_27_data_179B0;
    self->method1();
    return self;
}
