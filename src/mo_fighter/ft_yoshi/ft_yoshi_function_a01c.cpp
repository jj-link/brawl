#pragma force_active on
extern "C" void* fn_95_9F30();

extern "C" void* fn_95_A01C(void* self, int kind) {
    switch (kind) {
    case 0: return self;
    case 1: return (char*)self + 0x4A0;
    case 2: return fn_95_9F30();
    default: return fn_95_9F30();
    }
}
