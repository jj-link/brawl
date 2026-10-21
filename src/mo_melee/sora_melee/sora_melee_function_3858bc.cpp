#pragma force_active on
typedef signed short s16;

extern "C" void fn_27_385ADC(s16*, const s16*);
extern "C" void fn_27_38622C(char*, s16*, void*);
extern "C" void fn_27_386178(char*, s16*, void*);
extern "C" void fn_27_3860C4(char*, s16*, void*);
extern "C" void fn_27_386010(char*, s16*, void*);
extern "C" void fn_27_385F5C(char*, s16*, void*);
extern "C" void fn_27_385EA8(char*, s16*, void*);
extern "C" void fn_27_385DF4(char*, s16*, void*);
extern "C" void fn_27_385D40(char*, s16*, void*);

extern "C" void fn_27_3858BC(char* self, void* arg, const s16* src) {
    s16 result[2];
    s16 input[2];
    s16 v24[2];
    s16 v20[2];
    s16 v1C[2];
    s16 v18[2];
    s16 v14[2];
    s16 v10[2];
    s16 v0C[2];
    s16 v08[2];

    input[0] = *src;
    fn_27_385ADC(result, input);
    v08[0] = result[0];
    fn_27_38622C(self + 0x208, v08, arg);
    v24[0] = result[0];
    fn_27_386178(self + 0x1CC, v24, arg);
    v0C[0] = result[0];
    fn_27_3860C4(self + 0x180, v0C, arg);
    v20[0] = result[0];
    fn_27_386010(self + 0x138, v20, arg);
    v10[0] = result[0];
    fn_27_385F5C(self + 0xF0, v10, arg);
    v1C[0] = result[0];
    fn_27_385EA8(self + 0x98, v1C, arg);
    v14[0] = result[0];
    fn_27_385DF4(self + 0x64, v14, arg);
    v18[0] = result[0];
    fn_27_385D40(self + 8, v18, arg);
}
