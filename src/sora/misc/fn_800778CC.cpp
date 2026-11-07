#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
};
struct Entry {
    Object_vptr_0* object;
    int id;
    int unk8;
    u32 handle;
    char pad[12];
    u16 count;
    u16 unk1E;
    bool active() const { return handle != (u32)-1 && count != 0; }
    bool present() const {
        if (active()) return true;
        return object != 0;
    }
};
struct System {
    char pad[0x2D4];
    Entry entries[32];
    u32 index(int id) {
        if (id == -1) return -1;
        bool valid = false;
        u32 slot = (u8)id;
        Entry* entry = &entries[slot];
        if (entry->id == id) {
            if (entry->present()) valid = true;
        }
        return valid ? slot : (u32)-1;
    }
};
extern "C" void fn_800778CC(System* self, int id) {
    u32 slot = self->index(id);
    if (slot == (u32)-1) return;
    Object_vptr_0* object = self->entries[slot].object;
    if (object) object->slot13();
}