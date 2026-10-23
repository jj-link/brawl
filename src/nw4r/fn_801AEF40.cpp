extern "C" int fn_801AB244(void* self, int type, int* out);

#pragma force_active on

extern "C" int fn_801AEF40(void* self, int type, int* out)
{
    if (out == 0)
        return 0;

    switch (type) {
    case 0x20001:
        *out = (*(unsigned int*)((char*)self + 0xCC) >> 8) & 1;
        break;
    default:
        return fn_801AB244(self, type, out);
    }

    return 1;
}
