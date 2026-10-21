#pragma force_active on
extern "C" {
int isCanceled__14gfFileIOHandleCFv(void* self);

int fn_8001588C(char* self) {
    unsigned char flags = *(unsigned char*)(self + 0x9);
    if (!((flags >> 7) & 1) && !((flags >> 5) & 1)) {
        if (isCanceled__14gfFileIOHandleCFv(self + 0x6C)) {
            return 1;
        }
    }
    return 0;
}
}
