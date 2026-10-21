#pragma force_active on
extern "C" void fn_8004E7FC(int* self)
{
    int* ptr = (int*)self[9];
    int* field = (int*)((char*)ptr + 0x268);
    *field |= 0x2;
}
