#include <types.h>
#pragma force_active on

struct gfFileIOHandle {
    bool isReady() const;
    void release();
    u32 raw[4];
};

struct Unk398 {
    void* unk0;
    u32 unk4;
};

struct Target {
    char pad0[0x398];
    Unk398* unk398;
    u8 unk39C;
    char pad1[3];
    gfFileIOHandle handle;
};

extern "C" {
    u32 fn_13_0();
    u32 fn_13_BA4(u32);
    void fn_800B00B0(void*, gfFileIOHandle*);
    void fn_1_40E0(u32);
}

extern "C" s32 fn_1_5190(Target* self) {
    if (self->unk39C == 0) {
        if (self->handle.isReady()) {
            if (self->unk398->unk4 == 0) {
                self->unk398->unk4 = fn_13_0();
            }
            if (fn_13_BA4(self->unk398->unk4) == 1) {
                fn_800B00B0(self->unk398->unk0, &self->handle);
                self->handle.release();
                self->unk39C = 1;
                fn_1_40E0(0);
            }
        }
    }
    return 0;
}
