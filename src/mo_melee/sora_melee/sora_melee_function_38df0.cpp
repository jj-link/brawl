#pragma force_active on
struct SoraEntryTable {
    unsigned int data[3];
};

extern "C" void *fn_27_38DF0(SoraEntryTable *table, int index)
{
    int offset = (int)table->data[2] >> 28;
    int adjusted = offset + index;
    if (adjusted >= 7)
        adjusted -= 7;
    return (char *)table + adjusted * 8 + 12;
}
