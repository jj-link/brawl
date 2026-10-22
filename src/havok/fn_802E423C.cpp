#pragma force_active on
struct Owner;
struct Context {
    char pad[8];
    Owner* owner;
};
class Entry {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(Context*);
};
struct Owner {
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
extern "C" void fn_802E423C(Owner* self, Context* context) {
    context->owner = self;
    for (int i = self->count - 1; i >= 0; --i) {
        Entry* entry = self->entries[i];
        if (entry)
            entry->f3(context);
    }
    self->compact();
}
