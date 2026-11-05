#include <string.h>
#pragma force_active on

void fn_8020C7A0(char *head, char *tail, const char *src)
{
    unsigned int i;
    for (i = 0; i <= strlen(src); i++) {
        if (src[i] == '/') {
            strncpy(head, src, i);
            head[i] = '\0';
            if (src[i + 1] == '\0') {
                tail[0] = '\0';
                return;
            }
            strcpy(tail, src + i + 1);
            return;
        }
        if (src[i] == '\0') {
            strncpy(head, src, i);
            head[i] = '\0';
            tail[0] = '\0';
            return;
        }
    }
}
