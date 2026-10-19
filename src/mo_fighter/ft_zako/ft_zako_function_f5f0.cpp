#pragma force_active on
class ZakoSub {
public:
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
};

extern "C" void fn_126_F5F0(char* self) {
    reinterpret_cast<ZakoSub*>(self + 0x7b90)->fn2();
}
