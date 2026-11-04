#pragma force_active on
typedef struct Thread {
    unsigned char data[0x318];
    void *stack;
    unsigned int tail;
} Thread;

typedef struct Context {
    void *buffer;
    int result;
    int active;
    int unknown;
    Thread thread;
} Context;

typedef struct Allocator {
    void *(*alloc)(unsigned int);
    void (*free)(void *);
    unsigned char rest[0x170];
} Allocator;

extern Allocator lbl_80534638;
extern void OSCancelThread(Thread *);

static inline void release(void *p)
{
    if (p != 0) {
        lbl_80534638.free(p);
    }
}

void fn_8035D498(Context *arg0)
{
    Thread thread;
    
    thread = arg0->thread;
    OSCancelThread(&thread);
    
    if (thread.stack != 0) {
        release(thread.stack);
        thread.stack = 0;
    }
    
    release(arg0->buffer);
    arg0->buffer = 0;
    release(arg0);
}