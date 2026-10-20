#pragma force_active on
struct LuigiArrayDispatch {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void append(const unsigned int&);
};

extern "C" void fn_99_7E24(
    LuigiArrayDispatch* self, const unsigned int* values, int count)
{
    if (values == 0 || count <= 0)
        return;

    for (int i = 0; i < count; ++i)
        self->append(values[i]);
}
