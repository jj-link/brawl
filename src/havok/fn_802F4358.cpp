#pragma force_active on

struct Context {
    int pad[2];
    int value;
};

class Item {
public:
    virtual void v0();
    virtual void v1(Context*);
};

struct Owner {
    char pad[0x15c];
    Item** items;
    int count;

    void cleanup() {
        for (int i = count - 1; i >= 0; --i) {
            if (items[i] == 0) {
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

extern "C" void fn_802F4358(Owner* self, Context* context) {
    context->value = 0;
    for (int i = self->count - 1; i >= 0; --i) {
        Item* item = self->items[i];
        if (item != 0)
            item->v1(context);
    }
    self->cleanup();
}
