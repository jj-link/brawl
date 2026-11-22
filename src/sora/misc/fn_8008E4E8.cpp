#pragma force_active on

extern const float lbl_805A1CA8;

struct Entry {
    char pad0[0xb0];
    float value;
    char padb4[0xec];
    int id;
    char pad1a4[0x20];
    unsigned char flag;
    char pad1c5[0x2b];
    int kind;
    char pad1f4[4];
    int active;
};

struct Context {
    Entry** entries;
    int count;
    char pad8[5];
    unsigned char enabled;
    char pade[0x32];
    unsigned char state;
    char pad41;
    unsigned char limit;
    unsigned char tail;
    char pad44[0xc];
    float value;
    char pad54[3];
    unsigned char mode;
    char pad58[4];
    unsigned char flag5c;
    char pad5d[8];
    unsigned char flag65;
};

struct Owner {
    Context* current;
    Context* other;
};

extern "C" int fn_8008E89C(Owner*, Context*, int, int, int*, int*);

extern "C" int fn_8008E4E8(Owner* self, int* out, int* arg) {
    Context* c = self->current;
    int n = 0;

    if (!c->enabled) return 0;

    int state = c->state;
    if (state == 0) return 0;
    if (state == 2) return 0;

    int count = c->count;
    if (count == 9 && c->entries[7]->kind == 0x67) return 0;
    if (count == 11 && c->entries[10]->kind == 0x69) return 0;
    if (count == 9 && c->entries[8]->kind == 0x65) return 0;

    int mode = c->mode;
    if (mode != 5) {
        if (c->limit > count) return 0;

        int offset;
        int i;
        int extra;
        if (state != 1 || mode != 0) goto normal;
        {
            float value = c->value;
            if (lbl_805A1CA8 == value) goto normal;
        }
        extra = 2;
        goto done;
    normal:
        extra = 1;
    done:
        i = 0;
        offset = 0;

        for (; i < self->current->count - self->current->tail - extra;
             offset += 4, i++) {
            Context* p = self->current;
            out[n++] = i < p->count
                ? (*(Entry**)((char*)p->entries + offset))->id
                : (*(Entry**)((char*)p->entries + (p->count - 1) * 4))->id;
            if (self->current->flag65) {
                int copy = *arg;
                n = fn_8008E89C(self, self->current, i, n, out, &copy);
            }
        }

        extra = i * 4;
        for (; i < self->current->count; extra += 4, i++) {
            Context* p = self->current;
            Entry* e = *(Entry**)((char*)p->entries + extra);
            if (e->flag) {
                out[n++] = i < p->count
                    ? e->id
                    : (*(Entry**)((char*)p->entries + (p->count - 1) * 4))->id;
                if (self->current->flag65) {
                    int copy = *arg;
                    n = fn_8008E89C(self, self->current, i, n, out, &copy);
                }
            }
        }
        return n;
    }

    for (int i = 0; i < self->other->count; i++) {
        Entry* e = self->other->entries[i];
        int skip = 1;

        if (e->active && lbl_805A1CA8 == e->value) {
            skip = 0;
            out[n++] = i < self->other->count
                ? e->id
                : (*(Entry**)((char*)self->other->entries + (self->other->count - 1) * 4))->id;
        }

        if (skip && self->other->flag5c && i != 0 &&
            self->other->entries[i - 1]->flag) {
            skip = 0;
            out[n++] = i < self->other->count
                ? self->other->entries[i]->id
                : (*(Entry**)((char*)self->other->entries + (self->other->count - 1) * 4))->id;
        }

        if (!skip && self->current->flag65) {
            int copy = *arg;
            n = fn_8008E89C(
                self, self->current, self->other->count - 1 - i,
                n, out, &copy);
        }
    }

    return n;
}
