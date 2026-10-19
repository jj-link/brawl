#pragma force_active on
class ToonLinkDispatch {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void callback();
};

extern "C" void fn_121_18614(void* self) {
    reinterpret_cast<ToonLinkDispatch*>(
        static_cast<char*>(self) + 0x1724)->callback();
}
