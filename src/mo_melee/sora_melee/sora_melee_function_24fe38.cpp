#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct Self {
    char pad[0x100];
    u32 field100;
    void* buffer;
    u8 pending;
    char pad109[3];
    u32 field10c;
};

struct Data {
    char pad0[8];
    u32 offset;
    u32 size;
    char pad10[7];
    u8 flag;
    char pad18[0x80 - 0x18];
    char header[0x3f0];
    char contents[0x2000];
};

struct GameGlobal {
    char pad[0x40];
    Data* data;
};

struct Record {
    char pad[0x28];
    u8 flags;
};

extern "C" {
extern GameGlobal* g_GameGlobal;

void* getHeap__13gfHeapManagerFQ25Heaps8HeapType(int);
void fn_8002F9E8(int, u32, u32*, void*, u32*, void**, u32*);
void* memset(void*, int, unsigned long);
void* memcpy(void*, const void*, unsigned long);
Record* getGlobalRecordMenuDatap__10GameGlobalFv(GameGlobal*);
void free__13gfHeapManagerFPv(void*);

void fn_27_24FE38(Self* self) {
    if (self->pending) {
        self->pending = 0;
        void* heap = getHeap__13gfHeapManagerFQ25Heaps8HeapType(0x11);
        u32 size = 0;
        fn_8002F9E8(2, 0x2000, &size, heap, &self->field100,
                    &self->buffer, &self->field10c);

        Data* data = g_GameGlobal->data;
        memset(data->contents, 0, 0x2000);
        memset(data->header, 0, 0x3f0);

        if (self->buffer) {
            memcpy(data->contents, self->buffer, size);
            data->offset = 0x470;
            data->size = size;
            data->flag =
                (getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal)->flags >> 7) & 1;

            if (self->buffer) {
                free__13gfHeapManagerFPv(self->buffer);
                self->buffer = 0;
            }
        }
    }
}
}
