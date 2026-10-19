#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_27_12BAF8(void* object, int param);

class LuigiSubObj {
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19(unsigned int id);
};

extern "C" void fn_99_7F8C(void* object, int param) {
    u8* self = static_cast<u8*>(object);
    LuigiSubObj* p = *reinterpret_cast<LuigiSubObj**>(*reinterpret_cast<u8**>(*reinterpret_cast<u8**>(self + 0x60) + 0xD8) + 0x64);
    p->v19(0x1200003D);
    fn_27_12BAF8(object, param);
}
