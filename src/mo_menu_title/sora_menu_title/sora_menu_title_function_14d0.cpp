#pragma force_active on
extern "C" {
void __dt__14gfFileIOHandleFv(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_24_14D0(void* self, int flag) {
    if (self) {
        __dt__14gfFileIOHandleFv((char*)self + 0x44, -1);
        __dt__14gfFileIOHandleFv((char*)self + 0x40, -1);
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
