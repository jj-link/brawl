#pragma force_active on
struct acCmdInterpreter {
    void interpretCmd(float f);
};

extern const float lbl_27_rodata_CC8;

extern "C" void fn_27_A0B0C(char* self) {
    ((acCmdInterpreter*)(self + 0xfc))->interpretCmd(lbl_27_rodata_CC8);
    if (*(int*)(self + 0x108) == 0) {
        *(int*)(self + 0x134) = 0;
    }
}
