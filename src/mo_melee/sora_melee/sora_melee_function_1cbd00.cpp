#pragma force_active on
class soSub {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

extern "C" void fn_27_1CBD00(char* self) {
    ((soSub*)(self + 0x10))->vf1();
}
