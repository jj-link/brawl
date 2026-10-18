#pragma force_active on
typedef unsigned char u8;

class soModuleAccesser;
extern "C" void fn_27_1603F4(const float* vector, void* state, soModuleAccesser* accesser);

extern "C" void fn_119_BDA0(void* object, const float* vector, soModuleAccesser* accesser) {
    fn_27_1603F4(vector, static_cast<u8*>(object) + 4, accesser);
}
