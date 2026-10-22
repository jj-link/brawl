#pragma force_active on
typedef struct OSThread OSThread;
typedef struct OSMutex OSMutex;

struct OSMutex {
    char pad0[8];
    OSThread *thread;
    int count;
    OSMutex *next;
    OSMutex *prev;
};

struct OSThread {
    char pad0[0x2F4];
    OSMutex *head;
    OSMutex *tail;
};

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern OSThread *fn_801E0714(void);

int fn_801DEDC4(OSMutex *m) {
    int en = OSDisableInterrupts();
    OSThread *cur = fn_801E0714();
    int ret;
    if (m->thread == 0) {
        OSMutex *t;
        m->thread = cur;
        m->count = m->count + 1;
        t = cur->tail;
        if (t == 0) {
            cur->head = m;
        } else {
            t->next = m;
        }
        m->prev = t;
        ret = 1;
        m->next = 0;
        cur->tail = m;
    } else if (m->thread == cur) {
        ret = 1;
        m->count = m->count + 1;
    } else {
        ret = 0;
    }
    OSRestoreInterrupts(en);
    return ret;
}
