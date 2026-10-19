#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_27_12DCA8();

extern "C" void fn_97_A168(char* self) {
    fn_27_12DCA8();
    *(u8*)(self + 0x1CD45) = 0;
    *(u8*)(self + 0x1CD44) = 0;
}
