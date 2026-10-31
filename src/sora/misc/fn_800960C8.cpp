#pragma force_active on

extern "C" void fn_80285A6C(void*, float*, void*, float, float, float, float);
extern "C" void fn_80283E28(int, void*);

struct Buffer {
    float args[4];
    float source[4];
    char output[0x30];
    float duplicate[4];
} __attribute__((aligned(16)));

extern "C" void fn_800960C8(int arg0, void** arg1) {
    Buffer buffer;
    float* object = (float*)*arg1;
    float source0 = object[0x38];
    float source1 = object[0x39];
    float source2 = object[0x3A];
    float source3 = object[0x3B];

    float argValue0 = object[0x48];
    buffer.source[0] = source0;
    buffer.args[0] = argValue0;
    float argValue1 = object[0x49];
    buffer.source[1] = source1;
    buffer.args[1] = argValue1;
    float argValue2 = object[0x4A];
    buffer.source[2] = source2;
    buffer.args[2] = argValue2;
    float argValue3 = object[0x4B];
    buffer.source[3] = source3;
    buffer.args[3] = argValue3;

    buffer.duplicate[0] = buffer.source[0];
    buffer.duplicate[1] = buffer.source[1];
    buffer.duplicate[2] = buffer.source[2];
    buffer.duplicate[3] = buffer.source[3];

    fn_80285A6C(buffer.output, buffer.args, object,
                buffer.source[3], buffer.source[2],
                buffer.source[1], buffer.source[0]);
    fn_80283E28(arg0, buffer.output);
}
