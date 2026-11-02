#include <string.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct Msg {
    int type;
    int a;
    int b;
    int c;
    int d;
    int e;
    short f;
    short g;
    int h;
    unsigned short i;
    int j;
    int k;
    int l;
} Msg;

typedef struct Queue {
    signed char head;
    signed char tail;
    void* buf;
    int size;
} Queue;

int fn_8021E1E8(Queue* q, int arg1, unsigned short s, int v, int arg4) {
    Msg m;
    int en;
    signed char cnt;
    Msg out;
    m.type = 0x17;
    m.g = 6;
    m.l = arg4;
    memcpy(&m.a, &v, 4);
    memcpy(&m.b, &s, 2);
    m.i = s;
    m.h = arg1;
    m.j = v;
    out = m;
    en = OSDisableInterrupts();
    {
        int en2 = OSDisableInterrupts();
        cnt = q->tail - q->head;
        if (cnt < 0) cnt += q->size;
        OSRestoreInterrupts(en2);
    }
    if ((unsigned)(q->size - 1) == (unsigned)cnt) {
        OSRestoreInterrupts(en);
        return 0;
    }
    memset((char*)q->buf + q->tail * 0x30, 0, 0x30);
    memcpy((char*)q->buf + q->tail * 0x30, &out, 0x30);
    {
        int n = q->size - 1;
        q->tail = (q->tail == n) ? 0 : q->tail + 1;
    }
    OSRestoreInterrupts(en);
    return 1;
}
