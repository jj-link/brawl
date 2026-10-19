#pragma force_active on
extern "C" {
struct FnTable {
    unsigned int count;
    char *items;
};

void *fn_41_CD5C(FnTable *t, unsigned int idx) {
    if (idx >= t->count) {
        return 0;
    }
    return t->items + idx * 0x18;
}
}
