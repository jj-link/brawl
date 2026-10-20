#pragma force_active on
typedef unsigned int u32;

struct FieldBits {
    u32 a : 5;
    u32 b : 5;
    u32 c : 22;
};

struct FieldHolder {
    char pad[8];
    FieldBits word;
};

extern "C" {
void fn_27_19DF9C(FieldHolder* p, u32 v) {
    p->word.b = v;
}
}
