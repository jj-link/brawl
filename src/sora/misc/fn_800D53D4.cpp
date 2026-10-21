#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

extern "C" int fn_800C8524();
extern "C" u8 fn_800C8548();
extern "C" u8 fn_800C851C();
extern "C" void netReport__FPCce(const char*, ...);
extern "C" void fn_80145B98(int, int);

extern char lbl_80458C74[];
extern char lbl_80458CA0[];
extern int lbl_805A03A8;

struct Entry {
    char pad0[0x68];
    u8 status[4];
    char pad1[0xC];
    u8 flag : 1;
    u8 rest : 7;
    char pad2[0x19F];
};

struct Parent {
    char pad[0x70];
    Entry entries[5];
    char pad2[0x4E4];
    int state;
};

extern "C" void fn_800D53D4(Parent* self, u32 arg) {
    if ((self->state >> 24) == 4) {
        if (fn_800C8524() != 0) {
            netReport__FPCce(lbl_80458C74);
            if (arg < 4) {
                u8 index = fn_800C8548();
                Entry* entry;
                if (index == 0xFF) {
                    u8 local = fn_800C851C();
                    if (local == 0xFF)
                        local = 4;
                    entry = &self->entries[local];
                } else {
                    entry = &self->entries[index];
                    if (!entry->flag) {
                        u8 local = fn_800C851C();
                        if (local == 0xFF)
                            local = 4;
                        entry = &self->entries[local];
                    }
                }
                entry->status[arg] = 3;
            }
        } else {
            netReport__FPCce(lbl_80458CA0);
        }
        fn_80145B98(lbl_805A03A8, arg);
    }
}
