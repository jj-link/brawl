#pragma force_active on
typedef unsigned char u8;

extern "C" {
void* getBuffer__14gfFileIOHandleCFv(const void*);
void free__13gfHeapManagerFPv(void*);
void release__14gfFileIOHandleFv(void*);
void fn_25_11B4(void*);
void exit__6gfTaskFv(void*);
void fn_25_430(void*);
void fn_25_2A74(void*);
void fn_8018E808(void*);
void fn_37_E04(void*);

void fn_1_20700(u8* self) {
    free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(self + 0x18));
    release__14gfFileIOHandleFv(self + 0x18);
    fn_25_11B4(*(void**)(self + 8));
    exit__6gfTaskFv(*(void**)(self + 8));
    *(void**)(self + 8) = 0;
    fn_25_430(*(void**)(self + 0xC));
    exit__6gfTaskFv(*(void**)(self + 0xC));
    *(void**)(self + 0xC) = 0;
    fn_25_2A74(*(void**)(self + 0x10));
    exit__6gfTaskFv(*(void**)(self + 0x10));
    *(void**)(self + 0x10) = 0;
    free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(self + 0x2C));
    release__14gfFileIOHandleFv(self + 0x2C);
    fn_8018E808(self + 0x30);
    fn_37_E04(*(void**)(self + 0x14));
    exit__6gfTaskFv(*(void**)(self + 0x14));
    *(void**)(self + 0x14) = 0;
}
}
