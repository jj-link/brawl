#pragma force_active on
// The process object references the module's existing 0x40-byte data block.
extern "C" unsigned char lbl_101_data_AFA8[];

#pragma dont_inline on
extern "C" void fn_101_1CA04(void* object) {
    *reinterpret_cast<unsigned char**>(object) = lbl_101_data_AFA8;
}
#pragma dont_inline reset