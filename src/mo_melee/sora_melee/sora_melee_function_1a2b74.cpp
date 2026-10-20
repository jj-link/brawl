#pragma force_active on
typedef unsigned int u32;

struct FieldHolder {
    u32 pad[2];
    u32 a : 2;
    u32 b : 2;
    u32 c : 28;
};

extern "C" {
void fn_27_1A2B74(FieldHolder* obj, u32 value) {
    obj->b = value;
}
}
