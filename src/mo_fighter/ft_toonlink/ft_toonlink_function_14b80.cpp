#pragma force_active on
extern "C" {
extern const unsigned char lbl_121_data_7C34[];
extern const unsigned char lbl_121_data_3CF0[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1DA698(void*, int, int, int);

void fn_121_14B80(void*, void* accesser) {
    void* object = __dynamic_cast(
        *(void**)((char*)accesser + 8),
        0x3c,
        lbl_121_data_7C34,
        lbl_121_data_3CF0,
        short(1)
    );
    fn_27_1DA698(object, -1, -1, -1);
}
}
