#include <new>
#pragma force_active on

extern "C" {
void* fn_27_1F9CC(void*, short);
void* fn_27_C74E8(void*, short);
char* fn_107_1A58(char*, short);

char* fn_107_C094(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_27_1F9CC(object + 0x1FDBC, memberDeleting);
        fn_27_C74E8(object + 0x1FDA8, memberDeleting);
        fn_107_1A58(object, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
