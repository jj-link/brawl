#pragma force_active on

struct Context {
    char pad[0x10];
    int value;
};

class Entry {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2(Context*);
};

struct Manager {
    char pad[0x15c];
    Entry** entries;
    int count;

    void cleanup() {
        for (int i = count - 1; i >= 0; --i) {
            if (entries[i] == 0) {
                remove(i);
            }
        }
    }

    void remove(int i) {
        --count;
        for (int j = i; j < count; ++j) {
            entries[j] = entries[j + 1];
        }
    }
};

extern "C" void fn_802F4458(Manager* self, Context* context) {
    context->value = 0;
    for (int i = self->count - 1; i >= 0; --i) {
        Entry* entry = self->entries[i];
        if (entry != 0) {
            entry->f2(context);
        }
    }
    self->cleanup();
}
