#pragma force_active on
extern "C" bool isReady__14gfFileIOHandleCFv(const void*);

extern "C" bool fn_37_1094(char* self) {
    if (!isReady__14gfFileIOHandleCFv(self + 0x40)) {
        return true;
    }
    if (!isReady__14gfFileIOHandleCFv(self + 0x44)) {
        return true;
    }
    return isReady__14gfFileIOHandleCFv(self + 0x48) ? false : true;
}
