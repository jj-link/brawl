#pragma force_active on
typedef int s32;

extern "C" void fn_27_10D948(void* self, s32 value)
{
    s32* field = (s32*)((char*)self + 0x70);
    if (value != *field) {
        *field = value;
    }
}
