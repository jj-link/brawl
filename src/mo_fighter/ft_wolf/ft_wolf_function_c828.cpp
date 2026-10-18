#pragma force_active on
class FighterMemberIface {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

extern "C" void fn_125_C828(void* object) {
    FighterMemberIface* member = reinterpret_cast<FighterMemberIface*>(static_cast<char*>(object) + 0x1C6D8);
    member->vf2();
}
