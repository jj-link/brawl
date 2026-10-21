#pragma force_active on

class Entry {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
};

struct Object {
    char pad[0xE4];
    Entry** entries;
    int count;

    void cleanup() {
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

extern "C" void fn_802F3C88(Object* self, int arg) {
    for (int i = self->count - 1; i >= 0; --i) {
        Entry* entry = self->entries[i];
        if (entry != 0) {
            entry->f2(arg);
        }
    }
    self->cleanup();
}
