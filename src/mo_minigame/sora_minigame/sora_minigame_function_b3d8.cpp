#pragma force_active on
extern "C" void fn_20_2D50(void*, int);

extern "C" void* fn_20_B3D8(void* self, int flag) {
    if (self != 0) {
        fn_20_2D50(self, 0);
        if (flag > 0) {
            delete reinterpret_cast<unsigned char*>(self);
        }
    }
    return self;
}
