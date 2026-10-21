#pragma force_active on
struct WorkModule {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void setInt(int, int);
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void onFlag(int);
};

struct ModuleTable {
    char pad[0x64];
    WorkModule* work;
};

struct ModuleOwner {
    char pad[0xD8];
    ModuleTable* modules;
};

struct Fighter {
    char pad[0x60];
    ModuleOwner* owner;
};

extern "C" void fn_27_12BAF8(void*, int);

extern "C" void fn_122_D304(Fighter* self, int param) {
    self->owner->modules->work->onFlag(0x1200003D);
    fn_27_12BAF8(self, param);
    self->owner->modules->work->setInt(6, 0x10000033);
}
