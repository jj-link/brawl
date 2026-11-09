#pragma force_active on
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSThread.h>
typedef struct ShutdownNode {
    int (*fn)(int, int);
    unsigned int id;
    struct ShutdownNode* next;
} ShutdownNode;
extern ShutdownNode* ShutdownFunctionQueue_805A06E8;
extern void fn_801D75DC(void);
extern int fn_80216C34(int);
extern void* fn_801DFE60(void);
extern void fn_801D7928(void);
void fn_801DF11C(int arg0) {
    OSThread* next;
    int var_r29;
    int var_r28;
    ShutdownNode* node;
    int flag;
    unsigned int last;
    OSThread* t;
    if (arg0 < 5) {
        if (arg0 == 0)
            goto zero;
        goto one;
    }
    if (arg0 >= 7)
        goto one;
zero:
    var_r28 = 0;
    goto condition_done;
one:
    var_r28 = 1;
condition_done:
    fn_801D75DC();
    if (var_r28 == 0)
        var_r29 = fn_80216C34(1);
    do {
        node = ShutdownFunctionQueue_805A06E8;
        last = 0;
        flag = 0;
        while (node != 0) {
            if (flag != 0 && last != node->id)
                break;
            flag |= (node->fn(0, arg0) == 0);
            last = node->id;
            node = node->next;
        }
        flag |= (fn_801DFE60() == 0);
    } while (flag != 0);
    while (fn_801DFE60() == 0) {
    }
    OSDisableInterrupts();
    node = ShutdownFunctionQueue_805A06E8;
    last = 0;
    flag = 0;
    while (node != 0) {
        if (flag != 0 && last != node->id)
            break;
        flag |= (node->fn(1, arg0) == 0);
        last = node->id;
        node = node->next;
    }
    fn_801DFE60();
    fn_801D7928();
    if (var_r28 == 0)
        fn_80216C34(var_r29);
    t = *(OSThread**)0x800000DC;
    while (t != 0) {
        next = (OSThread*)t->nextActive;
        switch (t->state) {
        case 1:
        case 4:
            OSCancelThread(t);
            break;
        }
        t = next;
    }
}
