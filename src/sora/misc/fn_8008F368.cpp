#pragma force_active on

extern "C" int fn_8008F368(char* self, int arg1)
{
    int count = *(int*)(self + 4);
    if (count > arg1) {
        int index = count - arg1 - 1;
        if (index < count) {
            return *(int*)((*(char***)self)[index] + 0x1A0);
        }
        return *(int*)((*(char***)self)[count - 1] + 0x1A0);
    }
    if (count > 0) {
        return *(int*)((*(char***)self)[0] + 0x1A0);
    }
    return *(int*)((*(char***)self)[count - 1] + 0x1A0);
}
