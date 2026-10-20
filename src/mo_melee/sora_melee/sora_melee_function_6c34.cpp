#pragma force_active on
struct Pair {
    unsigned int first;
    unsigned int second;
};

extern "C" unsigned long long fn_27_6C34()
{
    Pair value = {0, 0};
    return *reinterpret_cast<unsigned long long*>(&value);
}
