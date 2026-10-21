#include <types.h>
#pragma force_active on

class BaseItem;

class ItList {
public:
    virtual void f2();
    virtual BaseItem** getAt(s32 idx);
    virtual void f4();
    virtual s32 size();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void removeAt(s32 idx);
};

class itManager {
public:
    char pad0[0x6D8];
    ItList m_list;

    void removeItem(BaseItem* arg0);
};

extern "C" void fn_27_2A7970(itManager* self, BaseItem* item, s32 a, s32 b);

void itManager::removeItem(BaseItem* arg0) {
    if (arg0 != 0) {
        for (s32 i = 0; i < m_list.size(); i++) {
            if (*m_list.getAt(i) == arg0) {
                m_list.removeAt(i);
                fn_27_2A7970(this, arg0, 0, 1);
                return;
            }
        }
    }
}
