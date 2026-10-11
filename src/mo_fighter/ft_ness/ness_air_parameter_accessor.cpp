class StageObject;

extern "C" void* fn_101_B640(StageObject* object) {
    unsigned char* parameters = *reinterpret_cast<unsigned char**>(
        reinterpret_cast<unsigned char*>(object) + 0x4AE20);
    return parameters + 0x7C;
}
