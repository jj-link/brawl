#pragma force_active on
extern "C" void fn_8015BFB4(void*, void*);

extern "C" void fn_27_C16BC(unsigned char* self, unsigned char* obj, int idx) {
    fn_8015BFB4(self + idx * 12 + 0x70, obj);
    if (!(*(unsigned int*)(self + 0xa0) & 1)) {
        obj[0x19] = 3;
    } else {
        obj[0x19] = 1;
    }
    *(unsigned int*)(self + 0xa0) += 1;
}
