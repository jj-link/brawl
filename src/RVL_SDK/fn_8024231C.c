#pragma force_active on
void* fn_8023A0F0(void);

void* fn_8024231C(void) {
    void* temp_r3;

    temp_r3 = fn_8023A0F0();
    if (temp_r3 != 0) {
        return (char*)temp_r3 + 0x10;
    }
    return 0;
}
