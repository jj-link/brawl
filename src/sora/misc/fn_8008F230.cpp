#pragma force_active on

struct Entry {
    char pad[0x1c4];
    unsigned char flag;
};

struct Context {
    Entry** entries;
    int count;
    char pad0[0x38];
    unsigned char mode;
    char pad1[2];
    unsigned char limit;
    char pad2[0x11];
    unsigned char flagA;
    char pad3[7];
    unsigned char flagB;
};

extern "C" int fn_8008F230(Context* self) {
    int limit = self->limit;
    int r7 = 0;
    int i;

    for (i = 0; i < self->count; i++) {
        if (self->flagA == 0) {
            if (self->entries[i]->flag != 0) {
                r7 = 0;
            } else {
                r7++;
            }
        } else {
            if (self->entries[i]->flag != 0) {
                if (r7 == 1 && self->flagB != 0) {
                    return 0;
                }
                break;
            } else {
                r7++;
            }
        }
    }

    if (r7 < limit) {
        if (self->mode == 1 && self->flagA == 0 && r7 != 0) {
            return r7 - 1;
        }
        if (self->mode == 1 && self->flagA != 0 && r7 != 0) {
            return r7 - 1;
        }
        return r7;
    }
    if (self->mode == 1 && self->flagA == 0 && limit != 0) {
        return limit - 1;
    }
    if (self->mode == 1 && self->flagA != 0 && limit != 0) {
        return limit - 1;
    }
    return limit;
}
