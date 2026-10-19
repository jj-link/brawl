#pragma force_active on

typedef unsigned char u8;

struct gfFileIOHandle {
    void release();
    ~gfFileIOHandle();
};

struct MenuEditObject {
    u8 pad0[8];
    void* node;
    void* vtable;
    gfFileIOHandle handle;
};

extern "C" void fn_800FABEC(void*);
extern "C" void removeExist__6utListFP10utListNode(void*, void*);
extern "C" void __dl__FPv(void*);
extern "C" u8 lbl_5_data_CD8[];
extern "C" u8 lbl_8049E550[];

extern "C" MenuEditObject* fn_5_122BC(MenuEditObject* self, int deleting) {
    if (self != 0) {
        self->vtable = lbl_5_data_CD8;
        fn_800FABEC(self);
        self->handle.release();
        self->handle.~gfFileIOHandle();
        if (self != 0) {
            if (self != 0) {
                removeExist__6utListFP10utListNode(lbl_8049E550, self);
                self->node = 0;
                if (self != 0) {
                    if (self->node != 0) {
                        removeExist__6utListFP10utListNode(0, self);
                        self->node = 0;
                    }
                }
            }
        }
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
