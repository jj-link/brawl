#pragma force_active on
class FtPokeObj {
public:
    virtual int fn0();
    virtual int fn1();
    virtual int fn2();
    virtual int fn3();
    virtual int fn4();
};

extern "C" int fn_116_19620(char* self) {
    FtPokeObj* obj = (FtPokeObj*)(self + 0x15d44);
    return obj->fn2();
}
