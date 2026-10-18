#pragma force_active on
extern "C" bool isReady__14gfFileIOHandleCFv(const void*);
extern "C" int isLoadFinishMenuSound__6muMenuFv();

extern "C" int fn_13_BA4(void* self) {
    const void* handle = static_cast<const char*>(self) + 0xE8;
    for (int i = 0; i < 8; ++i) {
        if (!isReady__14gfFileIOHandleCFv(handle)) {
            return 0;
        }
        handle = static_cast<const char*>(handle) + 4;
    }
    return isLoadFinishMenuSound__6muMenuFv();
}
