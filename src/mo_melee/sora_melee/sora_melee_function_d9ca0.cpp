#pragma force_active on
extern "C" void *fn_27_D9CA0(void *arg0, int arg1)
{
    int index = (*reinterpret_cast<int *>(static_cast<char *>(arg0) + 8) >> 29) + arg1;
    if (index >= 2)
        index -= 2;
    return static_cast<char *>(arg0) + index * 8 + 12;
}
