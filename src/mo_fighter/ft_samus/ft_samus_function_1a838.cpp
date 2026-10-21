#pragma force_active on
class Work {
public:
    virtual void entry08();
    virtual void entry0c();
    virtual void entry10();
    virtual void entry14();
    virtual void entry18();
    virtual void entry1c();
    virtual void entry20();
    virtual void entry24();
    virtual void entry28();
    virtual void entry2c();
    virtual void entry30();
    virtual void entry34();
    virtual void entry38();
    virtual void entry3c();
    virtual void entry40();
    virtual void entry44();
    virtual void entry48();
    virtual int isFlag(int);
};

class Motion {
public:
    virtual void entry08();
    virtual void entry0c();
    virtual void entry10();
    virtual void entry14();
    virtual void entry18();
    virtual void entry1c();
    virtual void entry20();
    virtual void entry24();
    virtual void entry28();
    virtual void entry2c();
    virtual void entry30();
    virtual void entry34();
    virtual void entry38();
    virtual void entry3c();
    virtual void entry40();
    virtual void entry44();
    virtual void entry48();
    virtual void entry4c();
    virtual void entry50();
    virtual void entry54();
};

struct Modules {
    unsigned char pad0[0x0c];
    Motion* motion;
    unsigned char pad1[0x54];
    Work* work;

    Work* getWork() { return work; }
    Motion* getMotion() { return motion; }
};

struct Object {
    unsigned char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_94_1A838(void*, Object* object, int status) {
    if (status == 0x115 || (unsigned)(status - 0x11a) <= 5)
        return;

    Modules* modules = object->modules;
    Work* work = modules->getWork();
    Motion* motion = modules->getMotion();

    if (work->isFlag(0x22000017)) {
        motion->entry34();
        motion->entry54();
    }
}
