#include <string.h>
#include <revolution/OS/OSInterrupt.h>
#include <types.h>
#pragma force_active on

typedef struct State {
    u8 pad0[0x160];
    s8 head;
    s8 tail;
    u8 pad162[2];
    void *buf;
    s32 size;
    u8 pad16C[0x8BC - 0x16C];
    s32 field8BC;
    u8 pad8C0[0x20];
    s32 field8E0;
    u8 pad8E4[0xAA];
    u8 byte98E;
} State;

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

extern State *lbl_804F6810[];
extern char lbl_8047C73C[];
extern char lbl_8047C774[];
extern char lbl_8059ED0C[4];
extern void fn_8022550C(void *, ...);
extern int fn_8021DC5C(void *, u32, u8, void (*)(int, int));
extern void fn_80218EB8(int, int);
extern void fn_80218DE4(int, int);

static inline s8 queue_count(State *q)
{
    s32 irq = OSDisableInterrupts();
    s8 count = q->tail - q->head;

    if (count < 0)
        count += q->size;
    OSRestoreInterrupts(irq);
    return count;
}

static inline s32 begin_enqueue(State *q, s32 *count)
{
    s32 irq = OSDisableInterrupts();
    *count = queue_count(q);
    return irq;
}

#define ENQUEUE(OUT, EN, CNT, LOCK_QUEUE) do { \
    { \
        LOCK_QUEUE; \
        if ((u32)(q->size - 1) == (u32)CNT) { \
            OSRestoreInterrupts(EN); \
        } else { \
            memset((char *)q->buf + (s8)q->tail * 0x30, 0, 0x30); \
            memcpy((char *)q->buf + (s8)q->tail * 0x30, &(OUT), 0x30); \
            { \
                s32 n = q->size - 1; \
                q->tail = q->tail == n ? 0 : q->tail + 1; \
            } \
            OSRestoreInterrupts(EN); \
        } \
    } \
} while (0)

static inline void init_simple(Msg *m, s32 type, u8 value, s32 callback)
{
    m->type = type;
    m->g = 1;
    *(u8 *)&m->a = value;
    m->l = callback;
    if (type == 0x15) m->k = 0;
}

static inline void send_read(State *q, u16 v, s32 value, s32 cb)
{
    Msg m5, o5;
    s32 en2, cnt2;
    m5.type = 0x17;
    m5.g = 6;
    m5.l = cb;
    memcpy(&m5.a, &value, 4);
    memcpy(&m5.b, &v, 2);
    m5.i = v;
    m5.h = (u32)q + 0x934UL;
    m5.j = value;
    o5 = m5;
    ENQUEUE(o5, en2, cnt2, en2 = begin_enqueue(q, &cnt2));
}

static inline void send_simple(State *q, s32 type, u8 value, s32 cb)
{
    Msg m6, o6;
    s32 en2, cnt2;
    init_simple(&m6, type, value, cb);
    o6 = m6;
    ENQUEUE(o6, en2, cnt2, en2 = begin_enqueue(q, &cnt2));
}

void fn_80218F9C(int arg0, s32 arg1)
{
    Msg o1, m1, o2, m2, o3, m3, o4, m4;
    u8 channel;
    s32 msgSize;
    State *q;
    s32 mask;
    s32 cnt;
    s32 en;

    q = lbl_804F6810[arg0];
    if (arg1 == -1)
        return;

    {
        s32 irq = OSDisableInterrupts();
        q->field8E0 = (arg1 == 0);
        q->field8BC = 0;
        OSRestoreInterrupts(irq);
    }

    msgSize = arg1 == 0 ? 0x14 : 0x2A;
    mask = -((arg1 == 0) & 1) & 0x176C;
    arg0 = (1 << arg0) & 0xFF;
    fn_8022550C((void *)lbl_8047C73C,
                q->field8E0 != 0 ? (void *)lbl_8059ED0C : (void *)lbl_8047C774);
    fn_8021DC5C((char *)q + 0x160, 0, q->byte98E, fn_80218EB8);

    init_simple(&m1, 0x1A, 0, (s32)fn_80218EB8);
    o1 = m1;
    ENQUEUE(o1, en, cnt, en = OSDisableInterrupts(); cnt = queue_count(q));

    init_simple(&m2, 0x11, (arg0 & 0xF) << 4, (s32)fn_80218EB8);
    o2 = m2;
    ENQUEUE(o2, en, cnt, en = OSDisableInterrupts(); cnt = queue_count(q));

    {
        s32 value = 0x2A;
        u16 v = 0x38;
        m3.type = 0x17;
        m3.g = 6;
        m3.l = (s32)fn_80218EB8;
        memcpy(&m3.a, &value, 4);
        memcpy(&m3.b, &v, 2);
        m3.i = v;
        m3.h = (s32)((char *)q + 0x934);
        m3.j = value;
        o3 = m3;
        ENQUEUE(o3, en, cnt, en = OSDisableInterrupts(); cnt = queue_count(q));
    }

    {
        s32 value = 0x62;
        u16 v = 0x38;
        m4.type = 0x17;
        m4.g = 6;
        m4.l = (s32)fn_80218EB8;
        memcpy(&m4.a, &value, 4);
        memcpy(&m4.b, &v, 2);
        m4.i = v;
        m4.h = 0x934 + (s32)q;
        m4.j = value;
        o4 = m4;
        ENQUEUE(o4, en, cnt, en = OSDisableInterrupts(); cnt = queue_count(q));
    }

    send_read(q, msgSize, mask, (s32)fn_80218DE4);
    send_simple(q, 0x15, 0, 0);
}
