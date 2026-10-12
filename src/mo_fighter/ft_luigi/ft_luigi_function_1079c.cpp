// This base destructor has no members; a positive flag releases its storage.
extern "C" void* fn_99_1079C(void* object, short deleting) {
    if (object) {
        if (deleting > 0) operator delete(object);
    }
    return object;
}
