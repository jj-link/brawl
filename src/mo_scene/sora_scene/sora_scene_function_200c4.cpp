#pragma force_active on
extern "C" void fn_80073F84(void*, int);
extern void* g_sndSystem;

extern "C" void fn_1_200C4(void* self) {
    unsigned int* words = (unsigned int*)self;
    words[2] = 0;
    words[3] = 0;
    words[4] = 0;
    words[5] = 0;
    words[7] = 0;
    words[10] = 0;
    fn_80073F84(g_sndSystem, 0);
}
