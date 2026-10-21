#include <string.h>
#pragma force_active on

extern "C" {
void fn_800BF850(void* self, int id, const char* str, int len, int flag);

void fn_800BF928(void* self, const char* str) {
    fn_800BF850(self, 5, str, strlen(str), 1);
}
}
