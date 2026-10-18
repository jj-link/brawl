#pragma force_active on
extern "C" void fn_114_15CB4(void* obj, unsigned int value) {
    unsigned int* p = static_cast<unsigned int*>(obj);
    p[4] = value;
    p[3] = value;
    p[2] = value;
}
