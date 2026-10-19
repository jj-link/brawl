#pragma force_active on
extern "C" {
void __dt__14gfFileIOHandleFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_13_450(void* self, int flag) {
    if (self) {
        __dt__14gfFileIOHandleFv(self, 0);
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
