#pragma force_active on
extern "C" {
void* fn_126_6BDC(void);

void* fn_126_6CC8(void* self, int kind) {
    switch (kind) {
    case 0:
        return self;
    case 1:
        return (char*)self + 0x46c;
    case 2:
        return fn_126_6BDC();
    default:
        return fn_126_6BDC();
    }
}
}