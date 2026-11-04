#pragma force_active on
struct Obj {
    char pad[0x1494];
    unsigned int flags;
};
extern "C" void fn_27_2A96F4(Obj *obj, int arg, int enable)
{
    if (enable) {
        switch (arg) {
        case 0: obj->flags |= 2; return;
        case 1: obj->flags |= 4; return;
        case 2: obj->flags |= 8; return;
        }
    } else {
        switch (arg) {
        case 0: obj->flags &= ~2; return;
        case 1: obj->flags &= ~4; return;
        case 2: obj->flags &= ~8; return;
        }
    }
}