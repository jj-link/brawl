#pragma force_active on
extern "C" void fn_8015BFB4(void*, void*);

extern "C" void fn_27_C164C(char* self, char* node, int idx) {
    fn_8015BFB4(self + idx * 12 + 0x40, node);
    if ((*(unsigned int*)(self + 0xA0) & 1) == 0) {
        node[0x19] = 3;
    } else {
        node[0x19] = 1;
    }
    (*(unsigned int*)(self + 0xA0))++;
}
