#pragma force_active on
typedef unsigned int u32;

struct A7CCResult {
    u32 x;
    u32 y;
    u32 z;
};

struct SonicHolder {
    u32 pad;
    A7CCResult value;
};

extern "C" void fn_123_A6A0(A7CCResult* result, SonicHolder* destination, const A7CCResult* source);

extern "C" A7CCResult* fn_123_A64C(SonicHolder* self, const A7CCResult* source) {
    A7CCResult result;
    fn_123_A6A0(&result, self, source);
    self->value = result;
    return &self->value;
}
