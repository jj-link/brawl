#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Entry {
    void* object;
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

extern "C" void fn_801C49C0(void**, Entry*);
extern "C" void fn_801C4730(void*, float);
extern "C" void fn_801C4AC8(void**);

extern "C" void fn_80076E30(System* self, int id, float value) {
    u32 slot = self->index(id);

    if (slot != (u32)-1 && self->enabled) {
        void* object;
        fn_801C49C0(&object, &self->entries[slot]);

        if (object)
            fn_801C4730(object, value);

        fn_801C4AC8(&object);
    }
}
