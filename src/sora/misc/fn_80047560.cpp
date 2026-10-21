#pragma force_active on
typedef unsigned int u32;

struct Data {
    char pad0[0x40];
    char values[0x24];
    u32 offset;
};

struct Obj {
    char pad0[0xE8];
    Data* data;
    void* buffer;
    u32 fieldF0;
    char padF4[0x10];
    u32 flags;
    u32 field108;
    int count;
};

extern "C" {
u32 fn_8015D804(void*);
void DCFlushRange(void*, u32);
void fn_8015D8B8(void*, void*, u32);
void fn_801E0CC0();
int fn_801D7AD8();
void fn_801A5414(void*, u32, Data**, int);
void fn_8015D8C0(void*, void*, u32);
void fn_8015D874();

void fn_80047560(Obj* self) {
    Data* local;
    u32 count;
    u32 size;
    u32 enabled = 0;
    Data* data = self->data;
    char* base = data->values;
    count = *(u32*)(base + data->offset);
    void* buffer;

    if (count > 8 && count < 0x156 &&
        (enabled = fn_8015D804(base)) == 1) {
        size = count * 0x30;
        DCFlushRange(self->buffer, size);
        fn_8015D8B8((void*)0xE0000000, self->buffer, size);

        while (fn_801D7AD8() != 0) {
            fn_801E0CC0();
        }

        buffer = (void*)0xE0000000;
    } else {
        buffer = self->buffer;
        self->flags &= ~1U;
    }

    int items = self->count;
    if (items != 0) {
        local = self->data;
        fn_801A5414(buffer, self->fieldF0, &local, items);
    }

    if (enabled != 0) {
        fn_8015D8C0(self->buffer, (void*)0xE0000000, count * 0x30);
        fn_8015D874();
    }
}
}
