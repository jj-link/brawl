#pragma force_active on
extern "C" int fn_27_1312F8(void*);
extern "C" int fn_27_195DF0(void*, void*);

extern "C" int fn_126_F370(void* arg1, void* arg2) {
    int result = 0;
    if (fn_27_1312F8(arg1)) {
        if (fn_27_195DF0(*(void**)((char*)arg1 + 0x60), arg2)) {
            result = 1;
        }
    }
    return result;
}
