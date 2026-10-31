#pragma force_active on
extern "C" void* fn_122_CDEC(void* self, int n);

extern "C" void* fn_122_CED8(void* self, int n) {
    switch (n) {
    case 0:
        return self;
    case 1:
        return (char*)self + 0x4e0;
    case 2:
        return fn_122_CDEC(self, n);
    default:
        return fn_122_CDEC(self, n);
    }
}
