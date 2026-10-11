extern "C" {
bool fn_101_15F00(void*);
void* fn_101_15EA4(void*, short);
}

extern "C" bool fn_101_16304(void* object) {
    return fn_101_15F00(reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 4));
}
// The adjustor forwards the complete EABI flags word; the deleting entry
// interprets its low signed halfword. Do not introduce an argument extension.
extern "C" void* fn_101_1630C(void* object, unsigned int deleting) {
    typedef void* (*NessRawDeletingEntry)(void*, unsigned int);
    return reinterpret_cast<NessRawDeletingEntry>(fn_101_15EA4)(
        reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 4), deleting);
}
