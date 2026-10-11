#include <new>

extern "C" {
extern const char lbl_98_data_9228[];
int fn_98_18E2C(void*, const void*, void*);
void* fn_98_17434(void*, int);
void* fn_98_170B0(void*, int);
void* fn_98_3650(void*, int);
void fn_98_19078(void*);

void* fn_98_19118(void* object) {
    *static_cast<const void**>(object) = lbl_98_data_9228;
    return object;
}
void* fn_98_19128(void* object, short deleting) {
    if (object && deleting > 0) operator delete(object);
    return object;
}

// Recover the complete owner without altering event arguments or deleting flags.
// Like the original secondary-base entry points, adjustment is unconditional.
int fn_98_19168(void* interface, const void* event, void* payload) {
    return fn_98_18E2C(static_cast<char*>(interface) - 4, event, payload);
}
void* fn_98_19170(void* interface, int deleting) {
    return fn_98_17434(static_cast<char*>(interface) - 4, deleting);
}
void* fn_98_19178(void* interface, int deleting) {
    return fn_98_170B0(static_cast<char*>(interface) - 0x40, deleting);
}
void* fn_98_19180(void* interface, int deleting) {
    return fn_98_170B0(static_cast<char*>(interface) - 0x90, deleting);
}
void* fn_98_19188(void* interface, int deleting) {
    return fn_98_170B0(static_cast<char*>(interface) - 0x88, deleting);
}
void* fn_98_19190(void* interface, int deleting) {
    return fn_98_3650(static_cast<char*>(interface) - 0x40, deleting);
}
void* fn_98_19198(void* interface, int deleting) {
    return fn_98_3650(static_cast<char*>(interface) - 0x90, deleting);
}
void fn_98_191A0(void* interface) {
    fn_98_19078(static_cast<char*>(interface) - 0x88);
}
void* fn_98_191A8(void* interface, int deleting) {
    return fn_98_3650(static_cast<char*>(interface) - 0x88, deleting);
}
}
