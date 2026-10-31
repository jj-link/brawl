#pragma force_active on
extern "C" {
void* fn_91_8CBC(void* object, int value);

void* fn_91_9450(void* object, int value) {
    switch (value) {
    case 0:
        return object;
    case 1:
        return static_cast<unsigned char*>(object) + 0x470;
    case 2:
        return fn_91_8CBC(object, value);
    default:
        return fn_91_8CBC(object, value);
    }
}
}
