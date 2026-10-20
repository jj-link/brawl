#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;

struct Input {
    u8 kind;
    u8 pad;
    u16 index;
};

struct Object {
    u8 pad0[0x2300];
    u8 kind;
    u8 pad1[7];
    u64 value;
    u8 pad2[0x71C];
    void* context;
};

extern "C" u64 fn_800344A0(void*, u16);

extern "C" void fn_14_ED0(Object* self, const Input* input) {
    if (input->kind != 0xFF) {
        self->kind = input->kind;
    } else {
        self->kind = 0xFF;
        self->value = fn_800344A0(self->context, input->index);
    }
}
