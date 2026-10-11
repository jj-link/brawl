extern "C" {
// Destructor adapters forward the control word unchanged; the destination
// interprets its low signed 16 bits when deciding whether to deallocate.
void* fn_91_185F4(void*, int);
void* fn_91_5D04(void*, int);
bool fn_91_18F3C(void*);
int fn_91_18F9C(void*);
void* fn_91_19048(void* object, int deleting) {
    return fn_91_185F4(static_cast<unsigned char*>(object) - 0x40, deleting);
}
void* fn_91_19050(void* object, int deleting) {
    return fn_91_185F4(static_cast<unsigned char*>(object) - 0x90, deleting);
}
void* fn_91_19058(void* object, int deleting) {
    return fn_91_185F4(static_cast<unsigned char*>(object) - 0x88, deleting);
}
void* fn_91_19060(void* object, int deleting) {
    return fn_91_5D04(static_cast<unsigned char*>(object) - 0x40, deleting);
}
bool fn_91_19068(void* object) {
    return fn_91_18F3C(static_cast<unsigned char*>(object) - 0x70);
}
void* fn_91_19070(void* object, int deleting) {
    return fn_91_5D04(static_cast<unsigned char*>(object) - 0x90, deleting);
}
int fn_91_19078(void* object) {
    return fn_91_18F9C(static_cast<unsigned char*>(object) - 0x88);
}
void* fn_91_19080(void* object, int deleting) {
    return fn_91_5D04(static_cast<unsigned char*>(object) - 0x88, deleting);
}
}
