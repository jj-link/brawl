#pragma force_active on
extern "C" {
void* getBuffer__14gfFileIOHandleCFv(void*);
void free__13gfHeapManagerFPv(void*);
void release__14gfFileIOHandleFv(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_800AD87C(char* self, int flag) {
    if (self) {
        unsigned char flagByte = self[0x3EB0];
        if (flagByte == 0) {
            free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(self + 0x3EAC));
            release__14gfFileIOHandleFv(self + 0x3EAC);
        }
        __dt__14gfFileIOHandleFv(self + 0x3EAC, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
