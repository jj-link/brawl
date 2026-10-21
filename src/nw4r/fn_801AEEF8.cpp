#pragma force_active on

extern "C" {

int fn_801AB1FC(void* obj, int a, int b);

int fn_801AEEF8(unsigned char* obj, int a, int b)
{
    switch (a) {
    case 0x20001:
        if (b) {
            *(unsigned int*)(obj + 0xcc) |= 0x100;
        } else {
            *(unsigned int*)(obj + 0xcc) &= ~0x100u;
        }
        break;
    default:
        return fn_801AB1FC(obj, a, b);
    }
    return 1;
}

}
