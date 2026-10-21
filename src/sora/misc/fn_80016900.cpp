#pragma force_active on
extern "C" void fn_80016900(void *arg0, unsigned int arg1, unsigned int arg2) {
    unsigned int *p = (unsigned int *)((char *)arg0 + 0xEC);
    union {
        unsigned int v;
        struct {
            unsigned int lo : 5;
            unsigned int f : 5;
            unsigned int hi : 22;
        } b;
    } u;
    u.v = *p;
    u.b.f = (u.b.f & ~(1u << arg2)) | (arg1 << arg2);
    *p = u.v;
}
