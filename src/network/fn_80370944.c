#include <string.h>
#pragma force_active on

typedef struct Inner {
    char* unk0;
    unsigned int unk4;
    char* unk8;
} Inner;

typedef struct Arg2 {
    unsigned char pad[0xC];
    Inner* unkC;
} Arg2;

typedef struct Arg3 {
    char* unk0;
    char* unk4;
    void** unk8;
    int unkC;
} Arg3;

int fn_80370944(void* arg1, Arg2* arg2, Arg3* arg3) {
    Inner* n = arg2->unkC;
    if (n != NULL && strcmp(arg3->unk0, n->unk0) == 0 && strcmp(arg3->unk4, n->unk8) == 0) {
        *arg3->unk8 = arg2;
        arg3->unkC = 1;
        return 0;
    }
    return 1;
}
