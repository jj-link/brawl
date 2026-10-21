#pragma force_active on

extern "C" void cancelRequest__14gfFileIOHandleFv(void*);

extern "C" int fn_8001583C(char* self) {
    unsigned char flags = *(unsigned char*)(self + 0x9);
    if (!((flags >> 7) & 1) && !((flags >> 5) & 1)) {
        if (*(int*)(self + 0x6C) != 0) {
            cancelRequest__14gfFileIOHandleFv(self + 0x6C);
            return 1;
        }
    }
    return 0;
}
