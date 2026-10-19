#pragma force_active on
extern "C" {
void* __dt__16acCmdInterpreterFv(void*, short);

void* fn_91_622C(void* object, short deleting) {
    if (object != 0) {
        __dt__16acCmdInterpreterFv(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
