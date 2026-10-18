#pragma force_active on
class fn_120_AF50_Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

extern "C" void fn_120_AF50(void* self) {
    fn_120_AF50_Base* obj = reinterpret_cast<fn_120_AF50_Base*>(static_cast<char*>(self) + 0x11CF4);
    obj->v2();
}
