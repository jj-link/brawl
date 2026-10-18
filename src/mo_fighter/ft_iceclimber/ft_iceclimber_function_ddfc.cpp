#pragma force_active on
typedef struct Obj
{
    char pad[0xc];
    int *arr;
} Obj;

extern "C" void fn_105_DDFC(Obj *self, int value, unsigned int index)
{
    self->arr[index] -= value;
}
