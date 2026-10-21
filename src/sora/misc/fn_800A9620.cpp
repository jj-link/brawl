#pragma force_active on

extern "C" void fn_800A9620(void* self, int arg1) {
    int var_r4;
    unsigned char var_r5;

    var_r5 = 1;
    var_r4 = 0;
    if (arg1 != 0 || *reinterpret_cast<int*>(static_cast<unsigned char*>(self) + 0x60) > 0) {
        var_r4 = 1;
    }
    if (var_r4 == 0 && *reinterpret_cast<int*>(static_cast<unsigned char*>(self) + 0xB4) == 0) {
        var_r5 = 0;
    }
    *reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(self) + 0x50) = var_r5;
}
