#pragma force_active on
struct Record {
    unsigned char data[0x1c];
};

extern "C" void *fn_27_C9C50(Record *records, int index)
{
    return &records[index].data[0x0c];
}
