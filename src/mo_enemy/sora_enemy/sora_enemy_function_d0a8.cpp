#pragma force_active on
typedef unsigned int u32;

struct emManager;

struct FnCD80Ret {
    unsigned char active;
    unsigned char pad[0x13];
    u32 value;
};

extern "C" FnCD80Ret* fn_41_CD80(emManager*, u32);

extern "C" bool fn_41_D0A8(emManager* mgr, u32 id) {
    if (id == 0xFFFF) {
        return false;
    }

    FnCD80Ret* entry = fn_41_CD80(mgr, id);
    if (entry == 0) {
        return false;
    }

    if (entry->active == 0) {
        return false;
    }

    return entry->value != 0;
}
