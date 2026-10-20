#pragma force_active on
struct Color {
    unsigned char r, g, b, a;
};

extern "C" void fn_27_9FCD4(void*, int, int, Color, int, int);

extern "C" void fn_27_9A1A4(
    void* self, int arg1, int arg2, const Color& color, int arg4, int arg5)
{
    fn_27_9FCD4(static_cast<char*>(self) + 0x124,
                arg1, arg2, color, arg4, arg5);
}
