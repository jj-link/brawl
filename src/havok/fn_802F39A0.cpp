#pragma force_active on

class Item {
public:
    virtual void f0();
    virtual void f1(int);
};

struct Root {
    char pad[0xD8];
    Item** items;
    int count;

    void cleanup() {
        for (int i = count - 1; i >= 0; --i) {
            if (!items[i]) {
                remove(i);
            }
        }
    }

    void remove(int i) {
        --count;
        for (int j = i; j < count; ++j) {
            items[j] = items[j + 1];
        }
    }
};

extern "C" void fn_802F39A0(Root* self, int arg) {
    for (int i = self->count - 1; i >= 0; --i) {
        Item* item = self->items[i];
        if (item) {
            item->f1(arg);
        }
    }
    self->cleanup();
}
