#pragma force_active on
#pragma force_active off

struct Container;

struct Item {
    virtual void unused0() = 0;
    virtual void onInsert(unsigned int id, int data, Container* c);
    unsigned int field4;
};

struct Container {
    char pad[0xdc];
    Item** array;
    unsigned int size;
    unsigned int count;
};

extern "C" int fn_801ABE70(Container* self, unsigned int pos, Item* item) {
    unsigned int count = self->count;
    if (pos <= count && count < self->size && item != 0) {
        if (item->field4 == 0) {
            for (unsigned int i = count; i > pos; i--) {
                self->array[i] = self->array[i - 1];
            }
            self->array[pos] = item;
            item->onInsert(0x10002, 0, self);
            self->count++;
            return 1;
        }
    }
    return 0;
}
