#pragma force_active on
extern "C" void fn_98_A118(char* self, int index)
{
    int* table = *(int**)(self + 0xc);
    table[index] = table[index] + 1;
}
