#include <stddef.h>
#pragma force_active on

extern "C" void fn_100_99FC(void* self, void* value, int index)
{
    // Loads the table pointer at offset 0xc, then writes value into entry [index].
    void** table = *reinterpret_cast<void***>(static_cast<char*>(self) + 0xC);
    table[index] = value;
}
