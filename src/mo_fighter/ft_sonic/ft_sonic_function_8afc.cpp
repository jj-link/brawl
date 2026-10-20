#pragma force_active on
struct Object {
    virtual void v0(const unsigned int*);
    virtual void v1(const unsigned int*);
    virtual void v2(const unsigned int*);
    virtual void v3(const unsigned int*);
    virtual void v4(const unsigned int*);
    virtual void v5(const unsigned int*);
    virtual void v6(const unsigned int*);
    virtual void v7(const unsigned int*);
    virtual void v8(const unsigned int*);
    virtual void v9(const unsigned int*);
    virtual void v10(const unsigned int*);
};

extern "C" void fn_123_8AFC(Object* self, const unsigned int* values, int count)
{
    if (values == 0 || count <= 0) {
        return;
    }

    for (int i = 0; i < count; ++i) {
        self->v10(&values[i]);
    }
}
