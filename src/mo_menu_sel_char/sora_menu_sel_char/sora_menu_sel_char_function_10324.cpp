#pragma force_active on
extern "C" {
void fn_10_10324(void* self);
int printf__5MuMsgFUlPCce(unsigned int, unsigned int, const char*, ...);
extern const char lbl_10_data_730[];
}

void fn_10_10324(void* self) {
    int i = 0;
    do {
        printf__5MuMsgFUlPCce(
            *(unsigned int*)((char*)self + 0x5C4),
            i + 2,
            lbl_10_data_730
        );
        ++i;
    } while (i < 5);
}
