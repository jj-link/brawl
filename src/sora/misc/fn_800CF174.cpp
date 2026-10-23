#pragma force_active on
extern "C" {

void netReport__FPCce(const char* fmt, ...);

extern unsigned char lbl_804581A8[0x20];

void fn_800CF174(void* arg0, int arg1) {
    *(unsigned short*)((char*)arg0 + 0xFDA) = (unsigned short)(arg1 * 60);
    netReport__FPCce((const char*)lbl_804581A8, arg1);
}

}
