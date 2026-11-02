#pragma force_active on

extern "C" {
void* getMsgData__5MuMsgFUlPPv(void* self, unsigned long index, void** size);
void* memcpy(void* dest, const void* src, unsigned long size);
void fn_800B92D8(void* msg, unsigned long index, char* buffer, unsigned long len);
}

struct Obj {
    char pad[0x66C];
    void* msg;
    int ids[8];
};

static inline void* getIt(Obj* self, int a, int b, unsigned long* size)
{
    return getMsgData__5MuMsgFUlPPv(self->msg, a + b - 1, (void**)size);
}

extern "C" void fn_2_2CC28(Obj* self)
{
    unsigned long pos = 0;
    char buffer[0x100];
    unsigned long size;
    int i;
    int k;
    void* data;

    for (i = 0; i < 0x100; i++) {
        buffer[i] = 0;
    }

    for (i = 0; i < 8; i++) {
        if (self->ids[i] != 0) {
            data = getIt(self, i * 2, self->ids[i], &size);
            for (k = i + 1; k < 8; k++) {
                if (self->ids[k] != 0) {
                    data = getIt(self, i * 2 + 16, self->ids[i], &size);
                    break;
                }
            }
            memcpy(buffer + pos, data, size);
            pos += size;
        }
    }

    if (pos == 0) {
        data = getMsgData__5MuMsgFUlPPv(self->msg, 0x20, (void**)&size);
        memcpy(buffer + pos, data, size);
        pos += size;
    }

    data = getMsgData__5MuMsgFUlPPv(self->msg, 0x21, (void**)&size);
    memcpy(buffer + pos, data, size);
    fn_800B92D8(self->msg, 0, buffer, pos + size);
}
