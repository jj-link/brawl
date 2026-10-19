#pragma force_active on
extern "C" {
void fn_98_A2C8(void* ret, void* manager, int index);

void* fn_98_A3F4(void* manager, int index) {
    unsigned char buf[16];
    fn_98_A2C8(buf, manager, index);
    return buf;
}
}
