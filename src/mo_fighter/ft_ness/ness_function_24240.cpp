#pragma force_active on
extern "C" unsigned char lbl_101_data_C200[];

// Stores the base of this module's 0x40-byte data block into the object's
// first word (virtual table / data pointer slot) and returns nothing.
extern "C" void fn_101_24240(void* object) {
    *reinterpret_cast<void**>(object) = const_cast<unsigned char*>(lbl_101_data_C200);
}