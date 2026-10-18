#pragma force_active on
class FtDonkeyObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

extern "C" void fn_92_ABB0(void* self) {
    FtDonkeyObj* obj = (FtDonkeyObj*)((char*)self + 0x11fec);
    obj->v2();
}
