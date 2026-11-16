#include <gf/gf_file_io.h>
#include <gf/gf_error_check.h>
#include <string.h>
#pragma force_active on

extern "C" {
int fn_8001B7F8(const char*);
int fn_8001C144(void*);
int fn_8001C5D4(void*);
int fn_8001C9EC(void*);
extern int lbl_8059FFD8;
}

struct S {
    const char* p;
    int a, b, c, d;
    unsigned r : 8;
    unsigned x : 8;
    unsigned y : 16;
};
struct B { unsigned char pad[0x15]; unsigned char x : 8; };

inline int readFileImpl(gfFileIORequest* request, int& fallback) {
    int type;
    char name[128];
    type = fn_8001B7F8(request->m_pFilepath);
    const char* s = request->m_pFilepath;
    fallback = lbl_8059FFD8;
    unsigned int n = strlen(s);
    const char* q = s;
    for (unsigned int i = 0; i < n; i++) {
        if (*q == ':') {
            strncpy(name, q + 1, 128);
            goto copied;
        }
        q++;
    }
    strncpy(name, s, 128);
copied:
    S local;
    ((int*)&local)[0] = ((int*)request)[0];
    ((int*)&local)[1] = ((int*)request)[1];
    ((int*)&local)[2] = ((int*)request)[2];
    ((int*)&local)[3] = ((int*)request)[3];
    ((int*)&local)[4] = ((int*)request)[4];
    ((int*)&local)[5] = ((int*)request)[5];
    local.p = name;
    int status = 2;
    switch (type) {
    case 0: status = 1; break;
    case 1: status = fn_8001C144(&local); break;
    case 2: status = fn_8001C5D4(&local); break;
    case 4:
        ((B*)&local)->x = ((const unsigned char*)request->m_pFilepath)[2] - '0';
        status = fn_8001C9EC(&local);
        break;
    case 3: status = gfFileIO::readSDFile((gfFileIORequest*)&local); break;
    }
    if (type == fallback) {
        if (type == 1) fallback = 0;
        else if (type == 0) fallback = 1;
    }
    if (status != 0) {
        switch (fallback) {
        case 0: status = 1; break;
        case 1: status = fn_8001C144(&local); break;
        case 2: status = fn_8001C5D4(&local); break;
        case 3: status = gfFileIO::readSDFile((gfFileIORequest*)&local); break;
        case 6: status = 2; break;
        }
    }
    if (status == 0) {
        ((int*)request)[2] = local.b;
        ((int*)request)[3] = local.c;
    } else if (status == 2) {
        gfErrorCheck::check();
    }
    request->m_returnStatus = status;
    return status;
}

int gfFileIO::readFile(gfFileIORequest* request) {
    int fallback;
    return readFileImpl(request, fallback);
}
