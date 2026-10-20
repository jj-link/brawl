#pragma force_active on
class StageObject;

extern "C" void* fn_110_1EF78(StageObject* object) {
    unsigned char* parameters = *reinterpret_cast<unsigned char**>(
        reinterpret_cast<unsigned char*>(object) + 0xB24C);
    return parameters + 0x7C;
}
