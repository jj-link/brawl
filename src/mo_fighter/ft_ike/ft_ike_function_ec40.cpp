#pragma force_active on
class WorkModule {
public:
    virtual void entry08();
    virtual void entry0C();
    virtual void entry10();
    virtual void entry14();
    virtual int getInt(unsigned int);
};

class SoundModule {
public:
    virtual void entry08();
    virtual void entry0C();
    virtual void entry10();
    virtual void entry14();
    virtual void entry18();
    virtual void entry1C();
    virtual void entry20();
    virtual void entry24();
    virtual void entry28();
    virtual void entry2C();
    virtual void entry30();
    virtual void entry34();
    virtual void entry38();
    virtual void entry3C();
    virtual void entry40();
    virtual void entry44();
    virtual void entry48();
    virtual void entry4C();
    virtual void entry50();
    virtual void entry54();
    virtual void stopSE(int, int);
};

struct ModuleAccesser {
    unsigned char padding0[0x50];
    SoundModule* sound;
    unsigned char padding1[0x10];
    WorkModule* work;
};

struct Fighter {
    unsigned char padding[0xD8];
    ModuleAccesser* modules;
};

extern "C" void fn_119_EC40(void*, Fighter* fighter, int status)
{
    switch (status) {
    case 0x11A:
        return;
    }

    int handle = fighter->modules->work->getInt(0x20000004);
    if (handle >= 0) {
        fighter->modules->sound->stopSE(handle, 0);
    }
}
