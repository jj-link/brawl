#pragma force_active on

struct Manager;

struct Context {
    char pad[8];
    Manager* manager;
};

class Entry {
public:
    virtual void f0();
    virtual void f1(Context*);
};

struct Manager {
    char pad[0x1b4];
    Entry** entries;
    int count;

    void compact() {
        for (int i = count - 1; i >= 0; --i) {
            if (entries[i] == 0) {
                remove(i);
            }
        }
    }

    void remove(int index) {
        --count;
        for (int j = index; j < count; ++j) {
            entries[j] = entries[j + 1];
        }
    }
};

extern "C" void fn_802E4044(Manager* self, Context* context) {
    context->manager = self;
    for (int i = self->count - 1; i >= 0; --i) {
        Entry* entry = self->entries[i];
        if (entry != 0) {
            entry->f1(context);
        }
    }
    self->compact();
}
