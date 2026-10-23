#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);

typedef struct {
    unsigned char *base;
    unsigned char *end;
    u32 size;
    u32 hiWatermark;
    u32 loWatermark;
    unsigned char *rdPtr;
    unsigned char *wrPtr;
    s32 count;
} GXFifo;

static inline void GXInitFifoPtrs(GXFifo *fifo, void *readPtr, void *writePtr)
{
    u32 level = OSDisableInterrupts();

    fifo->rdPtr = readPtr;
    fifo->wrPtr = writePtr;
    fifo->count = (unsigned char *)writePtr - (unsigned char *)readPtr;
    if (fifo->count < 0) {
        fifo->count += fifo->size;
    }
    OSRestoreInterrupts(level);
}

void GXInitFifoBase(GXFifo *fifo, void *base, u32 size)
{
    fifo->base = base;
    fifo->end = (unsigned char *)base + size - 4;
    fifo->size = size;
    fifo->count = 0;
    fifo->hiWatermark = size - 0x4000;
    fifo->loWatermark = (size >> 1) & ~0x1F;
    GXInitFifoPtrs(fifo, base, base);
}
