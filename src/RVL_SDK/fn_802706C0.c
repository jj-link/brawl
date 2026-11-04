#pragma force_active on
typedef struct {
    unsigned char padding[0x24];
    int value;
} Object;

void fn_802706C0(Object *object, int value)
{
    object->value = value;
}
