#pragma force_active on

struct Context {
    char pad[0xc];
    int field;
};

class Entry {
public:
    virtual void update(Context*);
};

struct Manager {
    char pad[0x15c];
    Entry** entries;
    int count;

    void compact() {
        for (int i = count - 1; i >= 0; --i) {
            if (entries[i] == 0) {
                erase(i);
            }
        }
    }

    void erase(int index) {
        --count;
        for (int j = index; j < count; ++j) {
            entries[j] = entries[j + 1];
        }
    }
};

extern "C" void fn_802F4258(Manager* self, Context* context) {
    context->field = 0;
    for (int i = self->count - 1; i >= 0; --i) {
        Entry* entry = self->entries[i];
        if (entry != 0) {
            entry->update(context);
        }
    }
    self->compact();
}
