#pragma force_active on
// Ness helper: the argument points at a block whose first word must be
// reloaded with the address of the module's 0x40-byte data table held in
// .data.  Build that address relative to the .data base (lis/addi) and
// store it into the block's first word, then return to the caller.

struct NessDataTable { unsigned char* table; };

extern "C" {
extern const unsigned char lbl_101_data_9928[0x40];
}

extern "C" void fn_101_16644(NessDataTable* object) {
    object->table = const_cast<unsigned char*>(lbl_101_data_9928);
}