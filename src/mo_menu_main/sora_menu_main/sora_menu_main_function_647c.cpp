#pragma force_active on
class gfFileIOHandle {
public:
    ~gfFileIOHandle();
};

void operator delete(void* p);

extern "C" void __dt__14gfFileIOHandleFv(void* p, int flag);

extern "C" {
gfFileIOHandle* fn_2_647C(gfFileIOHandle* self, int n);
}

gfFileIOHandle* fn_2_647C(gfFileIOHandle* self, int n) {
    if (self) {
        __dt__14gfFileIOHandleFv(self, 0);
        if (n > 0) {
            operator delete(self);
        }
    }
    return self;
}
