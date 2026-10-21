#pragma force_active on
extern "C" int OSReport(const char* fmt, ...);
extern "C" unsigned char lbl_80454B00[0xd];

extern "C" void fn_8009BA2C(int x)
{
    OSReport((const char*)lbl_80454B00, x);
}
