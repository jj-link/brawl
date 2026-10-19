#pragma force_active on
extern "C" unsigned char lbl_27_data_17D10[];

struct InitData
{
    unsigned int* data;
    unsigned int* dataEnd;
    unsigned int reserved;
    void* arg;
    unsigned int value0;
    unsigned int value1;
    unsigned char flag;
};

extern "C" void fn_27_C3418(InitData* self, void* arg)
{
    unsigned int* data = reinterpret_cast<unsigned int*>(lbl_27_data_17D10);

    self->data = data;
    self->dataEnd = data + 4;
    self->reserved = 0;
    self->arg = arg;
    self->value0 = 0;
    self->value1 = 0;
    self->flag = 0;
}
