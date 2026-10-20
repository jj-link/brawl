#pragma force_active on
typedef signed short s16;

struct ShortValue {
    s16 value;
};

extern "C" void fn_27_338A40(ShortValue* dest, const ShortValue* src);
extern "C" void fn_27_338A4C(void* self, const ShortValue* value, void* arg);

extern "C" void fn_27_3388D8(void* self, void* arg, const s16* value) {
    ShortValue copied;
    ShortValue input;
    input.value = *value;
    fn_27_338A40(&copied, &input);

    ShortValue output;
    output.value = copied.value;
    fn_27_338A4C((char*)self + 8, &output, arg);
}
