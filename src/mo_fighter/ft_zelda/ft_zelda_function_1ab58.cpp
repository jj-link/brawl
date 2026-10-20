#pragma force_active on
class StageObject;

extern "C" void* fn_104_1AB58(StageObject* object) {
    unsigned char* parameters = *reinterpret_cast<unsigned char**>(
        reinterpret_cast<unsigned char*>(object) + 0x1FF74);
    return parameters + 0x7C;
}
