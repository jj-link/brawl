#pragma force_active on
class FtSubObjectView {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
};

extern "C" void fn_115_B99C(void* object) {
    return static_cast<FtSubObjectView*>(static_cast<void*>(static_cast<char*>(object) + 0x262d4))->slot2();
}
