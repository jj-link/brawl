#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int : 4;
    unsigned int field : 4;
    unsigned int : 24;
};

extern "C" void fn_27_D2B38(Data* data, unsigned int value)
{
    data->field = value;
}
