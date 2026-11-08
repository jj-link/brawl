#include <string.h>
#pragma force_active on

extern "C" void netReport__FPCce(const char*, ...);
extern "C" char lbl_8045E600[0x48];
extern "C" char lbl_8045E648[0x14C];

struct NetBuf {
    char pad[0x23C];
    char* data;
    int cap;
    int stride;
    int head;
    int tail;
};

extern "C" void fn_80142BF0(NetBuf* buf, int value) {
    int sum = buf->cap + (buf->tail - buf->head);
    int rem = sum % buf->cap;

    if (buf->cap - 1 - rem < 1) {
        netReport__FPCce(lbl_8045E600);
        return;
    }

    short item = (short)value;
    memcpy(buf->data + buf->tail * buf->stride, &item, buf->stride);

    int next = buf->tail + 1;
    buf->tail = next % buf->cap;
    netReport__FPCce(lbl_8045E648, value, buf->cap, next);
}
