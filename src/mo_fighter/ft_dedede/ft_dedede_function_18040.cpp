#pragma force_active on
class FtDeddeVirtualBase {
public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
};

extern "C" void fn_117_18040(FtDeddeVirtualBase* self) {
    self->slot24();
}
