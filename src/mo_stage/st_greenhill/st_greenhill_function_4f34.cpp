#pragma force_active on
struct Flags {
    unsigned flags : 2;
    unsigned upper : 30;
};

extern "C" void fn_72_4F34(void* obj, unsigned val) {
    struct Flags* f = (struct Flags*)((char*)obj + 8);
    f->flags = val;
}