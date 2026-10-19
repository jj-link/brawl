#pragma force_active on
extern "C" {
void fn_100_9B2C(void* out, void* a, int b);
}

extern "C" void* fn_100_9C58(void* a, int b) {
    unsigned char tmp[0x18];
    fn_100_9B2C(tmp, a, b);
    return tmp;
}
