#pragma force_active on
extern "C" {

int fn_801AAC9C(void* obj, int type, int enable);

int fn_801AB1FC(void* obj, int type, int enable)
{
    switch (type) {
    case 0x10001:
        if (enable) {
            *(unsigned int*)((char*)obj + 0xcc) |= 0x60;
        } else {
            *(unsigned int*)((char*)obj + 0xcc) &= ~0x60u;
        }
        break;
    default:
        return fn_801AAC9C(obj, type, enable);
    }
    return 1;
}

}
