#pragma force_active on
extern "C" {
void fn_800BF830(void*);
void exit__6gfTaskFv(void*);
}

extern "C" void fn_22_1C40(void* self) {
    void** slot = (void**)((char*)self + 0x168);
    if (*slot != 0) {
        fn_800BF830(*slot);
        exit__6gfTaskFv(*slot);
        *slot = 0;
    }
}
