#pragma force_active on
extern "C" {
void __dt__14gfFileIOHandleFv(void* p, short v);
void* __dt__6gfTaskFv(void* p, short v);
void __dl__FPv(void* p);
}

extern "C" void* fn_80017BA4(char* self, int flag) {
    if (self) {
        if (self + 0x64) {
            __dt__14gfFileIOHandleFv(self + 0x6C, -1);
            __dt__14gfFileIOHandleFv(self + 0x68, -1);
        }
        __dt__14gfFileIOHandleFv(self + 0x48, -1);
        __dt__14gfFileIOHandleFv(self + 0x44, -1);
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
