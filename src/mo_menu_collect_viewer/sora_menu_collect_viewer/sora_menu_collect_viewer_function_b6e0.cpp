#pragma force_active on
extern "C" int fn_800B5854(void*, int, int, int, int);

extern "C" int fn_6_B6E0(void* self) {
    void* p = *(void**)((char*)self + 0x40);
    int mode = *(unsigned char*)((char*)self + 0x261) ? 4 : 2;
    return fn_800B5854(p, mode, 1, 1, 0);
}
