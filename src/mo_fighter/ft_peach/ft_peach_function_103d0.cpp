#include <types.h>
#pragma force_active on

extern "C" {
void fn_103_10488(void* unused, void* fighter);

struct Ft103Query {
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
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual u32 query(u32 id);
};

void fn_103_103D0(void* self, void* fighter) {
    Ft103Query* obj = *(Ft103Query**)((char*)*(void**)((char*)fighter + 0xd8) + 0x64);
    if (obj->query(0x22000011) == 1) {
        fn_103_10488(self, fighter);
    }
}
}
