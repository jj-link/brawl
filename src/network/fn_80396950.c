#include <revolution/NHTTP/d_nhttp.h>
#pragma force_active on

extern void *fn_803974FC(void);
extern void *fn_80397580(void *);
extern void *fn_803970D4(void *, NHTTPResponseHandle);
extern int fn_803960EC(void *, char **, int *);

int NHTTPGetBodyAll(NHTTPResponseHandle response, char **body) {
    int length;
    void *context;
    void *entry;

    context = fn_80397580(fn_803974FC());
    entry = fn_803970D4(context, response);
    if (entry != 0) {
        length = 0;
        return fn_803960EC(entry, body, &length);
    }
    return -1;
}