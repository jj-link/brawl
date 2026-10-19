#pragma force_active on
extern "C" {
void fn_27_12DCA8(void* p);
}

extern "C" void fn_104_99D8(void* p)
{
    fn_27_12DCA8(p);
    *((unsigned char*)p + 0x20000 - 0x798B) = 0;
    *((unsigned char*)p + 0x20000 - 0x798C) = 0;
}
