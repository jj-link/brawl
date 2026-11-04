#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
extern char lbl_1_data_62F8[];
extern "C" {
void fn_1_1EDE0(int* arg);
void __dt__14gfFileIOHandleFv(void*, int);
void* __nwa__FUlQ25Heaps8HeapType(u32, int);
void* __construct_new_array(void*, void*, void*, u32, u32);
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void*, const char*, int, int, int);
void* getGlobalRecordMenuDatap__10GameGlobalFv(void* global);
u32 getLanguage__10GameGlobalFv(void* self);
void fn_8004F300(char* buf, int idx);
char* strcat(char*, const char*);
extern void* g_GameGlobal;
}
extern "C" void fn_1_1E92C(void* self) {
    char* data = lbl_1_data_62F8;
    char path[0x40] = "movie/param/";
    char name[0x20];
    char ext[8] = ".pac";

    *(void**)((char*)self + 0x40) = __construct_new_array(
        __nwa__FUlQ25Heaps8HeapType(0x1C, 0x2A),
        (void*)&fn_1_1EDE0, (void*)&__dt__14gfFileIOHandleFv, 4, 3);

    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(
        *(void**)((char*)self + 0x40), data + 0x78, 0x2B, 0, 0);

    u8 flag = *(u8*)((char*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal) + 0x28);
    if (((flag >> 7) & 1) == 0) {
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(
            *(char**)((char*)self + 0x40) + 4, data + 0x94, 0x2B, 0, 0);
    } else {
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(
            *(char**)((char*)self + 0x40) + 4, data + 0xB8, 0x2B, 0, 0);
    }

    fn_8004F300(name, *(int*)((char*)self + 8));

    if (getLanguage__10GameGlobalFv(g_GameGlobal) == 0) {
        strcat(path, data + 0xE0);
    } else {
        strcat(path, data + 0xE4);
    }
    strcat(path, name);
    strcat(path, ext);

    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(
        *(char**)((char*)self + 0x40) + 8, path, 0x2B, 0, 0);
}
