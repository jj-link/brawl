#pragma force_active on
typedef unsigned char u8;

extern "C" {
void __dt__14gfFileIOHandleFv(void* p, int flag);
void __dt__6gfTaskFv(void* p, int flag);
void __dl__FPv(void* p);
}

class fnObj {
public:
    u8 pad[0x40];
    int h40;
    int h44;
    int h48;
};

extern "C" fnObj* fn_37_104(fnObj* self, int flag) {
    if (self) {
        __dt__14gfFileIOHandleFv(&self->h48, -1);
        __dt__14gfFileIOHandleFv(&self->h44, -1);
        __dt__14gfFileIOHandleFv(&self->h40, -1);
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
