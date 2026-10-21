#pragma force_active on
class ftComp {
public:
    virtual ~ftComp();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual float get(int id);
    virtual void set(int id, float value);
};

extern "C" void fn_118_110E4(void* unused, unsigned char* obj) {
    ftComp* c = *(ftComp**)(*(unsigned char**)(obj + 0xD8) + 0x64);
    float a = c->get(0x21000004);
    float b = c->get(0x21000005);
    float sum = a + b;
    c->set(0x21000004, sum);
}
