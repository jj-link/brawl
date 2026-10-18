#pragma force_active on
extern "C" {
void fn_123_17980(short*, const short*);
void fn_123_17AEC(short*, const short*);
void fn_123_17A54(void*, const short*, void*);
void fn_123_179A4(void*, const short*, void*);
}

extern "C" void fn_123_177FC(void* object, void* argument, const short* index) {
    unsigned char* self = static_cast<unsigned char*>(object);
    short converted;
    short value = *index;
    short third;
    short first;

    fn_123_17980(&converted, &value);
    fn_123_17AEC(&first, &converted);
    fn_123_17A54(self + 0x48, &first, argument);
    fn_123_17AEC(&third, &converted);
    fn_123_179A4(self + 8, &third, argument);
}
