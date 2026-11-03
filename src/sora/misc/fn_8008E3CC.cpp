#pragma force_active on
extern const float lbl_805A1CA8;
struct Entry { char pad[0x1a0]; int value; char pad2[0x20]; unsigned char flag; };
struct Context { Entry** entries; int count; char pad[5]; unsigned char enabled; char pad2[0x32]; unsigned char state; char pad3; unsigned char limit; unsigned char tail; char pad4[0xc]; float value; char pad5[3]; unsigned char flag; };
extern "C" int fn_8008E3CC(Context* self, int* out) {
    int* p;
    int n = 0;
    int i;
    if (self->enabled == 0) return 0;
    unsigned char state = self->state;
    if (state == 0) return 0;
    if (state == 2) return 0;
    if (self->limit > self->count) return 0;
    int extra;
    if (state == 1 && self->flag == 0 && lbl_805A1CA8 != self->value) extra = 2;
    else extra = 1;
    p = out;
    i = 0;
    for (; i < self->count - self->tail - extra; i++) {
        *p++ = self->entries[i]->value;
        n++;
    }
    p = out + n;
    for (; i < self->count; i++) {
        Entry* e = self->entries[i];
        if (e->flag) { *p++ = e->value; n++; }
    }
    return n;
}