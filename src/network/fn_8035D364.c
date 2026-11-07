#include <revolution/OS/OSThread.h>
#include <string.h>
#pragma force_active on
typedef struct Allocator {
    void *(*alloc)(unsigned int);
    void (*free)(void *);
    unsigned char rest[0x170];
} Allocator;
typedef struct Context {
    char *name;
    int result;
    int active;
    int unknown;
    OSThread thread;
    char *stack;
    int tail;
} Context;
extern Allocator lbl_80534638;
extern void *fn_8035D2A8(void *);
int fn_8035D364(const char *name, Context **out)
{
    Context *p;
    char *copy;
    p = lbl_80534638.alloc(0x330);
    if (p == 0)
        return -1;
    if (name == 0) {
        copy = 0;
    } else {
        copy = lbl_80534638.alloc(strlen(name) + 1);
        if (copy != 0)
            strcpy(copy, name);
    }
    p->name = copy;
    if (copy == 0) {
        if (p != 0)
            lbl_80534638.free(p);
        return -1;
    }
    p->active = 0;
    p->stack = lbl_80534638.alloc(0x1000);
    OSCreateThread(&p->thread, fn_8035D2A8, p, p->stack + 0x1000, 0x1000, 0x10, 1);
    OSResumeThread(&p->thread);
    *out = p;
    return 0;
}