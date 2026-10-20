#pragma force_active on
struct FtStorePad {
    char pad[0x158];
    float a;
    float b;
    float c;
};

extern "C" void fn_67_1B70(FtStorePad* self, float x, float y, float z) {
    self->a = x;
    self->b = y;
    self->c = z;
}
