#pragma force_active on

extern void fn_8023052C(void);
extern void fn_80230508(void);
extern void *fn_8022F77C(void *pool);

void *fn_8022F81C(void *arg0, void *arg1) {
    void *head;
    void *target;
    void *curr;
    void *next;
    void *tail;
    unsigned short count;

    fn_8023052C();
    head = *(void **)arg0;

    if (arg1 == head) {
        fn_80230508();
        return fn_8022F77C(arg0);
    }

    target = (char *)arg1 - 8;
    curr = (char *)head - 8;

    while (curr != 0) {
        next = *(void **)curr;
        if (next == target) {
            *(void **)curr = *(void **)target;

            tail = *(void **)((char *)arg0 + 4);
            if (arg1 == tail) {
                *(void **)((char *)arg0 + 4) = (char *)curr + 8;
            }

            count = *(unsigned short *)((char *)arg0 + 8);
            count--;
            *(unsigned short *)((char *)arg0 + 8) = count;
            *(void **)target = 0;
            *(unsigned char *)((char *)target + 6) = 1;

            fn_80230508();
            return arg1;
        }
        curr = next;
    }
    fn_80230508();
    return 0;
}