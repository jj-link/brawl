#pragma force_active on
struct WorkModule {
    virtual bool isNull() const;
    virtual ~WorkModule();
    virtual void activate();
    virtual void setWork(unsigned int, void*);
    virtual int getInt(unsigned int);
    virtual void setInt(int value, unsigned int index);
};

struct Module {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void setInt(int value, unsigned int index);
};

struct Accesser {
    char pad0[0x14];
    Module* m14;
    char pad1[0x64 - 0x18];
    WorkModule* work;
};

struct Fighter {
    char pad[0xD8];
    Accesser* accesser;
};

extern "C" void fn_102_1500C(void* unused, Fighter* fighter) {
    fighter->accesser->m14->v3();
    fighter->accesser->work->setInt(-1, 0x20000003);
    fighter->accesser->work->setInt(-1, 0x20000005);
    fighter->accesser->work->setInt(-1, 0x20000006);
    fighter->accesser->work->setInt(-1, 0x20000007);
}
