#pragma force_active on
extern "C" bool isReady__14gfFileIOHandleCFv(const void*);

extern "C" bool fn_25_638(void* self) {
    char* p = (char*)self;
    if (!isReady__14gfFileIOHandleCFv(p + 0x44)) {
        return true;
    }
    if (!isReady__14gfFileIOHandleCFv(p + 0x48)) {
        return true;
    }
    if (!isReady__14gfFileIOHandleCFv(p + 0x4c)) {
        return true;
    }
    bool r = isReady__14gfFileIOHandleCFv(p + 0x50);
    return !r;
}
