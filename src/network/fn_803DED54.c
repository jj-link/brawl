#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct File {
    u8 pad[0x20];
    u8 shift;
} File;

typedef struct State {
    s32 value;
    File *file;
    u8 pad08[0x34];
    File *source;
    s32 field40;
    u32 field44;
    u16 field48;
    u16 mask;
    u8 buffer[0x20];
    u8 shift;
} State;

extern s32 fn_803DDF18(State *, s32);
extern s32 PFSEC_ReadData(File *, void *, u32, u16, u32, u32 *, s32);

s32 fn_803DED54(State *self, s32 value)
{
    u32 count;
    s32 result;
    s32 old;
    s32 error;
    s32 readResult;
    u8 shift;

    self->file = self->source;
    old = self->value;
    shift = self->file->shift - 5;
    self->value = value;
    self->shift = shift;
    self->mask = (1 << self->shift) - 1;
    self->field40 = -1;

    result = fn_803DDF18(self, 0);
    if (result != 0) {
        self->value = old;
        fn_803DDF18(self, 0);
    } else {
        if (self->field44 == 0xFFFFFFFFU) {
            error = 16;
        } else {
            readResult = PFSEC_ReadData(self->file, self->buffer,
                                       self->field44, self->field48,
                                       32, &count, 0);
            error = 17;
            if (count == 32)
                error = readResult;
        }
        result = error & ((-error | error) >> 31);
    }
    return result;
}
