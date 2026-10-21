#include <types.h>
#pragma force_active on

class ItemBase {
public:
    virtual void vf00() = 0;
    virtual void vf01() = 0;
    virtual void vf02() = 0;
    virtual void vf03() = 0;
    virtual void vf04() = 0;
    virtual void vf05() = 0;
    virtual void vf06() = 0;
    virtual void vf07() = 0;
    virtual void vf08() = 0;
    virtual void vf09() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
};

class Item : public ItemBase {
public:
    virtual void process(int) = 0;
    char pad[0xE0];
    int next;
};

class MgrBase {
public:
    virtual void vf00() = 0;
    virtual void vf01() = 0;
    virtual void vf02() = 0;
    virtual void vf03() = 0;
    virtual void vf04() = 0;
    virtual void vf05() = 0;
    virtual void vf06() = 0;
    virtual void vf07() = 0;
    virtual void vf08() = 0;
    virtual void vf09() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
};

class MenuMgr : public MgrBase {
public:
    virtual void finish(Item*) = 0;
};

extern "C" void fn_18_85C4(void* param) {
    char* mgr = (char*)param;
    Item* it = *(Item**)(*(char**)(mgr + 0x650) + 0x14);
    int n;
    while (n = it->next) {
        if (n == 0) continue;
        it->process(n - 1);
    }
    MenuMgr* m = *(MenuMgr**)(mgr + 0x654);
    Item* first = *(Item**)(*(char**)(mgr + 0x650) + 0x14);
    m->finish(first);
}
