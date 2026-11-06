#include <types.h>
#pragma force_active on

class Class_7FC8 {
public:
    virtual int fn_104_7930();
    virtual void fn_104_12090();
    virtual void fn_104_12990();
    virtual Class_7FC8* fn_104_12988(int, bool, bool);
    virtual void fn_104_12980();
    virtual void fn_104_12978();
    virtual void fn_104_12970();
    virtual void fn_104_12968();
    virtual void fn_104_12960();
    virtual void fn_104_12958();
    virtual void fn_104_12950();
    virtual void fn_104_12948();
    virtual void fn_104_12940();
    virtual void fn_104_12938(Class_7FC8*);
    virtual void fn_104_128E8();
    virtual void fn_104_12930();
    virtual void fn_104_12920(int, int);
    virtual void fn_104_12910();
    virtual int fn_104_12900(int);
};

struct Modules {
    char pad0[0x84];
    Class_7FC8* obj84;
};

struct Fighter {
    char pad0[0xD8];
    Modules* modules;
};

extern "C" void fn_104_1E358(void*, Fighter* fighter, int kind) {
    Class_7FC8* obj = fighter->modules->obj84;
    if (kind == 0x80) {
        if (obj->fn_104_12900(2) == 0) {
            bool flag = false;
            Class_7FC8* sub = obj->fn_104_12988(2, flag, flag);
            if (sub->fn_104_7930() == 0) {
                obj->fn_104_12938(sub);
            }
        }
    } else if (kind == 0x11A) {
        return;
    } else if (kind == 0x81) {
        return;
    } else {
        obj->fn_104_12920(2, 0);
    }
}
