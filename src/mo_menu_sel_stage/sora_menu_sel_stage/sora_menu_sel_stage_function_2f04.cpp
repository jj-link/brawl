#pragma force_active on
struct Entry {
    unsigned char flags : 1;
    unsigned char rest : 7;
    unsigned char pad[3];
    int index;
    int value;
};

struct Object {
    unsigned char pad[0x28C];
    Entry entries[2000];
    int count;
};

extern "C" {
extern void* lbl_11_bss_8;

void fn_11_7DE4(void*);
int fn_11_7CE0(void*, int);
int fn_11_3004(const void*, const void*);
void fn_803F8ACC(void*, unsigned int, unsigned int,
                 int (*)(const void*, const void*));

void fn_11_2F04(Object* self) {
    int i;
    int count = 0;
    fn_11_7DE4(lbl_11_bss_8);

    Entry* entry = self->entries;
    for (i = 0; i < fn_11_7CE0(lbl_11_bss_8, 0) && count < 2000; ++i) {
        entry->flags = 0;
        ++count;
        entry->index = i;
        entry->value = -1;
        ++entry;
    }

    entry = &self->entries[count];
    for (i = 0; i < fn_11_7CE0(lbl_11_bss_8, 1) && count < 2000; ++i) {
        entry->flags = 1;
        ++count;
        entry->index = i;
        entry->value = -1;
        ++entry;
    }

    self->count = count;
    fn_803F8ACC(self->entries, count, sizeof(Entry), fn_11_3004);
}
}
