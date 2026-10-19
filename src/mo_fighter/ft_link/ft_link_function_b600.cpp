#pragma force_active on
extern "C" void fn_93_B4D4(void*, void*, void*);

struct Local {
    unsigned char data[16];
};

extern "C" Local* fn_93_B600(void* a, void* b) {
    Local local;
    fn_93_B4D4(&local, a, b);
    return &local;
}
