#pragma force_active on
class FtZakoSubObject {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

extern "C" void fn_126_B708(char* self) {
    reinterpret_cast<FtZakoSubObject*>(self + 0x7b90)->vf2();
}
