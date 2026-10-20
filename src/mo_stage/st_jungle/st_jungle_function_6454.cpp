#pragma force_active on
// st_jungle: fn_51_6454
// Clears the flag bits selected by rlwinm r0, r0, 0, 7, 5 (mask 0xFDFFFFFF)
// in the 32-bit word located at self + 8.
extern "C" void fn_51_6454(void* self)
{
    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(self) + 8) &= ~0x02000000;
}
