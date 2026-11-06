#pragma force_active on
extern int lbl_805A1170;
extern int fn_803A08EC(void *, int);
extern int fn_8039A69C(int, int, int *);

typedef struct {
    char pad0[0x14];
    unsigned int count;
    char pad18[0x2c];
    unsigned int flags1;
    unsigned int flags2;
    char pad4c[0x34];
    int entries[32];
} Data;

int fn_8039A53C(int *out, int flags) {
    int base = lbl_805A1170;
    Data *data;
    int result;
    unsigned int total = 0;
    unsigned int limit;
    Data *entry;
    unsigned int i;
    int index;
    int value;
    *out = 0;
    data = (Data *)(base + 0x400);
    result = fn_803A08EC(data, 0x100);
    if (result == -1 || result == -11 || result == -42) {
        *out = result - 0x1aa2c;
        return -1;
    }
    if (result != 0)
        return 0;
    if (flags & 1) {
        if ((data->flags1 & 3) == 3)
            return 0;
    } else if (flags & 2) {
        if ((data->flags2 & 15) == 15)
            return 0;
    }
    limit = 32;
    if (data->count < 32)
        limit = data->count;
    index = (int)(data->count + 31) % 32;
    for (i = 0; i < limit; i++) {
        entry = (Data *)((char *)data + index * 4);
        result = fn_8039A69C(entry->entries[0], flags, &value);
        if (result != 0) {
            total += value;
            if (total >= 60) {
                *out = entry->entries[0];
                return result;
            }
        }
        index--;
        if (index < 0)
            index = 31;
    }
    *out = 0;
    return 0;
}