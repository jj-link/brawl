#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_27_131CD0(void*);

class FtWorkObj {
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
    virtual void vf19(u32 flag);
};

extern "C" void fn_112_9984(void* self, int arg) {
    fn_27_131CD0(self);
    if (arg != 2) {
        FtWorkObj* obj = *(FtWorkObj**)(*(u8**)(*(u8**)((u8*)self + 0x60) + 0xd8) + 0x64);
        obj->vf19(0x1200003D);
    }
}
