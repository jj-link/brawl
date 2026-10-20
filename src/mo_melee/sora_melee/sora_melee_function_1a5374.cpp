#pragma force_active on
typedef unsigned int u32;

struct FieldHolder {
    char pad[8];
    u32 hi : 12;
    u32 f : 6;
    u32 lo : 14;
};

extern "C" {
void fn_27_1A5374(FieldHolder* p, u32 v) {
    p->f = v;
}
}
