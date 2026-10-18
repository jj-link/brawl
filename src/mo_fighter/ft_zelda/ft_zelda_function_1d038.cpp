#pragma force_active on
class FtZeldaSubObject {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

extern "C" void fn_104_1D038(char* self) {
    FtZeldaSubObject* sub = reinterpret_cast<FtZeldaSubObject*>(self + 0x1F9C8);
    sub->vf2();
}
