#pragma force_active on
extern "C" void* fn_98_9278(void*, int);

extern "C" void* fn_98_9364(void* self, int mode) {
    switch (mode) {
    case 0:
        return self;
    case 1:
        return (char*)self + 0x48c;
    case 2:
        return fn_98_9278(self, mode);
    default:
        return fn_98_9278(self, mode);
    }
}