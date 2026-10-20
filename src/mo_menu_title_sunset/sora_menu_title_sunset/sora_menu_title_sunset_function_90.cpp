#pragma force_active on
extern "C" {
void __dt__14gfFileIOHandleFv(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_25_90(void* self, int flag) {
    if (self) {
        char* object = (char*)self;
        __dt__14gfFileIOHandleFv(object + 0x50, -1);
        __dt__14gfFileIOHandleFv(object + 0x4C, -1);
        __dt__14gfFileIOHandleFv(object + 0x48, -1);
        __dt__14gfFileIOHandleFv(object + 0x44, -1);
        __dt__6gfTaskFv(self, 0);
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
