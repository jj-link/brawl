#pragma force_active on
extern "C" int* fn_56_63BC(int* object, int index)
{
    int slot = (object[2] >> 30) + index;

    if (slot >= 1)
        slot -= 1;

    return reinterpret_cast<int*>(reinterpret_cast<char*>(object) + slot * 160 + 12);
}
