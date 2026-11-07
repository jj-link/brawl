#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on
extern "C" { extern const float lbl_123_rodata_50; extern const float lbl_123_rodata_54; }
inline float product(float a, float b) { return a * b; }
extern "C" void fn_123_1040C(void* self, soModuleAccesser* accesser, int kind) {
if (kind == 0x11e) {
soWorkManageModule& work = accesser->getWorkManageModule();
float divisor = soValueAccesser::getConstantFloat(accesser, 0xfd8, 0);
float ratio = work.getFloat(0x21000004) / divisor;
if (ratio < lbl_123_rodata_50) ratio = lbl_123_rodata_50;
else if (ratio > lbl_123_rodata_54) ratio = lbl_123_rodata_54;
divisor = static_cast<float>(soValueAccesser::getConstantInt(accesser, 0x5dc7, 0));
float value = product(soValueAccesser::getConstantFloat(accesser, 0xfdf, 0) * ratio, divisor);
if (value < static_cast<float>(soValueAccesser::getConstantInt(accesser, 0x5dc6, 0))) value = static_cast<float>(soValueAccesser::getConstantInt(accesser, 0x5dc6, 0));
accesser->getWorkManageModule().setInt(static_cast<int>(value), 0x20000002);
}}