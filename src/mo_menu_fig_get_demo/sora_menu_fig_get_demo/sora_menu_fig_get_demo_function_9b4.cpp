#pragma force_active on
extern "C" {
int isLoadFinishMenuSound__6muMenuFv();
int isLoadFinish__20tyFigListDataManagerFv(void* manager);

int fn_26_9B4(void* self) {
    char* p = (char*)self;
    if (isLoadFinishMenuSound__6muMenuFv() == 0) {
        return *(int*)(p + 0x1368);
    }
    if (isLoadFinish__20tyFigListDataManagerFv(*(void**)(p + 0x1f0))) {
        *(int*)(p + 0x1368) = 1;
    }
    return *(int*)(p + 0x1368);
}
}
