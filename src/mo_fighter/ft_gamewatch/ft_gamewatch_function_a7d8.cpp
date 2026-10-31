#pragma force_active on
extern "C" void* fn_107_A6EC(void* a, int b);

extern "C" void* fn_107_A7D8(void* obj, int index) {
    switch (index) {
        case 0:
            return obj;
        case 1:
            return (char*)obj + 0x4f0;
        case 2:
            return fn_107_A6EC(obj, index);
        default:
            return fn_107_A6EC(obj, index);
    }
}