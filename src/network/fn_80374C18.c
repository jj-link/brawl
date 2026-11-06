#pragma force_active on
typedef struct {
    unsigned char padding[0x30];
    int value;
} Object;

void fn_80374C18(Object* object, int value) {
    object->value = value;
}
