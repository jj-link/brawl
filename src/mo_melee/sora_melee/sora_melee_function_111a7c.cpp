#pragma force_active on
#pragma scheduling off

struct Data {
    unsigned char padding[0x38];
    unsigned int values[7];
};

extern "C" unsigned int fn_27_111A7C(Data** self) {
    Data* data = *self;
    unsigned int total = data->values[0];
    total += data->values[1];
    total += data->values[2];
    total += data->values[3];
    total += data->values[4];
    total += data->values[5];
    total += data->values[6];
    return total;
}
