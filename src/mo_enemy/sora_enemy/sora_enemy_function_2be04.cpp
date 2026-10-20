#pragma force_active on
class Object {
    unsigned char data[0x24];

public:
    virtual ~Object();
};

extern Object* lbl_41_bss_1C8;

extern "C" void fn_41_2BE04() {
    if (lbl_41_bss_1C8) {
        delete lbl_41_bss_1C8;
        lbl_41_bss_1C8 = 0;
    }
}
