#pragma force_active on
extern "C" {
void fn_800BF830(void*);
void exit__6gfTaskFv(void*);
}

extern "C" void fn_800DCBA4(void* self) {
    void** ptr = (void**)((char*)self + 0xB0);
    if (*ptr != 0) {
        fn_800BF830(*ptr);
        exit__6gfTaskFv(*ptr);
        *ptr = 0;
    }
}
