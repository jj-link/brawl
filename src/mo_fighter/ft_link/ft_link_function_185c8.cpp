#pragma force_active on
class LinkCallback {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void callback();
};

extern "C" void fn_93_185C8(char* owner) {
    reinterpret_cast<LinkCallback*>(owner + 0x1724)->callback();
}
