#pragma force_active on
typedef unsigned char u8;
typedef unsigned long long u64;

struct S {
    u8 pad[0x20];
    u64 v;
};

extern "C" u64 fn_27_206D74(S* p) {
    return p->v;
}
