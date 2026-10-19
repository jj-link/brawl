#pragma force_active on
typedef unsigned int u32;

struct FtRobotTable {
    char pad[0xc];
    void **table;
};

extern "C" {
void *fn_120_9BA4(FtRobotTable *self, u32 index)
{
    return self->table[index];
}
}
