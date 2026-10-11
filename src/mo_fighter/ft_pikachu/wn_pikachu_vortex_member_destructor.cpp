#include <so/so_module_accesser.h>

extern "C" void* fn_27_1A405C(void*, short);

extern "C" void* fn_98_1B1C0(void* member, int deleting) {
    if (member) {
        fn_27_1A405C(member, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(member);
    }
    return member;
}
