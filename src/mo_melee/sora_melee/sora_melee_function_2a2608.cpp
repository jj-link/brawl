#pragma force_active on
extern "C" void fn_27_2A95B4();
extern "C" void fn_27_2A97A4(void*, int, int);

extern "C" void fn_27_2A2608(void* self) {
    *reinterpret_cast<unsigned char*>(static_cast<char*>(self) + 0xBC) = 0;
    fn_27_2A95B4();
    fn_27_2A97A4(self, 0, 1);
}
