#include <types.h>
#pragma force_active on

struct Item {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual s32 method6();
};

struct List {
    virtual void v0();
    virtual Item** at(s32 i);
    virtual void v2();
    virtual s32 size();
};

struct Host {
    char pad[0x2C];
    List* m_list;
};

extern "C" s32 fn_27_940C8(Host* self, s32 arg1) {
    s32 result = 0;
    for (s32 i = 0; i < self->m_list->size(); i++) {
        if (*(self->m_list->at(i)) != NULL) {
            if ((*self->m_list->at(i))->method6() == arg1) {
                result++;
            }
        }
    }
    return result;
}
