#pragma force_active on
typedef unsigned int u32;
typedef int s32;

typedef struct ShutdownNode {
    s32 (*fn)(void*, void*);
    u32 id;
    struct ShutdownNode* next;
} ShutdownNode;

extern ShutdownNode* ShutdownFunctionQueue_805A06E8;
extern void* fn_801DFE60(void);

s32 fn_801DF06C(void* arg0, void* arg1) {
    ShutdownNode* node;
    s32 flag;
    u32 last;

    flag = 0;
    last = 0;
    node = ShutdownFunctionQueue_805A06E8;
    while (node != 0) {
        if (flag != 0 && last != node->id) {
            break;
        }
        flag |= (node->fn(arg0, arg1) == 0);
        last = node->id;
        node = node->next;
    }
    flag |= (fn_801DFE60() == 0);
    return flag == 0;
}
