#include <types.h>

extern "C" void* fn_111_3FFC(void* object, int deleting);
extern "C" int fn_111_95C0(void* object, void* context, void* event);
extern "C" void* fn_111_31C8(void* object, int deleting);

// The destructor callees sign-extend the deleting flag; these adjustors
// forward the word unchanged from the secondary interface at offset four.
extern "C" void* fn_111_C5A8(void* interface, int deleting) {
    return fn_111_3FFC(static_cast<u8*>(interface) - 4, deleting);
}

extern "C" int fn_111_C5B0(void* interface, void* context, void* event) {
    return fn_111_95C0(static_cast<u8*>(interface) - 4, context, event);
}

extern "C" void* fn_111_C5B8(void* interface, int deleting) {
    return fn_111_31C8(static_cast<u8*>(interface) - 4, deleting);
}
