#include <string.h>
#pragma force_active on

typedef struct Allocator {
    void *(*alloc)(unsigned int);
    void (*free)(void *);
    unsigned char rest[0x170];
} Allocator;
extern Allocator lbl_80534638;

char *fn_8035D654(const char *str) {
    char *result;
    if (str == 0) return 0;
    result = lbl_80534638.alloc(strlen(str) + 1);
    if (result != 0) strcpy(result, str);
    return result;
}