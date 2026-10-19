#pragma force_active on
class StageObject;

extern "C" void* fn_96_AF98(StageObject* object) {
    unsigned char* parameters = *reinterpret_cast<unsigned char**>(
        reinterpret_cast<unsigned char*>(object) + 0x1B678);
    return parameters + 0x7C;
}
