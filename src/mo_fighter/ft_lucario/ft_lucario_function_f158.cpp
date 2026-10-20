#pragma force_active on
extern const float lbl_118_rodata_30;
extern const float lbl_118_rodata_3C;

class FtObj {
public:
    virtual ~FtObj();
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
    virtual void setFloat(float, unsigned long);
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void setInt(unsigned long);
};

extern "C" void fn_118_F158(void* self) {
    unsigned char* base = *(unsigned char**)((unsigned char*)self + 0xD8);
    FtObj* obj = *(FtObj**)(base + 0x64);
    obj->setFloat(lbl_118_rodata_30, 0x11000000);
    obj->setFloat(lbl_118_rodata_3C, 0x11000001);
    obj->setInt(0x12000003);
}
