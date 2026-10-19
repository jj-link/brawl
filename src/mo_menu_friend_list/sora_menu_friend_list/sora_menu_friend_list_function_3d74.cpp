#pragma force_active on
extern "C" int fn_800B5854(void* p, int a, int b, int c, int d);

extern "C" int fn_14_3D74(char* self, int a) {
    return fn_800B5854(*(void**)(self + 0xc0), a, 1, 0, 0);
}
