#pragma force_active on
typedef unsigned char u8;

struct FamicomInfo {
    u8 pad[0x28];
    u8 count;
};

struct FamicomEntry {
    u8 pad[0x24];
    u8 state;
    u8 tail[3];
};

struct Famicom {
    u8 pad0[0x9C];
    FamicomInfo* info;
    u8 pad1[0x388];
    FamicomEntry* entries;
};

extern "C" u8 fn_68_1E68(Famicom* self) {
    if (self->info == 0)
        return 0;

    u8 count = 0;
    u8 i = 0;
    u8 length = self->info->count;

    for (; i != length; ++i) {
        if (self->entries[i].state != 13)
            ++count;
    }

    return count;
}
