#pragma force_active on

struct Inner {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
};

struct Data {
    char pad[0x0C];
    unsigned int : 11;
    int val : 8;
    unsigned int : 13;
};

struct Object {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(int, void*);
    char padding[0x28];
    Inner* inner;
};

extern "C" void fn_27_B7024(
    Object* self, void*, void*, const Data* data, void* arg)
{
    if (data->val != -1) {
        self->inner->v07();
        self->v21(data->val, arg);
    }
}