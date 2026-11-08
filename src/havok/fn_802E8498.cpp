#pragma force_active on
struct Owner;
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(Owner*);
};
struct Owner {
    char pad[0x64];
    Object_vptr_0** entries;
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
extern "C" void fn_802E8498(Owner* self) {
    for (int i = self->count - 1; i >= 0; --i) {
        Object_vptr_0* entry = self->entries[i];
        if (entry) {
            entry->slot2(self);
        }
    }
    self->compact();
}