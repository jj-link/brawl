#pragma force_active on
extern "C" unsigned char fn_80185074(int arg0, unsigned int arg1)
{
    int offset = arg0 + ((arg1 >> 1) & 0x7FFFFFFC);
    offset += arg1 & 3;
    return *(unsigned char*)(offset + 0xD8);
}
