#pragma force_active on
extern "C" {
void* getBuffer__14gfFileIOHandleCFv(const void*);
void getPrintIndexData__7MessageFPvUlPPcPUl(
    void*, unsigned long, char**, unsigned long*);
void* memcpy(void*, const void*, unsigned long);
}

struct Dest {
    char pad[0x80];
    unsigned long length;
};

struct Owner {
    char pad[0x1AC];
    char* sub;
};

extern "C" void fn_8_3C0(Owner* self, Dest* dest) {
    unsigned long size;
    char* data;

    void* buffer = getBuffer__14gfFileIOHandleCFv(self->sub + 0x1C90);
    getPrintIndexData__7MessageFPvUlPPcPUl(buffer, 3, &data, &size);
    unsigned long n = size;
    unsigned long len = dest->length;
    memcpy((char*)dest + len, data, n);
    dest->length = len + n;
}
