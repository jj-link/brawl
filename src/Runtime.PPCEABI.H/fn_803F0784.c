#pragma force_active on
typedef struct {
    void *chain;
    void *func;
    int pad;
} AtExitEntry;

extern AtExitEntry atexit_funcs_805998E0[0x40];
extern int atexit_curr_func_805A12D0;
extern void *__global_destructor_chain;

int __register_atexit(void *func) {
    int idx;
    AtExitEntry *entry;
    idx = atexit_curr_func_805A12D0;
    if (idx == 0x40) {
        return -1;
    }
    atexit_curr_func_805A12D0 = idx + 1;
    entry = &atexit_funcs_805998E0[idx];
    entry->chain = __global_destructor_chain;
    entry->func = func;
    entry->pad = 0;
    __global_destructor_chain = entry;
    return 0;
}
