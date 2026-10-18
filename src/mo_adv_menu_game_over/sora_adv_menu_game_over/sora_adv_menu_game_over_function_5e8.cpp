#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

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

struct Sub2 {
    u8 pad0[8];
    void* node;
};

struct Obj {
    u32 field0;
    Sub2 sub2;
    void* vtable;
    Sub sub;
    u8 pad28[4];
    u8 byte2c;
    void* vtable2;
};

extern "C" {
void fn_800FABEC(void*);
void release__14gfFileIOHandleFv(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void removeExist__6utListFP10utListNode(void*, void*);
void __dl__FPv(void*);
extern u8 lbl_8045C4BC[];
extern u8 lbl_33_data_280[];
extern u8 lbl_8049E550[];
}

extern "C" void* fn_33_5E8(Obj* object, int deleting) {
    if (object) {
        object->vtable2 = lbl_8045C4BC;
        object->vtable = lbl_8045C4BC + 8;

        fn_800FABEC(&object->sub);

        int zero = 0;
        object->field0 = zero;
        object->byte2c = zero;

        if (&object->sub != 0) {
            object->sub.vtable = lbl_33_data_280;
            fn_800FABEC(&object->sub);
            object->sub.handle.release();
            object->sub.handle.~gfFileIOHandle();
            if (&object->sub != 0) {
                if (&object->sub != 0) {
                    removeExist__6utListFP10utListNode(lbl_8049E550, &object->sub);
                    object->sub.node = (void*)zero;
                    if (&object->sub != 0) {
                        if (object->sub.node != 0) {
                            removeExist__6utListFP10utListNode(0, &object->sub);
                            object->sub.node = (void*)zero;
                        }
                    }
                }
            }
        }

        if (&object->sub2 != 0) {
            if (&object->sub2 != 0) {
                removeExist__6utListFP10utListNode(lbl_8049E550, &object->sub2);
                int zero2 = 0;
                object->sub2.node = (void*)zero2;
                if (&object->sub2 != 0) {
                    if (object->sub2.node != 0) {
                        removeExist__6utListFP10utListNode(0, &object->sub2);
                        object->sub2.node = (void*)zero2;
                    }
                }
            }
        }

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
