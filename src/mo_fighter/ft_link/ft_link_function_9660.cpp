#pragma force_active on
extern "C" {
void fn_27_12DCA8(void*);
extern const float lbl_93_rodata_C;

struct FtLinkSubObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(float, unsigned int);
};

void fn_93_9660(void* object) {
    fn_27_12DCA8(object);
    unsigned char* obj = static_cast<unsigned char*>(object);
    void* p = *reinterpret_cast<void**>(obj + 0x60);
    p = *reinterpret_cast<void**>(static_cast<unsigned char*>(p) + 0xd8);
    p = *reinterpret_cast<void**>(static_cast<unsigned char*>(p) + 0x64);
    reinterpret_cast<FtLinkSubObj*>(p)->v13(lbl_93_rodata_C, 0x11000016);
}
}
