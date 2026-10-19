#pragma force_active on
extern "C" {
extern unsigned char lbl_114_data_80E8[0x40];

void fn_114_10A54(void* object)
{
    *static_cast<void**>(object) = lbl_114_data_80E8;
}
}
