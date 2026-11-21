#pragma force_active on
extern "C" unsigned int g_NtAIDBitmap;
extern "C" unsigned char lbl_8059E742;
extern "C" int lbl_805A03E8;

struct Entry {
    unsigned char pad[0x14];
    int w14;
    int w18;
    unsigned char data[0xE50 - 0x1C];
};

struct Object {
    unsigned char pad[0x44];
    Entry entries[4];
};

extern "C" Object* lbl_805A03A8;

static inline bool isPending(unsigned int aid) {
    Entry* e = &lbl_805A03A8->entries[aid];
    return e->w14 != e->w18;
}

static inline unsigned int findBusy() {
    unsigned int i;
    for (i = 0; i < 4; i++) {
        unsigned char a = i;
        if (i != lbl_8059E742 && (g_NtAIDBitmap & (1 << a)) && isPending(i))
            break;
    }
    return i;
}

extern "C" int fn_8014592C(void* self) {
    if (lbl_805A03E8 != 0)
        return 1;
    if (findBusy() != 4)
        return 0;
    if (*(int*)((char*)self + 0x18) != 0)
        return 0;
    if (*(unsigned char*)((char*)self + 0x34) != 0)
        return 0;
    if (*(int*)((char*)self + 0x1c) != 0)
        return 0;
    unsigned char flags = *(unsigned char*)((char*)self + 0x3e);
    if ((flags >> 5) & 1)
        return 0;
    if ((flags >> 3) & 1)
        return 0;
    if ((flags >> 2) & 1)
        return 0;
    if ((flags >> 6) & 1)
        return 0;
    return (unsigned int)__cntlzw((flags >> 7) & 1) >> 5;
}