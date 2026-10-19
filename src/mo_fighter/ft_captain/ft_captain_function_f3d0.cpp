#pragma force_active on
extern "C" {
void* getInstance__15gfTaskSchedulerFv();
void* getTask__15gfTaskSchedulerFQ26gfTask8CategoryUl(void*, int, unsigned int);
extern void* lbl_27_bss_5668;
void fn_27_222A94(void*);
}

extern "C" void fn_100_F3D0() {
    void* scheduler = getInstance__15gfTaskSchedulerFv();
    unsigned char* task = static_cast<unsigned char*>(
        getTask__15gfTaskSchedulerFQ26gfTask8CategoryUl(scheduler, 0x21, 0));
    if (task != 0 && ((task[0x2c] >> 5) & 1) != 0) {
        fn_27_222A94(lbl_27_bss_5668);
    }
}
