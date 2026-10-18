#pragma force_active on
extern "C" int fn_27_1312F8();
extern "C" int fn_27_195DF0(void*, void*);

extern "C" int fn_126_6DB4(void* a, void* b) {
    int result = 0;
    if (fn_27_1312F8()) {
        if (fn_27_195DF0(*(void**)((char*)a + 0x60), b)) result = 1;
    }
    return result;
}
