#pragma force_active on

class Item {
public:
    virtual void f0();
    virtual void update(int);
};

struct Manager {
    char pad[0xF0];
    Item** items;
    int count;

    void compact() {
        for (int i = count - 1; i >= 0; --i) {
            if (!items[i]) {
                erase(i);
            }
        }
    }

    void erase(int index) {
        --count;
        for (int j = index; j < count; ++j) {
            items[j] = items[j + 1];
        }
    }
};

extern "C" void fn_802F3E78(Manager* self, int arg) {
    for (int i = self->count - 1; i >= 0; --i) {
        Item* item = self->items[i];
        if (item) {
            item->update(arg);
        }
    }
    self->compact();
}
