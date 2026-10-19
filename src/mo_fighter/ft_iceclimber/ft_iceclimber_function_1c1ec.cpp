#pragma force_active on
typedef short s16;

extern "C" {
s16* fn_105_1C354(s16* destination, const s16* source);
s16* fn_105_1C448(s16* destination, const s16* source);
void fn_105_1C3B0(unsigned char* object, s16* index, void* argument);
}

extern "C" void fn_105_1C1EC(unsigned char* object, void* argument, const s16* index) {
    s16 second;
    s16 value = *index;
    s16 first;

    fn_105_1C354(&second, &value);
    fn_105_1C448(&first, &second);
    fn_105_1C3B0(object + 8, &first, argument);
}
