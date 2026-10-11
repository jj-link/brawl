// Secondary-interface entry points recover the complete weapon before
// forwarding to its destructor or event callback. Deleting flags and event
// arguments pass through unchanged; adjustment is unconditional, including null.
extern "C" {
void* fn_98_1AB8C(void*, int);
void* fn_98_5034(void*, int);
void fn_98_1B76C(void*, const void*, void*);
int fn_98_1B82C(void*, unsigned int);
void fn_98_1BAD4(void*);

void* fn_98_1BB80(void* interface, int deleting) {
    return fn_98_1AB8C(static_cast<char*>(interface) - 0x40, deleting);
}
void* fn_98_1BB88(void* interface, int deleting) {
    return fn_98_1AB8C(static_cast<char*>(interface) - 0x90, deleting);
}
void* fn_98_1BB90(void* interface, int deleting) {
    return fn_98_1AB8C(static_cast<char*>(interface) - 0x88, deleting);
}
void* fn_98_1BB98(void* interface, int deleting) {
    return fn_98_5034(static_cast<char*>(interface) - 0x40, deleting);
}
void fn_98_1BBA0(void* interface, const void* event, void* accesser) {
    fn_98_1B76C(static_cast<char*>(interface) - 0x54, event, accesser);
}
int fn_98_1BBA8(void* interface, unsigned int flags) {
    return fn_98_1B82C(static_cast<char*>(interface) - 0x70, flags);
}
void* fn_98_1BBB0(void* interface, int deleting) {
    return fn_98_5034(static_cast<char*>(interface) - 0x90, deleting);
}
void fn_98_1BBB8(void* interface) {
    fn_98_1BAD4(static_cast<char*>(interface) - 0x88);
}
void* fn_98_1BBC0(void* interface, int deleting) {
    return fn_98_5034(static_cast<char*>(interface) - 0x88, deleting);
}
}
