#pragma force_active on
#include <types.h>

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
    virtual void fn_96_23BAC();
    virtual void fn_96_23BA4();
    virtual void fn_96_23B3C();
    virtual void fn_96_23B70();
    virtual void fn_96_23B64();
    virtual void fn_96_23B5C();
    virtual void fn_96_23B50();
    virtual bool fn_96_23B48(u32);
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
    virtual void fn_96_23D4C();
    virtual bool fn_96_23D44(int);
    virtual void fn_96_23D3C();
    virtual void fn_96_23D34();
    virtual void fn_96_23D2C();
    virtual void fn_96_23CDC();
    virtual void fn_96_23D24();
    virtual void fn_96_23D14(int, void*, u32);
    virtual bool fn_96_23D04(u32);
};

struct Modules {
    char pad0[0x54];
    Class_CD28* link;
    char pad1[0xC];
    Class_CB50* work;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

struct LocalEvent {
    int id;
    bool flag;
    LocalEvent() : id(0x456), flag(false) {}
};

extern "C" {

void fn_96_2D960(void*, void*);

void fn_96_2D7D4(void* arg0, Accesser* arg1, int arg2) {
    switch (arg2) {
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    case 1:
        if (arg1->modules->work->fn_96_23B48(0x22000003) == false) {
            fn_96_2D960(arg0, arg1);
            return;
        }
        return;
    default:
        if (arg1->modules->link->fn_96_23D44(6)) {
            LocalEvent event;
            arg1->modules->link->fn_96_23D14(6, &event, 0);
        }
        break;
    }
}

}