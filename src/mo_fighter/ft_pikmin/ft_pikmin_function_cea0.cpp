#pragma force_active on
extern "C" void fn_113_CEF4(void*, void*, void*);

extern "C" void* fn_113_CEA0(void* object, void* argument) {
    unsigned int tmp[3];

    fn_113_CEF4(tmp, object, argument);

    unsigned int* fields = static_cast<unsigned int*>(object);
    fields[1] = tmp[0];
    fields[2] = tmp[1];
    fields[3] = tmp[2];

    return &fields[1];
}
