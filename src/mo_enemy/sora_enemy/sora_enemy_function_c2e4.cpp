#pragma force_active on
struct ParamTable
{
    int unk0[3];
    int* table;
};

extern "C" int fn_41_C2E4(const ParamTable* obj, int index)
{
    return obj->table[index];
}
