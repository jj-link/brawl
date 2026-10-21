#pragma force_active on

extern "C" {
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(int, unsigned long, long);
void free__13gfHeapManagerFPv(void*);
void* memcpy(void*, const void*, unsigned long);
void* memset(void*, int, unsigned long);
}

struct Object {
    int unk0;
    int heap;
    int unk8;
    char* buffer;
    unsigned int size;
};

extern "C" void fn_80152A60(Object* self, const void* data, unsigned int size) {
    if (data == 0 || size == 0) {
        return;
    }

    if (self->size != size) {
        char* buffer = (char*)alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(
            self->heap, size + 0x34, 0x20);

        if (buffer != 0) {
            if (self->buffer != 0) {
                memcpy(buffer, self->buffer, 0x34);
            } else {
                memset(buffer, 0, 0x34);
            }
            memcpy(buffer + 0x34, data, size);
        }

        if (self->buffer != 0) {
            free__13gfHeapManagerFPv(self->buffer);
        }

        self->buffer = buffer;
        if (buffer != 0) {
            self->size = size;
        } else {
            self->size = 0;
        }
    } else if (self->buffer != 0) {
        memcpy(self->buffer + 0x34, data, size);
    }
}
