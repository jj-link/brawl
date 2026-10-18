#pragma force_active on
typedef unsigned char u8;

struct Work {
    u8 pad[0xa4];
    u8 f0 : 1;
    u8 flag : 1;
    u8 rest : 6;
};

extern "C" bool fn_114_157E8(const Work* self) {
    return self->flag;
}
