#pragma force_active on

struct FnItem {
    int unk0;
    unsigned int unk4;
};

extern "C" {
extern void* g_GameGlobal;
void* fn_8004E5D8(void*, int);
int fn_2_1E6CC(FnItem*, FnItem*);
void fn_803F8ACC(void*, unsigned int, unsigned int,
                 int (*)(FnItem*, FnItem*));
}

extern "C" int fn_2_1E620(void* self, FnItem* entries,
                         unsigned int (*callback)(int)) {
    int i;
    FnItem* out = entries;
    int count = 0;
    for (i = 0; i < 0x23; ++i) {
        if (*(int*)((char*)fn_8004E5D8(g_GameGlobal, i) + 0x68) != 0) {
            out->unk0 = i;
            out->unk4 = callback(i);
            ++out;
            ++count;
        }
    }
    if (count >= 2) {
        fn_803F8ACC(entries, count, 8, fn_2_1E6CC);
    }
    return count;
}
