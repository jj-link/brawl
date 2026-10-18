#pragma force_active on
class FieldObj
{
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

extern "C" void fn_110_A9D8(char *self)
{
    FieldObj *obj = (FieldObj *)(self + 0xCD4C);
    obj->vf2();
}
