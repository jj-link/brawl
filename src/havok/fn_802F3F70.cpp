#pragma force_active on

class Entry {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
};

struct Main {
    char pad[0xf0];
    Entry** entries;
    int count;

    void cleanup() {
        for (int i = count - 1; i >= 0; --i) {
            if (!entries[i]) remove(i);
        }
    }

    void remove(int index) {
        --count;
        for (int j = index; j < count; ++j) {
            entries[j] = entries[j + 1];
        }
    }
};

extern "C" void fn_802F3F70(Main* self, int arg) {
    for (int i = self->count - 1; i >= 0; --i) {
        Entry* entry = self->entries[i];
        if (entry) entry->f2(arg);
    }
    self->cleanup();
}
