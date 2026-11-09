#include <string.h>
#pragma force_active on

extern "C" void* fn_8016E658(void* data, const char* name)
{
    const char* end;
    int count;
    unsigned char* base = (unsigned char*)data + *(int*)data;
    int length = strlen(name);
    count = *(unsigned short*)(base + 4);
    end = name + length;
    unsigned char* p = base + 8;
    int i;
    for (i = 0; i < count; ++i) {
        int size = (p[0] << 8) + p[1];
        p += 2;
        const char* entry = (const char*)p;
        p += size;
        unsigned int offset = (p[3] + (p[2] << 8)) + ((p[0] << 24) + (p[1] << 16));
        p += 8;
        if (length + 1 == size && end[-1] == entry[size - 2] && strcmp(name, entry) == 0)
            return base + offset;
    }
    return 0;
}