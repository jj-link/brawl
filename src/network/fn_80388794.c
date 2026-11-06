#pragma force_active on
#include <string.h>
#include <internal/strtoul.h>

typedef struct {
    char pad[0x18];
    void *map;
    int ping;
} Query;

typedef struct {
    void *key;
    char *value;
} Entry;

extern char lbl_8059FB94[5];
extern char lbl_804942B8[];
extern Entry *fn_8035B1C4(void *, const char **);

int fn_80388794(Query *obj, const char *name, int fallback)
{
    const char *key;
    Entry *entry;
    char *value;
    char *digits;
    int c;
    int invalid;
    int digit;

    if (obj == 0) {
        return fallback;
    }
    if (strcmp(name, lbl_8059FB94) == 0) {
        return obj->ping;
    }
    if (obj == 0) {
        value = 0;
    } else {
        key = name;
        entry = fn_8035B1C4(obj->map, &key);
        if (entry == 0) {
            value = 0;
        } else {
            value = entry->value;
        }
    }
    if (value == 0) {
        return fallback;
    }
    if (*value != '-') {
        digits = value;
    } else {
        digits = value + 1;
    }
    c = (unsigned char)*digits;
    invalid = c < 0 || c >= 256;
    if (invalid) {
        digit = 0;
    } else {
        digit = (*(unsigned short **)(*(char **)(lbl_804942B8 + 0x38) + 8))[c] & 8;
    }
    if (digit == 0) {
        return fallback;
    }
    return atoi(value);
}
