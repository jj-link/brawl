#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Data {
    u16 count, count2, count3, flags;
    u32 value;
    void* data2;
    void* data3;
};

struct Object {
    u16 unk0;
    u16 count, count2, count3;
    Data* data;
    u32 value;
    void* entries;
    void* entries2;
    void* entries3;
    float x, y, z, w;
    u8 pad : 2;
    u8 mode : 2;
    u8 enabled : 1;
    u8 flag2 : 1;
    u8 pad2 : 1;
    u8 flag0 : 1;
    u8 pad3 : 3;
    u8 mode2 : 2;
    u8 pad4 : 3;
};

extern "C" {
extern void* lbl_805A0360;
extern const float lbl_27_rodata_4518;
extern const float lbl_27_rodata_451C;

void fn_80112C98(void*, Object*);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
void* fn_801107CC(Object*, u16, void*, u16);
void* fn_80110748(Object*, u16, void*);

void fn_27_275534(Object* self, Data* data) {
    self->mode = 0;
    self->enabled = 1;
    self->flag2 = 0;
    self->flag0 = 0;
    self->mode2 = 0;

    fn_80112C98(lbl_805A0360, self);

    u16 flags = data->flags;
    self->data = data;
    u16 count = data->count;
    self->count = count;
    self->count2 = data->count2;
    self->count3 = data->count3;
    self->value = data->value;

    self->entries =
        alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(15, count * 16);
    self->entries2 =
        fn_801107CC(self, self->count2, data->data2, flags);
    self->entries3 =
        fn_80110748(self, self->count3, data->data3);

    self->x = lbl_27_rodata_4518;
    self->y = lbl_27_rodata_4518;
    self->z = lbl_27_rodata_451C;
    self->w = lbl_27_rodata_451C;
}
}
