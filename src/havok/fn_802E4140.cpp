#pragma force_active on

struct Root;

struct Context {
    char pad[0x10];
    Root* root;
};

class Entry {
public:
    virtual void f0();
    virtual void f1();
    virtual void update(Context*);
};

struct Root {
    char pad[0x1b4];
    Entry** entries;
    int count;

    void compact() {
        for (int i = count - 1; i >= 0; --i) {
            if (!entries[i]) {
                erase(i);
            }
        }
    }

    void erase(int index) {
        --count;
        for (; index < count; ++index) {
            entries[index] = entries[index + 1];
        }
    }
};

extern "C" void fn_802E4140(Root* self, Context* ctx) {
    ctx->root = self;
    for (int i = self->count - 1; i >= 0; --i) {
        Entry* entry = self->entries[i];
        if (entry) {
            entry->update(ctx);
        }
    }
    self->compact();
}
