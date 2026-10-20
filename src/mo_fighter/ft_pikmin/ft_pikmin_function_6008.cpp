#include <stddef.h>
#pragma force_active on

extern "C" {
void __dt__17soModelModuleImplFv(void*, short);
void* fn_113_6080(void*, short);
void* fn_27_19A83C(void*, short);
void* fn_113_6008(void* object, short deleting);
void operator delete(void*);
}

void* fn_113_6008(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__17soModelModuleImplFv(storage + 0x1F4, -1);
        fn_113_6080(storage + 0x1AC, -1);
        fn_27_19A83C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
