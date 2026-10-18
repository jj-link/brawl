#pragma force_active on
extern "C" int fn_800B5854(void*, int, int, int, int);

extern "C" int fn_14_9BE4(char* self) {
    return fn_800B5854(*(void**)(self + 0xc8), 1, 1, 1, 0);
}
