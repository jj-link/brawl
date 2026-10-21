#pragma force_active on

class Item {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void update(void*);
};

struct Container {
    char pad[0x15c];
    Item** items;
    int count;

    void cleanup() {
        for (int i = count - 1; i >= 0; --i) {
            if (!items[i]) {
                remove(i);
            }
        }
    }

    void remove(int index) {
        --count;
        for (int j = index; j < count; ++j) {
            items[j] = items[j + 1];
        }
    }
};

extern "C" void fn_802F4558(Container* self, void* arg) {
    *(int*)((char*)arg + 8) = 0;

    for (int i = self->count - 1; i >= 0; --i) {
        Item* item = self->items[i];
        if (item) {
            item->update(arg);
        }
    }

    self->cleanup();
}
