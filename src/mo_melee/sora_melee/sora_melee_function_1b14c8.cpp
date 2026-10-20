#pragma force_active on
class soInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

extern "C" void fn_27_1B14C8(char* p) {
    soInner* inner = (soInner*)(p + 0x10);
    inner->vf3();
}
