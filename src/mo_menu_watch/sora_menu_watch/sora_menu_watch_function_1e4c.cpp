#pragma force_active on
extern "C" {
int exchangeSrStageKindToMuStageKind__6muMenuFiii(unsigned int);
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(unsigned int);
int fn_15_1F58(void*, void*);
int fn_15_1F68(void*, void*);
void fn_803F8ACC(void*, unsigned int, unsigned int, int (*)(void*, void*));
}

extern "C" void fn_15_1E4C(void* self) {
    unsigned char* object = (unsigned char*)self;
    if (object[0xD59] == 0) {
        unsigned char* menuData = (unsigned char*)*(void**)(object + 0xD5C);
        unsigned char* stageData = menuData + 0x35C;
        if (menuData[0x386] == 1)
            *(unsigned int*)(object + 0x490) = 1;
        else
            *(unsigned int*)(object + 0x490) = 0;
        *(unsigned int*)(object + 0x494) =
            exchangeSrStageKindToMuStageKind__6muMenuFiii(
                *(unsigned short*)(stageData + 2));

        unsigned char* entry;
        unsigned char* output;
        int i;
        int count;
        output = object + 0x49C;
        count = 0;
        i = 0;
        while (i < 4) {
            entry = stageData + i;
            if (entry[0x19] != 3) {
                output[0] = (unsigned char)i;
                *(unsigned int*)(output + 4) =
                    exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(entry[4]);
                ++count;
                output[8] = entry[0x0B];
                *(unsigned int*)(output + 0x0C) = entry[0x12];
                output[0x10] = entry[0x20];
                output += 0x14;
            }
            ++i;
        }

        object[0x498] = (unsigned char)count;
        if (*(int*)(object + 0x490) == 1)
            fn_803F8ACC(object + 0x49C, count, 0x14, fn_15_1F58);
        else
            fn_803F8ACC(object + 0x49C, count, 0x14, fn_15_1F68);
    }
}
