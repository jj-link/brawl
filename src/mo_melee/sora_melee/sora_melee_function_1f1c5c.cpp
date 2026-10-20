#pragma force_active on
class IpHuman {
public:
    void setEnableRumble(bool state);
};

extern "C" void fn_27_207DC0(unsigned char* entry, int index, int arg, IpHuman* input, int zero);

extern "C" {
void fn_27_1F1C5C(unsigned char* self, int index, IpHuman* input, int arg) {
    int idx = index + 7;
    *(self + 0x84 + idx) = 1;
    *(unsigned int*)(self + 0x4c + idx * 4) = (unsigned int)input;
    fn_27_207DC0(*(unsigned char**)(self + 0xf8) + idx * 0x1c4, idx, arg, input, 0);
    if (input != 0) {
        input->setEnableRumble(false);
    }
}
}
