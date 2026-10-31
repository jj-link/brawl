#pragma force_active on
extern "C" void* fn_118_895C(void* self, int arg);

extern "C" void* fn_118_8A48(void* self, int arg) {
    switch (arg) {
    case 0:
        return self;
    case 1:
        return (char*)self + 0x4a0;
    case 2:
        return fn_118_895C(self, arg);
    default:
        return fn_118_895C(self, arg);
    }
}
