#include <types.h>
#pragma force_active on

extern "C" {
void exit__6gfTaskFv(void*);
void setBan__10gfHomeMenuFUlUl(void*, u32, u32);
extern void* g_gfHomeMenu;

class Item;

class Base {
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
    virtual void process(int) = 0;
    virtual void finish(Item* ) = 0;
};

class Item : public Base {
public:
    char pad[0xE0];
    int next;
};

struct Task {
    char pad[0x100];
    u8 flag;
    char pad101[3];
    int state;
};

struct Menu {
    char pad[0x94];
    Item* items;
    int unk98;
    int result;
    char pada0[0x45c - 0xa0];
    Task* task;
};

int fn_16_6B84(Menu* self) {
    Task* task = self->task;
    int status;
    if (task->state != 3) {
        status = 0;
    } else {
        status = 2;
        if (task->flag) {
            status = 1;
        }
        exit__6gfTaskFv(task);
        self->task = 0;
    }

    if (status == 0) {
        return self->result;
    }

    setBan__10gfHomeMenuFUlUl(g_gfHomeMenu, 0, 3);

    Item* it = self->items;
    int n;
    while ((n = it->next) != 0) {
        if (n != 0) {
            it->process(n - 1);
        }
    }
    Base* h = *(Base**)((char*)self + 0xa8);
    h->finish(self->items);
    return 2;
}

}