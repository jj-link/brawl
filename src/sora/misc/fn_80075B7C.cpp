#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual int slot9();
};

struct Entry {
    Object* object;
    int id;
    int unk8;
    u32 handle;
    char pad[12];
    u16 count;
    u16 unk1E;

    bool active() const {
        return handle != (u32)-1 && count != 0;
    }

    bool present() const {
        if (active())
            return true;
        return object != 0;
    }
};

struct System {
    char pad[0x2D4];
    Entry entries[32];
    char pad6D4[0x19];
    u8 enabled;

    u32 index(int id) {
        if (id == -1)
            return -1;

        bool valid = false;
        u32 slot = (u8)id;
        Entry* entry = &entries[slot];

        if (entry->id == id) {
            if (entry->present())
                valid = true;
        }

        return valid ? slot : (u32)-1;
    }
};

extern "C" bool fn_80075B7C(System* self, int id) {
    u32 slot = self->index(id);
    bool result;

    if (!self->enabled) {
        result = true;
    } else if (slot == (u32)-1) {
        result = true;
    } else {
        result = false;
        Object* object = self->entries[slot].object;
        if (object != 0 && object->slot9() != 0) {
            result = true;
        }
    }

    return result;
}
