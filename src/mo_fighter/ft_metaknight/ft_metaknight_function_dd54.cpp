#pragma force_active on
extern "C" const unsigned char lbl_111_data_5F58[0x40];

extern "C" void* fn_111_DD54(void* object) {
    *static_cast<const unsigned char**>(object) = lbl_111_data_5F58;
    return object;
}
