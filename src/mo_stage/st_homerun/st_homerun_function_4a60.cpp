#pragma force_active on
class Obj {
public:
    virtual void f0(int);
    virtual void f1(int);
    virtual void f2(int);
    virtual void f3(int);
    virtual void f4(int);
    virtual void f5(int);
};

extern "C" void fn_88_4A60(char* self, int idx)
{
    void** table = *(void***)(self + 0x48);
    char* entry = (char*)table[idx];
    if (entry == 0) {
        return;
    }
    Obj* obj = *(Obj**)(entry + 0x18);
    return obj->f5(idx);
}
