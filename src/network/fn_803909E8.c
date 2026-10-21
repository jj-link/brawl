#pragma force_active on
extern int OSSendMessage(void* queue, unsigned int mesg, unsigned int flags);
extern int OSJoinThread(void* thread, void* val);

void fn_803909E8(void* arg0, void* arg1) {
    *(int*)((char*)arg1 + 0x7dc) = 1;
    OSSendMessage(arg0, 0, 0);
    OSJoinThread((char*)arg0 + 0x30, 0);
}
