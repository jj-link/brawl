#pragma force_active on

class Class_80465F18 {
public:
    virtual void fn_8019B94C();
    virtual void fn_8019A670();
    virtual void fn_8019BA6C();
    virtual void fn_8019BA60();
    virtual void fn_8019BA30();
    virtual void fn_8019A0D4();
    virtual void fn_8019A15C();
    virtual void fn_8019A05C();
    virtual void fn_8019A1B0();
    virtual void fn_8019A238();
    virtual void fn_8019A28C();
    virtual void fn_8019A47C();
    virtual void fn_8019A874();
    virtual void fn_80199DF8();
    virtual void fn_80199EE4(int index);

    unsigned char padding[0x14];
    int count;
};

extern "C" void fn_80199FFC(Class_80465F18* self)
{
    for (int i = 0; i < self->count; ++i) {
        self->fn_80199EE4(i);
    }
}
