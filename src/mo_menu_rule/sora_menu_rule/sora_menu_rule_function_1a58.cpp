#pragma force_active on
extern "C" {
void* getInstance__14gfSceneManagerFv();
void* __dynamic_cast(void*, long, unsigned long long, short);

extern unsigned char lbl_18_data_6D0[];
extern unsigned char lbl_18_data_700[];

unsigned int fn_18_1A58() {
    char* manager = (char*)getInstance__14gfSceneManagerFv();
    unsigned long long types =
        ((unsigned long long)(unsigned int)lbl_18_data_6D0 << 32) |
        (unsigned int)lbl_18_data_700;

    char* scene = (char*)__dynamic_cast(
        *(void**)(manager + 4), 4, types, 0
    );
    return *(unsigned int*)(scene + 0x3D8);
}
}
