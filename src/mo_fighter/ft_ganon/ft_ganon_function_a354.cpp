#pragma force_active on
class FtSubObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

extern "C" {
void fn_109_A354(void* object)
{
    reinterpret_cast<FtSubObj*>(static_cast<char*>(object) + 0xC3F8)->f2();
}
}
