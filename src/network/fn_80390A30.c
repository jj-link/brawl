#pragma force_active on
extern int OSReceiveMessage(void *queue, void *msg, int flags);

void fn_80390A30(void *queue) {
    int sp8;

    OSReceiveMessage(queue, &sp8, 1);
}
