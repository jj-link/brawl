#pragma force_active on
struct Fn115Object {
    char pad[0x31];
    unsigned char flag31;
};

extern "C" void fn_115_C974(Fn115Object* object) {
    object->flag31 = 1;
}
