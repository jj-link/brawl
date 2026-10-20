#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} fnFlagsObject;

extern "C" void fn_27_1A6CA4(fnFlagsObject *obj) {
    obj->flags &= ~0x2u;
}
