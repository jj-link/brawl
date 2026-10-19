#pragma force_active on
extern "C" {
void fn_98_A2C8(void* ret, void* manager, int index);

void* fn_98_A274(void* manager, int index) {
    unsigned int bundle[3];
    fn_98_A2C8(bundle, manager, index);
    unsigned int* result = static_cast<unsigned int*>(manager);
    result[1] = bundle[0];
    result[2] = bundle[1];
    result[3] = bundle[2];
    return result + 1;
}
}
