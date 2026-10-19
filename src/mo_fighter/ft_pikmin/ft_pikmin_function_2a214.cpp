#pragma force_active on
extern "C" void fn_113_2A37C(short* destination, const short* source);
extern "C" void fn_113_2A458(short* destination, const short* source);
extern "C" void fn_113_2A3C0(void* object, const short* source, void* argument);

extern "C" void fn_113_2A214(void* object, void* argument, const short* index) {
    short first;
    short value = *index;
    short second;
    fn_113_2A37C(&first, &value);
    fn_113_2A458(&second, &first);
    fn_113_2A3C0(static_cast<unsigned char*>(object) + 8, &second, argument);
}
