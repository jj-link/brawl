#pragma force_active on
extern "C" int fn_800B5854(void*, int, int, int, int);

extern "C" int fn_800FD4F0(void* arg0) {
    return fn_800B5854(*(void**)(arg0), 1, 0x10, 1, 0);
}
