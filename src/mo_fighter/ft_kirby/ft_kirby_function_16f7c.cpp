#pragma force_active on
extern float lbl_96_rodata_94;
struct Event {
    int kind;
    bool flag;
    float value;
    int unused;
    bool flag2;
};
class Class_CB50 {
public:
    virtual void fn_96_28D0();
    virtual void fn_96_23378();
    virtual void fn_96_23B90();
    virtual void fn_96_23B8C();
    virtual void fn_96_23B88();
    virtual void fn_96_23B84();
    virtual void fn_96_23B7C();
    virtual void fn_96_23BC4();
    virtual void fn_96_23BBC();
    virtual void fn_96_23BB4();
    virtual unsigned int fn_96_23BAC(int);
    virtual void fn_96_23BA4();
    virtual void fn_96_23B3C();
    virtual void fn_96_23B70();
    virtual void fn_96_23B64();
    virtual void fn_96_23B5C();
    virtual void fn_96_23B50(int, Event&, unsigned int);
};
class Class_CD28 {
public:
    virtual void fn_96_28D0();
    virtual void fn_96_2331C();
    virtual void fn_96_23D84();
    virtual void fn_96_23D7C();
    virtual void fn_96_23D74();
    virtual void fn_96_23D6C();
    virtual void fn_96_23D64();
    virtual void fn_96_23D5C();
    virtual void fn_96_23D54();
    virtual void fn_96_23D4C(int, bool);
    virtual void fn_96_23D44();
    virtual void fn_96_23D3C();
    virtual void fn_96_23D34();
    virtual void fn_96_23D2C();
    virtual void fn_96_23CDC();
    virtual void fn_96_23D24();
    virtual void fn_96_23D14();
};
struct Modules {
    char pad[0x3c];
    Class_CD28* catcher;
    char pad40[0x14];
    Class_CB50* link;
};
struct Accesser {
    char pad[0xd8];
    Modules* modules;
};
extern "C" void fn_96_16F7C(void*, Accesser* accesser, int status) {
    switch (status) {
    case 0x11b: case 0x11c: case 0x11d: case 0x11e: case 0x11f:
    case 0x120: case 0x121: case 0x122: case 0x123: case 0x124: case 0x125:
        return;
    case 0x127: case 0x128: {
        Event event;
        event.kind = 0x16;
        event.flag = false;
        event.value = lbl_96_rodata_94;
        event.flag2 = false;
        accesser->modules->link->fn_96_23B50(0, event, 0);
        break;
    }
    default:
        if (accesser->modules->link->fn_96_23BAC(0) == 1)
            accesser->modules->catcher->fn_96_23D4C(0, true);
        break;
    }
}