#include <string.h>
#include <revolution/OS/OSInterrupt.h>
#include <types.h>
#pragma force_active on

typedef struct Msg {
    s32 type;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s16 f;
    s16 g;
    s32 h;
    u16 i;
    s32 j;
    s32 k;
    s32 l;
} Msg;

typedef struct Queue {
    s8 head;
    s8 tail;
    void* buf;
    s32 size;
} Queue;

int fn_8021E030(Queue* q, void* arg1, s32 arg2, s32 arg3, s32 arg4) {
    Msg m;
    Msg out;
    s32 en;
    s8 cnt;
    s8 val;

    val = (s8)(arg2 & 0x1F);
    m.type = 0x16;
    m.g = 0x15;
    m.l = arg4;
    memcpy(&m.a, &arg3, 4);
    memcpy(&m.b, &val, 1);
    memcpy((char*)&m.b + 1, arg1, arg2);
    out = m;
    en = OSDisableInterrupts();
    {
        s32 en2 = OSDisableInterrupts();
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
        s32 n = q->size - 1;
        q->tail = (q->tail == n) ? 0 : q->tail + 1;
    }
    OSRestoreInterrupts(en);
    return 1;
}