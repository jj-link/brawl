#include <em/enemy.h>
#pragma force_active on

struct Fake {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual float getScore();
};

extern "C" float fn_41_C36C(Enemy* em) {
    return reinterpret_cast<Fake*>(em)->getScore();
}
