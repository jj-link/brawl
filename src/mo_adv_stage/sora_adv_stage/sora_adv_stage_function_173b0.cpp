#pragma force_active on
extern "C" void fn_40_16854(unsigned char* self);
extern "C" void fn_40_168F0(unsigned char* self);
extern "C" void fn_40_16D8C(unsigned char* self);

extern "C" void fn_40_173B0(unsigned char* self)
{
    fn_40_16854(self + 0x40);
    fn_40_168F0(self + 0x9c);
    fn_40_16D8C(self + 0xa4);
}
