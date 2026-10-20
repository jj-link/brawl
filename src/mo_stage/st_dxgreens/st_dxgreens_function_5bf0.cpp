#pragma force_active on
struct UnkFlags {
    unsigned int pad : 12;
    unsigned int flag : 1;
    unsigned int rest : 19;
};

struct UnkObj {
    char pad[8];
    UnkFlags flags;
};

extern "C" unsigned int fn_79_5BF0(UnkObj* obj) {
    return obj->flags.flag;
}
