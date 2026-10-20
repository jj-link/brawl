#pragma force_active on
extern const float lbl_27_rodata_7E8;

struct Base {
    unsigned char padding[8];
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void callback();
};

struct Object : Base {
    void* field_0C;
    float value;
    unsigned char flag;
};

extern "C" void fn_27_5C6B4(Object* self)
{
    float value = lbl_27_rodata_7E8;
    self->flag = 0;
    self->value = value;
    self->callback();
}
