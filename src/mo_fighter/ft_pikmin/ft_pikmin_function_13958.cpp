#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
extern u8 lbl_113_data_72C8[0x90];

struct FtStateRec {
    u8* base;
    u8* cursor;
    u32 count;
    u32 pad[21];
};

void fn_113_13958(FtStateRec* self);
}

extern "C" void fn_113_13958(FtStateRec* self) {
    u8* p;
    self->base = lbl_113_data_72C8;
    self->cursor = lbl_113_data_72C8 + 0x48;
    self->count = self->count & 0xFFFF;
    p = (u8*)self + 0xc;
    do {
        p += 8;
    } while (p < (u8*)self + 0x5c);
}
