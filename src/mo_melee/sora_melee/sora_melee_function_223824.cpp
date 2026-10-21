#pragma force_active on

typedef unsigned long u32;

struct Data {
    u32 magic;
    u32 count;
};

struct Container {
    virtual ~Container();
    virtual void f1();
    virtual void f2();
    virtual void* get(u32);

    u32 pad;
    Data* data;
};

struct List {
    u32 a;
    u32 b;
};

struct Self {
    char pad[0xF8];
    List list;
    signed char flag;
};

extern "C" {
extern u32 g_BlocMagic;
extern char lbl_27_data_4A1BC[];

void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, unsigned short);
Container* create__20stDataMultiContainerFP19stDataContainerDataQ25Heaps8HeapType(void*, int);
Container* searchContainer__20stDataMultiContainerFUlUl(Container*, u32, u32);
void fn_27_2282B4(List*, void*);

void fn_27_223824(Self* self, void* archive, int id, signed char flag) {
    void* data = getData__9gfArchiveF11ARCNodeTypeiUs(archive, 1, id, 0xFFFE);
    if (data) {
        u32* magic;
        Container* multi =
            create__20stDataMultiContainerFP19stDataContainerDataQ25Heaps8HeapType(data, 15);
        if (g_BlocMagic == multi->data->magic) {
            Container* container;
            magic = (u32*)lbl_27_data_4A1BC;
            u32 index = 0;
            while ((container = searchContainer__20stDataMultiContainerFUlUl(
                        multi, *magic, index++)) != 0) {
                for (u32 i = 0; i < container->data->count; ++i) {
                    fn_27_2282B4(&self->list, container->get(i));
                }
            }
        }
        delete multi;
    }
    self->flag = flag;
}
}
