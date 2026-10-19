#pragma force_active on
extern "C" void fn_62_5510(void *object, unsigned int value1, unsigned int value2)
{
    unsigned char *bytes = (unsigned char *)object;
    *(unsigned int *)(bytes + 0x5ac) = value1;
    *(unsigned int *)(bytes + 0x5b4) = value2;
}
