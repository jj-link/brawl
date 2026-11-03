#pragma force_active on
struct Owner;
class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C(Owner*);
};
struct Owner {
    char pad[0x108];
    Class_8042B6D0** entries;
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
extern "C" void fn_802F4658(Owner* self) {
    for (int i = self->count - 1; i >= 0; --i) {
        Class_8042B6D0* entry = self->entries[i];
        if (entry) {
            entry->fn_8004781C(self);
        }
    }
    self->compact();
}