#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_102_9420(void* out, void* a, void* b);

extern "C" void* fn_102_93CC(void* self, void* b) {
    u32 buf[3];
    fn_102_9420(buf, self, b);
    u32* p = (u32*)self;
    p[1] = buf[0];
    p[2] = buf[1];
    p[3] = buf[2];
    return &p[1];
}
