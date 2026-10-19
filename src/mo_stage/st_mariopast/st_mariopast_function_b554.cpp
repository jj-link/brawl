#pragma force_active on
extern "C" int* fn_48_B554(int* object, int index)
{
    int offset = (object[2] >> 23) + index;
    if (offset >= 0xCD) {
        offset -= 0xCD;
    }
    return (int*)((char*)object + offset * 0x38 + 0x0C);
}
