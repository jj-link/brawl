#pragma force_active on
class IceClimberSys {
public:
    virtual ~IceClimberSys();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual void unk4();
    virtual void unk5();
    virtual void unk6();
    virtual void unk7();
    virtual void unk8();
    virtual void unk9();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void func13();
};

extern "C" void fn_105_184AC(IceClimberSys* sys)
{
    sys->func13();
}
