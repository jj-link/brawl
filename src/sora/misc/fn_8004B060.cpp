#pragma force_active on
extern "C" {

extern int lbl_8059C800;
void* memset(void* s, int c, unsigned long n);

void fn_8004B060(void* arg0, int arg1) {
    char* base = (char*)arg0;
    char* obj = (char*)*(void**)(base + 0x24);
    
    memset(obj, 0, 0x388);
    
    *(int*)(obj + 0) = lbl_8059C800;
    *(int*)(obj + 0x10) = 0;
    *(short*)(obj + 6) = 0;
    *(short*)(obj + 8) = 0;
    *(short*)(obj + 0xa) = 0;
    *(short*)(obj + 0xc) = 0;
    *(short*)(obj + 0xe) = 0;
    
    *(char*)(base + 0x3b) = 0;
    *(char*)(base + 0x3a) = 0;
    *(int*)(base + 0) = 0;
    *(int*)(base + 0x3c) = 0;
    *(int*)(base + 0x40) = 0;
    *(char*)(base + 0x49) = (char)arg1;
}
}
