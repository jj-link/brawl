#pragma force_active on
extern "C" void fn_118_99DC(void* object, unsigned long id, int flag);

extern "C" void fn_118_9968(unsigned char* self) {
    void* obj = *reinterpret_cast<void**>(self + 0x60);
    fn_118_99DC(obj, 0x10000047, 1);
    fn_118_99DC(obj, 0x10000048, 1);
    fn_118_99DC(obj, 0x10000043, 1);
    fn_118_99DC(obj, 0x10000044, 1);
}
