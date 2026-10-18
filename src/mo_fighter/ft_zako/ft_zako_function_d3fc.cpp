#pragma force_active on
extern "C" int fn_27_1312F8(void*);
extern "C" int fn_27_195DF0(void*, void*);

extern "C" int fn_126_D3FC(void* arg0, void* arg1) {
    int result = 0;
    if (fn_27_1312F8(arg0)) {
        if (fn_27_195DF0(*(void**)((char*)arg0 + 0x60), arg1)) {
            result = 1;
        }
    }
    return result;
}
