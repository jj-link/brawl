#pragma force_active on
extern "C" int fn_101_19F7C(void* object, void*, int parameter, int index) {
    unsigned char* bytes = static_cast<unsigned char*>(object);
    unsigned int first = *reinterpret_cast<unsigned int*>(bytes + 0x14);
    unsigned int group = static_cast<unsigned int>(parameter) - first;
    int* values = *reinterpret_cast<int**>(bytes + group * sizeof(int*) + 0x30);
    return values[index];
}
