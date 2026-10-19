#pragma force_active on
extern "C" {
void* getBuffer__14gfFileIOHandleCFv(const void*);
void getPrintIndexData__7MessageFPvUlPPcPUl(
    void*, unsigned long, char**, unsigned long*);
void* memcpy(void*, const void*, unsigned long);
}

struct ReplayOwner {
    char pad[0x1AC];
    void* fileHandle;
};

struct ReplayBuffer {
    char data[0x80];
    unsigned long offset;
};

extern "C" void fn_7_558(ReplayOwner* owner, ReplayBuffer* replay) {
    unsigned long size;
    char* data;

    getPrintIndexData__7MessageFPvUlPPcPUl(
        getBuffer__14gfFileIOHandleCFv(
            (const char*)owner->fileHandle + 0x1C90),
        0xB,
        &data,
        &size);
    unsigned long copySize = size;
    unsigned long offset = replay->offset;
    memcpy(replay->data + offset, data, copySize);
    replay->offset = offset + copySize;
}
