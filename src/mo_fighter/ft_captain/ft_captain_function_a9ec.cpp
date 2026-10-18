#pragma force_active on
struct FtCaptainEmbedded {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

extern "C" void fn_100_A9EC(char* self) {
    reinterpret_cast<FtCaptainEmbedded*>(self + 0xC018)->v2();
}
