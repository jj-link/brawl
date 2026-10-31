#pragma force_active on
extern "C" {
void* fn_106_6EF8(void* self, int x);

void* fn_106_6FE4(void* self, int x) {
    switch (x) {
    case 0:
        return self;
    case 1:
        return (char*)self + 0x490;
    case 2:
        return fn_106_6EF8(self, x);
    default:
        return fn_106_6EF8(self, x);
    }
}
}
