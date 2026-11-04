#include <so/so_module_accesser.h>
#pragma force_active on
struct Article {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual void set(bool, int, bool);
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15();
    virtual void clear(int, bool);
    virtual void v17();
    virtual unsigned exists(int);
    virtual void v19(); virtual void v20();
    virtual int count(int);
};
struct Modules {
    char pad[0x64];
    soWorkManageModule* work;
    char pad2[0x1c];
    Article* article;
};
struct Accesser { char pad[0xd8]; Modules* modules; };
extern "C" void fn_116_DD48(void*, Accesser* a, int kind) {
    unsigned flag = 0;
    if (a->modules->work->isFlag(0x22000012) == 1) {
        if (a->modules->article->exists(1) == 1) {
            switch (kind) {
            case 0x43: case 0x44: case 0x45: case 0x46:
            case 0x56: case 0x5c: case 0x6e: case 0x70:
            case 0x89: case 0x8a:
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1 && a->modules->article->count(1) < 2) {
        a->modules->work->onFlag(0x22000013);
        a->modules->article->set(true, 0, true);
    } else {
        a->modules->article->clear(1, false);
    }
}