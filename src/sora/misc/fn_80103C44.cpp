#pragma force_active on

extern "C" int fn_800FA740(void*);
extern "C" int fn_801063BC(void);
extern "C" int fn_801063C4(void);

extern "C" int fn_80103C44(const char* p) {
    int result = 0;
    if ((*(unsigned char*)(p + 0x42) >> 6 & 1) && fn_800FA740(*(void**)(p + 0x32C)) != 0) {
        fn_801063BC();
        if (fn_801063C4() != 0) {
            result = 1;
        }
    }
    return result;
}