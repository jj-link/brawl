#pragma force_active on
class PikachuDispatch {
public:
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
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void dispatch();
};

extern "C" void fn_98_14E64(PikachuDispatch* object) {
    object->dispatch();
}
