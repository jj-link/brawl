#pragma force_active on
extern "C" void fn_40_41478(void*);
extern "C" int fn_800B5854(void*, int, int, int, int);

extern "C" void fn_40_42D20(void* self) {
    int mode = 3;
    void* p = *(void**)((char*)self + 0x714);
    if (*(unsigned char*)((char*)self + 0xC29)) {
        mode = 1;
    }

    fn_40_41478(self);
    fn_800B5854(p, mode, 0x11, 1, 0);
    *(int*)((char*)self + 0xC18) = 0;
}
