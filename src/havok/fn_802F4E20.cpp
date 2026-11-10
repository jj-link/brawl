#pragma force_active on
struct Owner;
class Entry {
public:
    virtual void f0();
    virtual void f1(int, int);
};
struct Owner {
    char pad[0x144];
    Entry** entries;
    int count;
    void remove(int index) {
        --count;
        for (int j = index; j < count; ++j) {
            entries[j] = entries[j + 1];
        }
    }
    void compact() {
        for (int i = count - 1; i >= 0; --i) {
            if (entries[i] == 0) {
                remove(i);
            }
        }
    }
};
extern "C" void fn_802F4E20(Owner* self, int arg1, int arg2) {
    for (int i = self->count - 1; i >= 0; --i) {
        Entry* entry = self->entries[i];
        if (entry) {
            entry->f1(arg1, arg2);
        }
    }
    self->compact();
}
