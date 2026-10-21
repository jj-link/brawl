#pragma force_active on

struct Item {
    unsigned char pad[0x71];
    unsigned char flags;
};

struct Entry {
    unsigned int unk0;
    Item* item;
};

struct Container {
    virtual void v0();
    virtual Entry* get(int);
    virtual void v2();
    virtual int size();
};

struct Owner {
    unsigned char pad[0x28];
    Container* container;
};

extern "C" void fn_80137F2C(Item*);
extern "C" void fn_801376B4(Item*);

extern "C" void fn_27_27630(Owner* self) {
    int count = self->container->size();
    for (int i = 0; i < count; i++) {
        if ((self->container->get(i)->item->flags >> 3) & 1) {
            fn_80137F2C(self->container->get(i)->item);
        }
        if ((self->container->get(i)->item->flags >> 7) & 1) {
            fn_801376B4(self->container->get(i)->item);
        }
    }
}
