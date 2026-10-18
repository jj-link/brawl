#include <new>
#pragma force_active on

extern "C" {
void* fn_125_1A70(void*, short);
void* fn_125_1E50(void*, short);
void* fn_125_1EEC(void*, short);
void* fn_125_2024(void*, short);
void* fn_27_125E20(void*, short);

void* fn_125_19D0(char* this_, short deleting) {
    if (this_) {
        short memberDeleting = -1;
        fn_125_1A70(this_ + 0x1cbcc, memberDeleting);
        fn_125_1E50(this_ + 0x1c714, memberDeleting);
        fn_125_1EEC(this_ + 0x1c6d8, memberDeleting);
        fn_125_2024(this_ + 0x194, memberDeleting);
        fn_27_125E20(this_, short(0));
        if (deleting > 0) operator delete(this_);
    }
    return this_;
}
}
