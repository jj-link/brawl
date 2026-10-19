#pragma force_active on
extern "C" {
void* getBuffer__14gfFileIOHandleCFv(const void*);
void printIndex__5MuMsgFUlUlPv(void*, unsigned long, unsigned long, void*);
}

extern "C" void fn_6_64C8(char* self, unsigned long arg) {
    void* buf = getBuffer__14gfFileIOHandleCFv(*(char**)(self + 0x1ac) + 0x1ca8);
    printIndex__5MuMsgFUlUlPv(*(void**)(*(char**)(self + 0x1ac) + 0x1c7c), 0xf, arg, buf);
}
