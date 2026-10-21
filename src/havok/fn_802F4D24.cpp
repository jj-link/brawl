#pragma force_active on
struct Owner;
class Entry {
public:
    virtual void f0();
    virtual void f1(Owner*, int);
};
struct Owner {
    char pad[0x138];
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
extern "C" void fn_802F4D24(Owner* self, int arg) {
    for (int i = self->count - 1; i >= 0; --i) {
        Entry* entry = self->entries[i];
        if (entry) {
            entry->f1(self, arg);
        }
    }
    self->compact();
}
