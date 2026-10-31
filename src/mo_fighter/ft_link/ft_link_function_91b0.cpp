#pragma force_active on
extern "C" void* fn_93_8A1C(void* self, int param);

extern "C" void* fn_93_91B0(void* self, int param) {
    switch (param) {
        case 0: return self;
        case 1: return (char*)self + 0x47c;
        case 2: return fn_93_8A1C(self, param);
        default: return fn_93_8A1C(self, param);
    }
}