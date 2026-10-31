#pragma force_active on
class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(int a, int b);
};

extern "C" {
void fn_107_1227C(void* unused, char* self, int id)
{
    if (id == 0x118) {
        return;
    }
    char* a = *(char**)(self + 0xd8);
    Obj* obj = *(Obj**)(a + 0x84);
    obj->v15(2, 0);
}
}
