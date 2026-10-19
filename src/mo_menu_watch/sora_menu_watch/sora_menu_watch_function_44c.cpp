#pragma force_active on
class gfFileIOHandle {
public:
    ~gfFileIOHandle();
};

class sora_menu_watch_obj {
public:
    int unk0;
    int unk4;
    gfFileIOHandle h8;
};

extern "C" void __dl__FPv(void*);

extern "C" sora_menu_watch_obj* fn_15_44C(sora_menu_watch_obj* self, int flag) {
    if (self) {
        self->h8.~gfFileIOHandle();
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
