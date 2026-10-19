#pragma force_active on
struct Resource {
    int id;
    bool flag;
};

class Effect {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void set(int, const Resource&, int);
};

class Motion {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void set(int, bool);
};

struct Modules {
    char unused[0x3C];
    Motion* motion;
    char unused40[0x14];
    Effect* effect;
};

struct Fighter {
    char unused[0xD8];
    Modules* modules;
};

extern "C" void fn_95_FCC0(void*, Fighter* fighter, int kind) {
    switch (kind) {
    case 0x39: {
        Resource resource;
        resource.id = 0x452;
        resource.flag = false;
        fighter->modules->effect->set(0, resource, 0);
        break;
    }
    default:
        fighter->modules->motion->set(0, false);
        break;
    }
}
