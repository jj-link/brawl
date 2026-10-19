#pragma force_active on
extern "C" {
void fn_27_131CD0(void*);

class FtObj {
public:
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v21(unsigned int);
};

void fn_91_99E8(void* self, int param) {
    fn_27_131CD0(self);
    if (param != 2) {
        FtObj* obj = *reinterpret_cast<FtObj**>(static_cast<unsigned char*>(self) + 0x60);
        obj = *reinterpret_cast<FtObj**>(reinterpret_cast<unsigned char*>(obj) + 0xd8);
        obj = *reinterpret_cast<FtObj**>(reinterpret_cast<unsigned char*>(obj) + 0x64);
        obj->v21(0x1200003Du);
    }
}
}
