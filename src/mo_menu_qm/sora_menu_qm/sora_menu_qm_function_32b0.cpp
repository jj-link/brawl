#pragma force_active on

extern "C" {
void* getMsgData__5MuMsgFUlPPv(void* self, unsigned long index, void** size);
void* memcpy(void* dest, const void* src, unsigned long size);
void* memset(void* dest, int c, unsigned long n);
void fn_800B92D8(void* msg, unsigned long index, char* buffer, unsigned long len);
}

struct Obj {
    char pad[0xFC];
    void* msg;
};

extern "C" void fn_4_32B0(Obj* self, unsigned long a, int b, int c, int d)
{
    char buf[0x80];
    unsigned long size;
    unsigned long pos;
    void* data;

    memset(buf, 0, 0x80);
    data = getMsgData__5MuMsgFUlPPv(self->msg, c + 0x1F, (void**)&size);
    memcpy(buf, data, size);
    pos = size;
    data = getMsgData__5MuMsgFUlPPv(self->msg, 0x2B, (void**)&size);
    memcpy(buf + pos, data, size);
    pos += size;
    if (d >= 10) {
        data = getMsgData__5MuMsgFUlPPv(self->msg, d / 10 + 0x1F, (void**)&size);
        memcpy(buf + pos, data, size);
        pos += size;
    }
    data = getMsgData__5MuMsgFUlPPv(self->msg, d % 10 + 0x1F, (void**)&size);
    memcpy(buf + pos, data, size);
    pos += size;
    if (b == 1) {
        data = getMsgData__5MuMsgFUlPPv(self->msg, 0x12, (void**)&size);
    } else {
        data = getMsgData__5MuMsgFUlPPv(self->msg, 0x13, (void**)&size);
    }
    memcpy(buf + pos, data, size);
    fn_800B92D8(self->msg, a, buf, pos + size);
}
