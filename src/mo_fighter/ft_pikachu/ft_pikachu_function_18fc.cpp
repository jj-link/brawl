#include <new>
#pragma force_active on

extern "C" {
void* fn_98_199C(void*, short);
void* fn_98_1D7C(void*, short);
void* fn_98_1E18(void*, short);
void* fn_98_1F50(void*, short);
void* fn_27_125E20(void*, short);

void* fn_98_18FC(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_199C(object + 0x2AD8C, memberDeleting);
        fn_98_1D7C(object + 0x2A8D4, memberDeleting);
        fn_98_1E18(object + 0x2A898, memberDeleting);
        fn_98_1F50(object + 0x194, memberDeleting);
        fn_27_125E20(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
