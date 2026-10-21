#pragma force_active on
extern "C" extern unsigned char lbl_804652E8[];

extern "C" void fn_8016B680(void* self)
{
    *(void**)((char*)self + 0x1c) = (void*)&(lbl_804652E8[0]);
}
