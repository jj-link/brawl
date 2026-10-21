#pragma force_active on
struct Work {
    unsigned char pad0[0xA2];
    unsigned short flags;
    unsigned char padA4[0x149 - 0xA4];
    unsigned char count;
    unsigned char pad14A[0x32C - 0x14A];
    unsigned char slots[24];
};

extern "C" void fn_27_1F290C(Work* self, int mode)
{
    if (mode == 0 && (self->flags & 0x100))
        return;

    int start = 0;
    int end = 24;
    switch (mode) {
    case 0:
        end = 8;
        break;
    case 1:
        start = 8;
        break;
    }

    for (; start < end; ++start) {
        if (start >= 0 && (unsigned int)start < 24 && self->slots[start] != 0) {
            self->slots[start] = 0;
            --self->count;
        }
    }
}
