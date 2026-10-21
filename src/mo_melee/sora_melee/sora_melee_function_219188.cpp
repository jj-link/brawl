#pragma force_active on
struct Pool {
    unsigned char records[0x1900];
    unsigned char bits[8];
    int limit;
    int count;
    int index;
};

extern "C" void* fn_27_219188(Pool* self) {
    if (self->count < self->limit) {
        int index = self->index;
        for (; index < 8; ++index) {
            if (self->bits[index] != 0) {
                for (int bit = 0; bit < 8; ++bit) {
                    if ((1 << bit) & self->bits[index]) {
                        self->bits[index] &= ~(1 << bit);
                        int offset = (index * 8 + bit) * 100;
                        self->count++;
                        return self->records + offset;
                    }
                }
            }
            self->index++;
        }
    }
    return 0;
}
