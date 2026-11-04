#include <string.h>
#pragma force_active on
extern void *lbl_8059EE5C;
extern void *fn_80204E5C(void *, int);
typedef struct Input {
    char pad[12]; char *data; char pad2[24]; int size;
} Input;
typedef struct Object {
    char pad[4]; Input *input; int count; int total; char pad2[0x88];
    int flags[4]; char *first; char *second;
} Object;
void fn_802706C8(Object *obj)
{
    char *str = obj->input->data;
    char *end = str + obj->input->size;
    char *p = str;
    int len = 0;
    int len2;
    int i, count;
    char c;
    while ((c = *p) != 0) {
        if (c == ',') break;
        len++;
        p++;
    }
    obj->first = fn_80204E5C(lbl_8059EE5C, len + 1);
    strncpy(obj->first, str, len);
    obj->first[len] = 0;
    str += len + 1;
    len2 = 0;
    p = str;
    while ((c = *p) != 0) {
        if (c == ',') break;
        len2++;
        p++;
    }
    obj->second = fn_80204E5C(lbl_8059EE5C, len2 + 1);
    strncpy(obj->second, str, len2);
    obj->second[len2] = 0;
    str += len2;
    i = 0;
    count = 0;
    while (str[i] && str + i < end) {
        if (str[i] == ',') {
            if ((int)(unsigned char)str[i + 1] == '1') obj->flags[count] = 1;
            else obj->flags[count] = 0;
            count++;
        }
        i++;
    }
    obj->count = count;
    obj->total = count * 3;
}