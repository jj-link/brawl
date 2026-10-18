#pragma force_active on
typedef unsigned int u32;

struct S8 {
    u32 hi;
    u32 lo;
};

struct Obj {
    u32 pad[2];
    S8 val;
};

extern "C" S8 fn_123_9564(Obj* o) {
    return o->val;
}
