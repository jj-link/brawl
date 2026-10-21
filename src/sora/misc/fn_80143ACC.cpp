#pragma force_active on
extern "C" char lbl_8045F1BC[];
extern "C" int lbl_805A03A8;

extern "C" void fn_80143ACC(void* arg0) {
    unsigned int* p = (unsigned int*)arg0;
    p[1] = 0;
    *(void**)p = lbl_8045F1BC;
    p[0x11F7] = 0;
    lbl_805A03A8 = (int)(unsigned int)arg0;
    p[0x8] = 0;
    p[0x9] = 0;
    p[0xA] = 0;
    p[0xB] = 0;
    ((unsigned char*)arg0)[0x3C] = 0;
}
