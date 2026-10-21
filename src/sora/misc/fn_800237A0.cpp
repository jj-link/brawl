#pragma force_active on

extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);

struct Item {
    char pad[0x17];
    unsigned char flags;
    unsigned int value;
};

struct List {
    unsigned short unused;
    unsigned short count;
    Item* items[1];
};

struct Manager {
    char pad[0x18];
    List* list;
};

struct Object {
    char pad0[8];
    Manager* first;
    Manager* second;
    char pad1[6];
    unsigned short state;
    char pad2[0x80];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
};

extern "C" void fn_800237A0(Object* self, int enabled) {
    self->enabled = enabled;
    self->state = 0;
    if (!self->enabled) {
        OSLockMutex(self->first);
        unsigned int count = self->first->list->count;
        for (unsigned int i = 0; i < count; ++i) {
            Item* item = self->first->list->items[i];
            if (((int)((item->value << 4) & 0xFF800000) >> 24) == 0)
                item->flags &= ~2;
        }
        OSUnlockMutex(self->first);

        OSLockMutex(self->second);
        count = self->second->list->count;
        for (unsigned int i = 0; i < count; ++i) {
            Item* item = self->second->list->items[i];
            if (((int)((item->value << 4) & 0xFF800000) >> 24) == 0)
                item->flags &= ~2;
        }
        OSUnlockMutex(self->second);
    }
}
