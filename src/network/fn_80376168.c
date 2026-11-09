#pragma force_active on
typedef struct { unsigned char pad44[0x44]; int unk44; } Header;
typedef struct { int offset; int size; unsigned short value; unsigned short pad; int unkC; } Entry;
typedef struct {
    unsigned char pad8[8]; Header *header; int unkC; int unk10; int unk14;
    unsigned char pad18[0x38]; unsigned char *buffer; unsigned char pad54[0xC];
    int entries; unsigned char pad64[2]; unsigned short unk66;
    unsigned char pad68[0x20]; int unk88; int unk8C;
} State;
extern int fn_8035A590(int);
extern Entry *fn_8035A598(int, int);
extern int fn_80373AA0(void *, int, int, int);
extern int fn_80373C54(void *, int);
extern int fn_8037442C(void *, void *, int);
extern void fn_80374778(void *);
int fn_80376168(State *self, unsigned char *data, int type, int arg3)
{
    int low, high, field, var_r3, count, i, offset;
    Entry *entry;
    unsigned short value;
    int var_r0;
    unsigned char *buffer;
    low = (data[0] << 8) | data[1];
    if (type == 2) {
        high = low;
    } else if (type == 4) {
        high = (data[2] << 8) | data[3];
    } else {
        field = self->unkC;
        if (field < 5) {
            if (self->unk10 != 0) {
                fn_80374778(self);
                if (fn_80373AA0(self, 7, 0, 0) == 0) {
                    var_r3 = 0;
                    goto out;
                }
            } else {
                if (field == 4) self->unk14 = 1;
                fn_80374778(self);
            }
        } else if (field != 7) {
            fn_80374778(self);
            if (fn_80373C54(self, 2) == 0) {
                var_r3 = 0;
                goto out;
            }
        }
        var_r3 = 1;
out:
        return var_r3 != 0;
    }
    count = fn_8035A590(self->entries);
    i = 0;
    while (i < count) {
        entry = fn_8035A598(self->entries, i);
        if ((short)(entry->value - low) >= 0 && (short)(entry->value - high) <= 0) {
            value = self->unk66;
            offset = self->header->unk44 + entry->offset + 5;
            buffer = self->buffer;
            buffer[offset++] = (unsigned char)((value >> 8) & 0xff);
            buffer[offset] = (unsigned char)value;
            if (fn_8037442C(self, self->buffer + entry->offset, entry->size) == 0) {
                var_r0 = 0;
            } else {
                entry->unkC = self->unk88;
                if (*(signed char *)(self->buffer + entry->offset + self->header->unk44 + 2) == 2) {
                    self->unk8C = self->unk88;
                }
                var_r0 = 1;
            }
            if (var_r0 == 0) return 0;
        }
        i++;
    }
    return 1;
}