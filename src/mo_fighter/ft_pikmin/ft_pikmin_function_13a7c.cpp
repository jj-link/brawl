#pragma force_active on
extern "C" char* fn_113_13A7C(char* self, int index)
{
    int i = (*(int*)(self + 8) >> 27) + index;
    if (i >= 10) {
        i -= 10;
    }
    return self + i * 8 + 12;
}
