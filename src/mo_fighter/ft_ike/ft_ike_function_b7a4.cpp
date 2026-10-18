#pragma force_active on
struct Pair {
    unsigned long first;
    unsigned long second;
};

extern "C" Pair fn_119_B7A4(void* arg0, void* arg1)
{
    return *(Pair*)((char*)arg0 + 8);
}