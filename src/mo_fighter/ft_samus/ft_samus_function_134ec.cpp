#include <new>
#pragma force_active on

extern "C" {
void fn_94_19BC(void*, short);
void fn_94_1D9C(void*, short);
void fn_94_1E38(void*, short);
void fn_94_1358C(void*, short);
void fn_27_125E20(void*, short);

char* fn_94_134EC(char* self, short deleting) {
    if (self) {
        short memberDeleting = -1;
        fn_94_19BC(self + 0x19BF4, memberDeleting);
        fn_94_1D9C(self + 0x1973C, memberDeleting);
        fn_94_1E38(self + 0x19700, memberDeleting);
        fn_94_1358C(self + 0x194, memberDeleting);
        fn_27_125E20(self, short(0));
        if (deleting > 0) operator delete(self);
    }
    return self;
}
}
