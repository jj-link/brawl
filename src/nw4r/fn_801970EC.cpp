#pragma force_active on
extern "C" void* fn_801970EC(void** pp, unsigned int index)
{
    char* base = (char*)(*pp);
    unsigned short count = *(unsigned short*)(base + 0x3C);
    if (count <= index)
        return 0;

    int offset = *(int*)(base + 0x1C);
    char* ptr;
    if (offset != 0)
        ptr = base + offset;
    else
        ptr = 0;

    ptr = ptr + index * 0x5C;
    unsigned int val = *(unsigned int*)(ptr + 0x0C);
    if (val < count)
        return ptr;
    return 0;
}
