#pragma force_active on

class Item {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
};

struct Main {
    char pad[0xD8];
    Item** items;
    int count;

    void compact() {
        for (int i = count - 1; i >= 0; --i) {
            if (!items[i]) {
                removeAt(i);
            }
        }
    }

    void removeAt(int index) {
        --count;
        for (int j = index; j < count; ++j) {
            items[j] = items[j + 1];
        }
    }
};

extern "C" void fn_802F3A98(Main* self, int arg) {
    for (int i = self->count - 1; i >= 0; --i) {
        Item* item = self->items[i];
        if (item) {
            item->f2(arg);
        }
    }
    self->compact();
}
