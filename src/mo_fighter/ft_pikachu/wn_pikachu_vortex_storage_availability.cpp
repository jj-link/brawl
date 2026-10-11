extern "C" {
void* fn_98_19088(char*, int);
int fn_27_8D3E4(void*);

void fn_98_19004(char* owner) {
    for (int index = 0; index < 4; ++index) {
        char* element = static_cast<char*>(fn_98_19088(owner + 0xc, index));
        if (fn_27_8D3E4(element + 0x88) == 0) break;
    }
}
int fn_98_19064(void*) {
    return 1;
}
void fn_98_1906C(char* owner, unsigned char state) {
    owner[0x8630] = state;
}
}
