#pragma force_active on
struct Flags {
    unsigned int pad : 9;
    unsigned int flag : 1;
    unsigned int rest : 22;
};

struct Obj {
    char pad[8];
    Flags flags;
};

extern "C" unsigned int fn_73_9F5C(Obj* obj) {
    return obj->flags.flag;
}
