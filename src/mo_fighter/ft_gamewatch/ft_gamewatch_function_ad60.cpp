#pragma force_active on
extern "C" void fn_27_13604C(void* self);

class FtObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void setValue(unsigned long v);
};

extern "C" void fn_107_AD60(void* self) {
    fn_27_13604C(self);
    unsigned char* a = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x60);
    unsigned char* b = *reinterpret_cast<unsigned char**>(a + 0xd8);
    FtObj* c = *reinterpret_cast<FtObj**>(b + 0x64);
    c->setValue(0x1200003Eul);
}
