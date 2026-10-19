#pragma force_active on
extern "C" int fn_800AD954(void* p);
extern "C" int isLoadFinish__20tyFigListDataManagerFv(void* manager);

extern "C" int fn_33_994(char* p) {
    int result = 0;
    if (fn_800AD954(*(void**)(p + 0x280))) {
        if (isLoadFinish__20tyFigListDataManagerFv(*(void**)(p + 0x27c))) {
            result = 1;
        }
    }
    return result;
}
