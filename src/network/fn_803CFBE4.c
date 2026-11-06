#include <revolution/OS/OSInterrupt.h>
#pragma force_active on
typedef struct { char pad[0x1b40]; int state, previousState, error, previousError; } State;
typedef struct { int a; char pad[0x18c - 4]; int kind, index; } Entry;
extern int fn_803CD270(void);
extern Entry *fn_803CD3B4(int);
extern void fn_803CD318(int);
extern State *fn_803CD324(void);
extern int fn_803CD32C(void);
extern void fn_8020B898(void *, void *);
extern int fn_8020C34C(void *, void (*)(void), void *);
extern void fn_803CFA44(void);
void fn_803CFBE4(int a, int b) {
    int result, previous;
    BOOL enabled;
    int *info;
    void *buf;
    char *ptr;
    Entry *entry;
    entry = fn_803CD3B4(a);
    enabled = OSDisableInterrupts();
    fn_803CD318(1);
    previous = fn_803CD324()->state;
    fn_803CD324()->previousState = previous;
    previous = fn_803CD324()->error;
    fn_803CD324()->previousError = previous;
    fn_803CD324()->state = 6;
    OSRestoreInterrupts(enabled);
    entry->a = b;
    buf = (char *)fn_803CD3B4(a) + 0xd4;
    entry = fn_803CD3B4(a);
    info = &entry->kind;
    info[0] = 15;
    info[1] = a;
    fn_8020B898(buf, info);
    if (fn_803CD270())
        ptr = (char *)fn_803CD3B4(a) + 0x48;
    else
        ptr = 0;
    result = fn_8020C34C(ptr, fn_803CFA44, buf);
    switch (result) {
    case 0: break;
    case -3:
    case -4:
        switch (fn_803CD324()->state) {
        case 0:
        case 6: {
            BOOL enabled = OSDisableInterrupts();
            fn_803CD318(0);
            fn_803CD324()->state = 2;
            fn_803CD324()->error = result;
            OSRestoreInterrupts(enabled);
            break;
        }}
        break;
    case -1:
    case -8:
    case -64:
    case -128:
    default:
        switch (fn_803CD324()->state) {
        case 0:
        case 6: {
            BOOL enabled = OSDisableInterrupts();
            fn_803CD318(0);
            fn_803CD324()->state = 5;
            fn_803CD324()->error = result;
            OSRestoreInterrupts(enabled);
            break;
        }}
        break;
    }
    fn_803CD32C();
}