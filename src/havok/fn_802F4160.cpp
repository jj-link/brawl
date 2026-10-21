#pragma force_active on

class Entry {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
};

struct Manager {
    char pad[0xfc];
    Entry** entries;
    int count;

    void sweep() {
        for (int i = count - 1; i >= 0; --i) {
            if (entries[i] == 0)
                remove(i);
        }
    }

    void remove(int index) {
        --count;
        for (int j = index; j < count; ++j)
            entries[j] = entries[j + 1];
    }
};

extern "C" void fn_802F4160(Manager* self, int arg) {
    for (int i = self->count - 1; i >= 0; --i) {
        Entry* entry = self->entries[i];
        if (entry != 0)
            entry->f2(arg);
    }
    self->sweep();
}
