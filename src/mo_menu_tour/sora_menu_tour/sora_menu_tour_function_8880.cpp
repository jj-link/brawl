#include <string.h>
#pragma force_active on
extern "C" {
void* getMsgData__5MuMsgFUlPPv(void*, unsigned long, void**);
void fn_800B92D8(void*, unsigned long, char*, unsigned long);
}
struct Self {
    char pad[0xf8];
    void* msg;
    char pad2[0x8e4];
    unsigned long value;
};
extern "C" void fn_3_8880(Self* self) {
    void* size;
    char buffer[0x100];
    memset(buffer, 0, 0x100);
    void* data = getMsgData__5MuMsgFUlPPv(self->msg, 9, &size);
    memcpy(buffer, data, (unsigned long)size);
    buffer[(unsigned long)size] = '\n';
    unsigned long pos = (unsigned long)size + 1;
    data = getMsgData__5MuMsgFUlPPv(self->msg, 10, &size);
    memcpy(buffer + pos, data, (unsigned long)size);
    pos += (unsigned long)size;
    data = getMsgData__5MuMsgFUlPPv(self->msg, self->value + 0x2b, &size);
    memcpy(buffer + pos, data, (unsigned long)size);
    pos += (unsigned long)size;
    data = getMsgData__5MuMsgFUlPPv(self->msg, 11, &size);
    memcpy(buffer + pos, data, (unsigned long)size);
    fn_800B92D8(self->msg, 5, buffer, pos + (unsigned long)size);
}