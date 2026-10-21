#pragma force_active on

struct Manager;

struct Context {
    char pad[0xc];
    Manager* owner;
};

class Entry {
public:
    virtual void run(Context*);
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
        for (; index < count; ++index) {
            entries[index] = entries[index + 1];
        }
    }
};

extern "C" void fn_802E3F48(Manager* self, Context* context) {
    context->owner = self;
    for (int i = self->count - 1; i >= 0; --i) {
        Entry* entry = self->entries[i];
        if (entry) {
            entry->run(context);
        }
    }
    self->compact();
}
