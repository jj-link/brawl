#pragma force_active on
class WorkModule {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual int getInt(int id) = 0;
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
    virtual bool isFlag(int id) = 0;
};

struct ModuleTable {
    unsigned char padding[0x64];
    WorkModule* work;
};

struct ModuleAccessor {
    unsigned char padding[0xD8];
    ModuleTable* modules;
};

struct Fighter {
    unsigned char padding[0x60];
    ModuleAccessor* accessor;
};

extern "C" int fn_96_E010(Fighter* fighter) {
    return !fighter->accessor->modules->work->isFlag(0x12000042)
        ? -1 : fighter->accessor->modules->work->getInt(0x10000048);
}
