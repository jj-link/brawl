#pragma force_active on
struct StageObject {
    char pad[0x3C];

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
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual int test();
    virtual int kind();
};

struct LinkModule {
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
    virtual StageObject* get(int);
};

struct Modules {
    char pad[0x54];
    LinkModule* link;
};

struct Object {
    char pad[0xD8];
    Modules* modules;
};

extern "C" int getStatusKind__23soExternalValueAccesserFP11StageObject(StageObject*);

extern "C" int fn_27_189200(Object* self) {
    LinkModule* link = self->modules->link;
    StageObject* object = link->get(0);
    if (object == 0) return 0;
    if (object->test() != 0) return 0;

    int kind = object->kind();
    int status = getStatusKind__23soExternalValueAccesserFP11StageObject(object);

    switch (kind) {
    case 2:
        switch (status) {
        case 0x116:
        case 0x11A:
        case 0x11B:
            return 1;
        }
        break;
    case 41:
        switch (status) {
        case 0x116:
        case 0x11A:
        case 0x11B:
            return 1;
        }
        break;
    }
    return 0;
}
