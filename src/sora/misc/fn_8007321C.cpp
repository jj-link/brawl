#pragma force_active on

struct sndSystem {
    char pad0[0x18c];
    char field18c[0xe0];
    char field26c[0xc];
    void* field278;
    int field27c;
    char pad280[0x14];
    char field294[0x460];
    void* buffer1;
    void* buffer2;
    void* buffer3;
};

extern "C" {
unsigned long fn_801C8D38(void*, sndSystem*);
unsigned long fn_801C6110(void*, sndSystem*);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
int fn_801C8B3C(void*, sndSystem*, void*, unsigned long, void*, unsigned long);
int fn_801C6164(void*, sndSystem*, void*, unsigned long);
void check__12gfErrorCheckFv();

int setupBuffers__9sndSystemFv(sndSystem* self) {
    unsigned long size1 = fn_801C8D38(self->field18c, self);
    unsigned long size2 = fn_801C6110(self->field26c, self);

    self->buffer1 = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(5, size1);
    self->buffer2 = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(5, 0xe6000);
    self->buffer3 = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(5, size2);

    if (!fn_801C8B3C(self->field18c, self, self->buffer1, size1,
                     self->buffer2, 0xe6000)) {
        check__12gfErrorCheckFv();
        return 0;
    }

    if (!fn_801C6164(self->field26c, self, self->buffer3, size2)) {
        check__12gfErrorCheckFv();
        return 0;
    }

    self->field27c = 0x20;
    self->field278 = self->field294;
    return 1;
}
}
