#include <gf/gf_file_io_handle.h>
#include <ut/ut_list.h>
#pragma force_active on

typedef unsigned char u8;

struct Sub {
    utListNode links;
    void* node;
    void* vtable;
    gfFileIOHandle handle;
};

struct Obj {
    u8 pad0[0x1D0C];
    Sub subA;
    u8 pad1[4];
    Sub subB;
};

extern "C" {
void fn_800FABEC(void*);
void fn_6_930(void*, int);
void __dl__FPv(void*);
extern u8 lbl_5_data_CD8[];
}
extern utList lbl_8049E550;

extern "C" void* fn_5_1237C(Obj* object, int deleting) {
    if (object) {
        if (&object->subB != 0) {
            object->subB.vtable = lbl_5_data_CD8;
            fn_800FABEC(&object->subB);
            object->subB.handle.release();
            object->subB.handle.~gfFileIOHandle();
            if (&object->subB != 0) {
                if (&object->subB != 0) {
                    lbl_8049E550.removeExist(&object->subB.links);
                    int zero = 0;
                    object->subB.node = (void*)zero;
                    if (&object->subB != 0) {
                        if (object->subB.node != 0) {
                            ((utList*)0)->removeExist(&object->subB.links);
                            object->subB.node = (void*)zero;
                        }
                    }
                }
            }
        }
        if (&object->subA != 0) {
            object->subA.vtable = lbl_5_data_CD8;
            fn_800FABEC(&object->subA);
            object->subA.handle.release();
            object->subA.handle.~gfFileIOHandle();
            if (&object->subA != 0) {
                if (&object->subA != 0) {
                    lbl_8049E550.removeExist(&object->subA.links);
                    int zero = 0;
                    object->subA.node = (void*)zero;
                    if (&object->subA != 0) {
                        if (object->subA.node != 0) {
                            ((utList*)0)->removeExist(&object->subA.links);
                            object->subA.node = (void*)zero;
                        }
                    }
                }
            }
        }
        fn_6_930(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
