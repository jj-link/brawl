#include <gf/gf_file_io_handle.h>
#include <ut/ut_list.h>
#pragma force_active on

struct Sub {
    utListNode links;
    void* node;
    void* vtable;
    gfFileIOHandle handle;
};
struct Sub2 {
    utListNode links;
    void* node;
};
struct Obj {
    unsigned int field0;
    Sub2 sub2;
    void* vtable;
    Sub sub;
    unsigned char pad28[4];
    unsigned char byte2c;
    void* vtable2;
};
extern "C" {
void fn_800FABEC(void*);
void __dl__FPv(void*);
extern char lbl_8045C4BC[];
extern char lbl_8045B4B8[];
extern utList lbl_8049E550;
}
extern "C" void* fn_800ED9D0(Obj* object, int deleting) {
    if (object) {
        object->vtable2 = lbl_8045C4BC;
        object->vtable = lbl_8045C4BC + 8;
        fn_800FABEC(&object->sub);
        int zero = 0;
        object->field0 = zero;
        object->byte2c = zero;
        if (&object->sub != 0) {
            object->sub.vtable = lbl_8045B4B8;
            fn_800FABEC(&object->sub);
            object->sub.handle.release();
            object->sub.handle.~gfFileIOHandle();
            if (&object->sub != 0) {
                if (&object->sub != 0) {
                    lbl_8049E550.removeExist(&object->sub.links);
                    object->sub.node = (void*)zero;
                    if (&object->sub != 0) {
                        if (object->sub.node != 0) {
                            ((utList*)0)->removeExist(&object->sub.links);
                            object->sub.node = (void*)zero;
                        }
                    }
                }
            }
        }
        if (&object->sub2 != 0) {
            if (&object->sub2 != 0) {
                lbl_8049E550.removeExist(&object->sub2.links);
                int zero2 = 0;
                object->sub2.node = (void*)zero2;
                if (&object->sub2 != 0) {
                    if (object->sub2.node != 0) {
                        ((utList*)0)->removeExist(&object->sub2.links);
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