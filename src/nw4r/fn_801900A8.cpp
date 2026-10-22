#pragma force_active on
extern "C" void fn_8018CD30(void* p, unsigned int arg1);
extern "C" void fn_8018CC6C(void* p, unsigned int arg1, unsigned int arg2);

extern "C" void fn_801900A8(void** arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    char* p = *(char**)arg0;
    p += arg1 * 0x14;
    char* base = p + 0x20;
    
    fn_8018CD30(base, 0xF);
    
    fn_8018CC6C(base + 5, (unsigned int)(arg2 | (arg3 << 2) | ((arg1 * 2 + 0xF6) << 24)), 0xFF00000F);
    fn_8018CD30(base + 0xA, 0xF);
    fn_8018CC6C(base + 0xF, (unsigned int)(arg4 | (arg5 << 2) | ((arg1 * 2 + 0xF7) << 24)), 0xFF00000F);
}
