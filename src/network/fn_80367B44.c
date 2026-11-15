#include <string.h>
#pragma force_active on
typedef struct { unsigned char *data; int length; } Obj;
int fn_80367B44(char *s, Obj *obj) {
    int i = 0;
    int len;
    char *p;
    if (s == 0) return 1;
    if (s[strlen(s)-1] == ':') return 0;
    p = strchr(s, ':');
    if (p == 0) p = s;
    len = obj->length;
    while (i < len && obj->data[i] != ':') i++;
    if (i == len) i = 0; else i = i + 1;
    if (strncmp(p, (char *)obj->data + i, len - i) == 0) return 1;
    return 0;
}
