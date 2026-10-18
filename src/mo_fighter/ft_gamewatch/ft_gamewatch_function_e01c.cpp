#pragma force_active on
class FtObj {
public:
    virtual void* f0();
    virtual void* f1();
    virtual void* f2();
    virtual void* f3();
};

extern "C" void* fn_107_E01C(char* self) {
    FtObj* obj = (FtObj*)(self + 0x1F80C);
    return obj->f2();
}
