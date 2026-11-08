#pragma force_active on
struct Color3 { unsigned char r, g, b; };
extern "C" void fn_8015E100(unsigned char* arg0, const Color3* arg1) {
 unsigned char* p = *(unsigned char**)(arg0 + 0x14);
 *(Color3*)(p + 4) = *arg1;
}
