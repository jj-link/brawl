#pragma force_active on

typedef unsigned char u8;

struct gfSceneManager {
    /* 0x000 */ char pad0[0x290];
    /* 0x290 */ struct Entry {
        /* 0x00 */ const char* name;
        /* 0x04 */ int unk;
        /* 0x08 */ u8 flag;
        /* 0x09 */ u8 flag2;
    } entries[11];
};

extern "C" int setLoadModuleName__14gfSceneManagerFv(gfSceneManager* self, const char* name, int unk, u8 flag, unsigned int kind) {
    for (int i = 0; i < 11; i++) {
        if (self->entries[i].name == 0) {
            self->entries[i].name = name;
            self->entries[i].unk = unk;
            self->entries[i].flag = flag;
            if (kind == 1) {
                self->entries[i].flag2 = 1;
            } else {
                self->entries[i].flag2 = 2;
            }
            return i;
        }
    }
    return -1;
}
