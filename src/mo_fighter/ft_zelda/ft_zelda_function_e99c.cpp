#pragma force_active on
class VBase {
public:
    virtual void* f0();
    virtual void* f1();
    virtual void* f2();
    virtual void* f3();
    virtual void* f4();
    virtual void* f5();
    virtual void* f6();
    virtual void* f7(int);
};

extern "C" void* fn_104_E99C(void* a, char* b, int c)
{
    if (c == 0x11a) {
        return a;
    }
    VBase* q = *(VBase**)(*(char**)(b + 0xd8) + 0x58);
    return q->f7(1);
}
