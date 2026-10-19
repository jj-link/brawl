#pragma force_active on
typedef unsigned char Byte;

struct WorkPrefix {
    unsigned int header[2];
};

class CaptainWork : public WorkPrefix {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void slot3C() = 0;
    virtual void slot40() = 0;
    virtual void slot44() = 0;
    virtual void slot48() = 0;
    virtual void slot4C() = 0;
    virtual void slot50() = 0;
    virtual void slot54() = 0;
    virtual void slot58() = 0;
    virtual void slot5C() = 0;
    virtual void slot60() = 0;
    virtual void slot64() = 0;
    virtual void slot68() = 0;
    virtual void slot6C() = 0;
};

extern "C" void fn_100_7D70(void*, void*, int, void*, int, void*, int);

extern "C" void* fn_100_8270(Byte* self) {
    fn_100_7D70(self + 0x1C0, self, 0x4D,
               self + 0x134, 0x20, self + 0x1B4, 3);
    reinterpret_cast<CaptainWork*>(self + 0x1C0)->slot6C();
    return self;
}
