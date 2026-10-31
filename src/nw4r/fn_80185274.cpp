#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_8015FCE0();

extern "C" void fn_80185274(u8* arg0, const u8* arg1, const u8* arg2) {
    arg0[0x18] = arg1[0];
    arg0[0x19] = arg1[1];
    arg0[0x1A] = arg1[2];
    arg0[0x1B] = arg1[3];
    arg0[0x1C] = arg2[0];
    arg0[0x1D] = arg2[1];
    arg0[0x1E] = arg2[2];
    arg0[0x1F] = arg2[3];
    fn_8015FCE0();
}
