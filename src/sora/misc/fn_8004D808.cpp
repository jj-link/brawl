#pragma force_active on

extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" void fn_8006BCA8(char*, const void*);
extern "C" int strcmp(const char*, const char*);

struct NameSlot {
    unsigned char pad0[0xE0];
    unsigned short used;
    unsigned char raw[10];
    unsigned char pad1[0x38];
};

struct RawName {
    unsigned short chars[6];
};

struct Manager {
    unsigned char pad[0x28];
    NameSlot* slots;
};

static inline int getName(NameSlot* slot, void* out) {
    if (slot->used == 0)
        return 0;
    memcpy(out, &slot->used, 12);
    return 1;
}

extern "C" int fn_8004D808(Manager* mgr, const char* name) {
    int count = 0;
    int i;
    NameSlot* p = mgr->slots;
    for (i = 0; i < 120; ++p, ++i) {
        if (p->used)
            ++count;
    }

    struct {
        RawName raw;
        char buf[32];
    } work;

    int off;
    int index;
    index = 0;
    off = 0;
    while (index < count) {
        NameSlot* slot = (NameSlot*)((char*)mgr->slots + off);
        if (getName(slot, &work.raw))
            fn_8006BCA8(work.buf, &work.raw);
        if (strcmp(name, work.buf) == 0)
            return index;
        off += 0x124;
        ++index;
    }
    return -1;
}
