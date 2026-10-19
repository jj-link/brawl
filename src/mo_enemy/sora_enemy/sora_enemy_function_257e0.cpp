#pragma force_active on
typedef unsigned char u8;
typedef int s32;
struct soModuleAccesser;

extern "C" void fn_41_25524(void* out, soModuleAccesser* acc, s32 p2, s32 flag);
extern "C" int fn_41_247FC(char* self, void* input);
extern "C" void fn_41_24A48(char* self, s32 p2, s32 p3);

extern "C" {
void fn_41_257E0(soModuleAccesser* acc, s32 p2, s32 p3) {
    u8 buf[8];
    fn_41_25524(buf, acc, p2, 1);
    s32 r = fn_41_247FC((char*)acc, buf);
    fn_41_24A48((char*)acc, r, p3);
}
}
