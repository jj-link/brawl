#pragma force_active on

struct Block {
    float f;
    unsigned int w[18];
};

extern "C" void fn_8009D158(char* dst, const Block* src) {
    Block* d = (Block*)(dst + 0xC4);
    d->f = src->f;
    d->w[0] = src->w[0];
    d->w[1] = src->w[1];
    d->w[2] = src->w[2];
    d->w[3] = src->w[3];
    d->w[4] = src->w[4];
    d->w[5] = src->w[5];
    d->w[6] = src->w[6];
    d->w[7] = src->w[7];
    d->w[8] = src->w[8];
    d->w[9] = src->w[9];
    d->w[10] = src->w[10];
    d->w[11] = src->w[11];
    d->w[12] = src->w[12];
    d->w[13] = src->w[13];
    d->w[14] = src->w[14];
    d->w[15] = src->w[15];
    d->w[16] = src->w[16];
    d->w[17] = src->w[17];
}
