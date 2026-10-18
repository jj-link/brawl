#pragma force_active on
struct FtPitBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

extern "C" void fn_112_BDC8(char* object) {
    FtPitBase* base = reinterpret_cast<FtPitBase*>(object + 0x29200);
    base->v2();
}
