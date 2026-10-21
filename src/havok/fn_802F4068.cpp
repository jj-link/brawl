#pragma force_active on

class Entry {
public:
    virtual void f0();
    virtual void f1(int);
};

struct Container {
    char pad[0xFC];
    Entry** entries;
    int count;

    void compact() {
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

extern "C" void fn_802F4068(Container* self, int arg) {
    for (int i = self->count - 1; i >= 0; --i) {
        Entry* entry = self->entries[i];
        if (entry) {
            entry->f1(arg);
        }
    }
    self->compact();
}
