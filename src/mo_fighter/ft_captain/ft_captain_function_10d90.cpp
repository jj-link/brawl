#pragma force_active on
extern "C" void fn_100_10D90(void* destination, unsigned int first, unsigned int second)
{
    unsigned int* words = static_cast<unsigned int*>(destination);
    words[0] = first;
    words[1] = second;
}
