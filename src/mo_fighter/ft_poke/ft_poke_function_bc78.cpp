#pragma force_active on
class ftPokeObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

extern "C" void fn_116_BC78(char* self)
{
    ((ftPokeObj*)(self + 0x179F4))->v2();
}
