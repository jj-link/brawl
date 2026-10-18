#pragma force_active on
extern "C" void fn_113_CDC4(void *object, void *value, unsigned int index) {
    ((void **)(*(void ***)((char *)object + 0xC)))[index] = value;
}
