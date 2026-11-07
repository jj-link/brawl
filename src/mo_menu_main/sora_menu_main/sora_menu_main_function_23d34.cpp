#pragma force_active on
extern "C" {
struct PathBlob { char d[0x40]; };
struct ExtBlob { char d[8]; };
extern PathBlob lbl_2_rodata_AD8;
extern ExtBlob lbl_2_rodata_B18;
extern char lbl_2_data_2CB0[];
void fn_2_3BC(int* arg0);
void __dt__14gfFileIOHandleFv(void*, int);
void* __nwa__FUlQ25Heaps8HeapType(unsigned int, int);
void* __construct_new_array(void*, void*, void*, unsigned int, unsigned int);
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void*, const char*, int, int, int);
void* getGlobalRecordMenuDatap__10GameGlobalFv(void* global);
unsigned int getLanguage__10GameGlobalFv(void* self);
void fn_8004F300(char* buf, int idx);
char* strcat(char*, const char*);
extern void* g_GameGlobal;
}

extern "C" void fn_2_23D34(void* self) {
    char* data = lbl_2_data_2CB0;
    PathBlob path = lbl_2_rodata_AD8;
    char name[0x20];
    ExtBlob ext = lbl_2_rodata_B18;

    *(void**)((char*)self + 0x6ac) = __construct_new_array(
        __nwa__FUlQ25Heaps8HeapType(0x1C, 0x2A),
        (void*)&fn_2_3BC, (void*)&__dt__14gfFileIOHandleFv, 4, 3);

    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(
        *(void**)((char*)self + 0x6ac), data + 0x34, 0x2B, 0, 0);

    if (*(unsigned char*)((char*)self + 0x6aa)) {
        if ((((*(unsigned char*)((char*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal) + 0x28)) >> 7) & 1) == 0) {
            readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(
                *(char**)((char*)self + 0x6ac) + 4, data + 0x50, 0x2B, 0, 0);
        } else {
            readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(
                *(char**)((char*)self + 0x6ac) + 4, data + 0x74, 0x2B, 0, 0);
        }
    } else {
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(
            *(char**)((char*)self + 0x6ac) + 4, data + 0x74, 0x2B, 0, 0);
    }

    if (*(unsigned char*)((char*)self + 0x6aa)) {
        fn_8004F300(name, *(int*)((char*)self + 0x66c));
        if (getLanguage__10GameGlobalFv(g_GameGlobal) == 0) {
            strcat(path.d, data + 0x9C);
        } else {
            strcat(path.d, data + 0xA0);
        }
        strcat(path.d, name);
        strcat(path.d, ext.d);
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(
            *(char**)((char*)self + 0x6ac) + 8, path.d, 0x2B, 0, 0);
    }
}