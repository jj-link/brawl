#pragma force_active on
struct WorkManageModule {
    virtual bool isNull() const;
    virtual ~WorkManageModule();
    virtual void activate();
    virtual void setWork(unsigned int, void*);
    virtual int getInt(unsigned int);
    virtual void setInt(int value, unsigned int index);
};

struct ModuleEnumeration {
    char padding[0x64];
    WorkManageModule* work;
};

struct ModuleAccesser {
    char padding[0xD8];
    ModuleEnumeration* enumeration;
};

struct Fighter {
    char padding[0x60];
    ModuleAccesser* accesser;
};

extern "C" void fn_113_A008(Fighter* fighter) {
    fighter->accesser->enumeration->work->setInt(-1, 0x10000041);
    fighter->accesser->enumeration->work->setInt(-1, 0x10000040);
}
