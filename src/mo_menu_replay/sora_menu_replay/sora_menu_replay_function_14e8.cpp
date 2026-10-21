#pragma force_active on
typedef unsigned char u8;

struct gfFileIOHandle {
    void release();
    ~gfFileIOHandle();
};

struct Sub {
    u8 pad0[8];
    void* node;
    void* vtable;
    gfFileIOHandle handle;
};

struct Obj {
    u8 pad0[0x1D1C];
    Sub sub;
};

extern "C" void fn_800FABEC(void*);
extern "C" void removeExist__6utListFP10utListNode(void*, void*);
extern "C" void __dl__FPv(void*);
extern "C" void fn_6_930(void*, int);
extern "C" u8 lbl_7_data_580[];
extern "C" u8 lbl_8049E550[];

extern "C" void* fn_7_14E8(Obj* arg0, int arg1) {
    if (arg0 != 0) {
        if (&arg0->sub != 0) {
            arg0->sub.vtable = lbl_7_data_580;
            fn_800FABEC(&arg0->sub);
            arg0->sub.handle.release();
            arg0->sub.handle.~gfFileIOHandle();
            if (&arg0->sub != 0) {
                if (&arg0->sub != 0) {
                    removeExist__6utListFP10utListNode(lbl_8049E550, &arg0->sub);
                    arg0->sub.node = 0;
                    if (&arg0->sub != 0) {
                        if (arg0->sub.node != 0) {
                            removeExist__6utListFP10utListNode(0, &arg0->sub);
                            arg0->sub.node = 0;
                        }
                    }
                }
            }
        }
        fn_6_930(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
