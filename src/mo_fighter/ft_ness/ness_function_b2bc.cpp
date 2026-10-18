#pragma force_active on
extern const unsigned int lbl_101_data_3D20[];

// Installs the article's command descriptor: stores the descriptor vtable
// (data+0x3D20), the owning command block and the two shared callback lists.
extern "C" void fn_101_B2BC(unsigned int* storage, unsigned int* owner,
                            unsigned int* vtable, unsigned int* arg3)
{
    storage[0] = reinterpret_cast<unsigned int>(&lbl_101_data_3D20[0]);
    storage[4] = reinterpret_cast<unsigned int>(owner);
    storage[5] = reinterpret_cast<unsigned int>(vtable);
    storage[6] = reinterpret_cast<unsigned int>(arg3);
}
