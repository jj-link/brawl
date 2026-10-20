#pragma force_active on
extern "C" {
extern void* lbl_27_data_4EDD8;

void fn_27_24858C(char* self)
{
    *(void**)(self + 0xB4) = lbl_27_data_4EDD8;
    *(int*)(self + 0xB8) = 0;
    *(unsigned char*)(self + 0xBC) = 0;
}
}
