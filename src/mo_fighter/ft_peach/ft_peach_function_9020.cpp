#pragma force_active on
extern "C" {
void* fn_103_8F34(void* self, int mode);

void* fn_103_9020(void* self, int mode) {
    switch (mode) {
    case 0:
        return self;
    case 1:
        return (char*)self + 0x488;
    case 2:
        return fn_103_8F34(self, mode);
    default:
        return fn_103_8F34(self, mode);
    }
}
}
