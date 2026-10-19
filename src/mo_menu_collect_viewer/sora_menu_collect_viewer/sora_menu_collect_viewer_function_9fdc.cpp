#pragma force_active on
typedef unsigned long long u64;

struct Item {
    char padding[0x16];
    unsigned char enabled;
    char trailing;
};

struct Viewer {
    char padding[0x12c];
    Item items[64];
    int count;
    void* object;
    char padding2[0x2c];
    unsigned int field760;
    unsigned int field764;
    unsigned int field768;
};

extern "C" {
void fn_8014E640(void*);
void fn_8014E6A8(void*, unsigned int, unsigned int);
void fn_8014E6B4(void*, unsigned int);
u64 fn_8014D0D8(void*, int);
void fn_8014E680(void*, u64);
void fn_8014F490(void*, int, int);

void fn_6_9FDC(Viewer* self) {
    void* object = self->object;
    fn_8014E640(object);
    fn_8014E6A8(object, self->field760, self->field764);
    fn_8014E6B4(object, self->field768);

    for (int i = 0; i < self->count; ++i) {
        if (self->items[i].enabled) {
            fn_8014E680(object, fn_8014D0D8(object, i));
        }
    }

    fn_8014F490(object, 2, 0);
}
}
