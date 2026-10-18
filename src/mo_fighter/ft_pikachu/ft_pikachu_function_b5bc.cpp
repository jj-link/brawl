#pragma force_active on
class PikachuVirtualIface {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
};

extern "C" void fn_98_B5BC(char* owner) {
    reinterpret_cast<PikachuVirtualIface*>(owner + 0x2A898)->slot2();
}
