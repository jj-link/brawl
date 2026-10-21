#pragma force_active on
extern unsigned char lbl_804A7F40[];

extern "C" void* fn_801A1084(void)
{
    unsigned char* base = lbl_804A7F40;
    unsigned short idx = *reinterpret_cast<unsigned short*>(base + 2);
    return base + idx * 0x30 + 0x34;
}
