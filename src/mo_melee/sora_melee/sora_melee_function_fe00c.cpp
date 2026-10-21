#pragma force_active on
struct Data {
    unsigned int first;
    unsigned int second;
    short third;
    short fourth;
};

extern "C" void fn_27_FE00C(Data* dest, const unsigned int* first,
                           unsigned int second, const short* third, short fourth)
{
    dest->first = *first;
    dest->second = second;
    dest->third = *third;
    dest->fourth = fourth;
}
