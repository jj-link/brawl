#pragma force_active on
class StageObject;

extern "C" void* fn_110_8C60(StageObject* object) {
    unsigned char* parameters = *reinterpret_cast<unsigned char**>(
        reinterpret_cast<unsigned char*>(object) + 0xD2F8);
    return parameters + 0x7C;
}
