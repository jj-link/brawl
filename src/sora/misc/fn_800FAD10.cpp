#pragma force_active on

extern "C" {
bool isReady__14gfFileIOHandleCFv(const void*);
int getReturnStatus__14gfFileIOHandleCFv(const void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
}

extern "C" bool fn_800FAD10(void* self) {
    char* p = (char*)self;

    if (!isReady__14gfFileIOHandleCFv(p + 0x24)) {
        return false;
    }

    if (*(unsigned char*)(p + 0x2C) == 0 &&
        getReturnStatus__14gfFileIOHandleCFv(p + 0x24) == 0) {
        *(void**)(p + 0x00) = getBuffer__14gfFileIOHandleCFv(p + 0x24);
        Init__Q34nw4r3g3d7ResFileFPv(self);
        *(unsigned char*)(p + 0x2C) = 1;
    }
    return true;
}