#pragma force_active on
struct KirbyInitializeObject;

struct ValueModule {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual int getValue();
};

struct TeamModule {
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
    virtual int getTeam();
};

struct Fighter {
    unsigned char pad[8];
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual TeamModule* getTeamModule();
};

struct Modules {
    Fighter* fighter;
    unsigned char pad[16];
    ValueModule* value;
};

struct Resource {
    unsigned char pad[0x28];
    int resource;
};

struct Input {
    unsigned char pad0[8];
    Resource* resource;
    unsigned char pad1[0xCC];
    Modules* modules;
};

extern "C" void fn_96_25CDC(KirbyInitializeObject*, int, int, int);

extern "C" int fn_96_B5A4(KirbyInitializeObject* object, Input* input) {
    int value;
    Modules* modules = input->modules;
    Fighter* fighter = modules->fighter;
    int resource = input->resource->resource;
    value = modules->value->getValue();
    int team = fighter->getTeamModule()->getTeam();
    fn_96_25CDC(object, resource, team, value);
    return 1;
}
