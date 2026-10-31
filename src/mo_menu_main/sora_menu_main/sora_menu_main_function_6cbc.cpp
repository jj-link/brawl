#pragma force_active on
extern "C" {
extern const char lbl_2_data_D10[];
extern const char lbl_2_data_D1C[];
unsigned long getBilTexFileIdx__20tyFigListDataManagerFUl(void*, unsigned long);
void getBilTexName__20tyFigListDataManagerFUlPc(void*, unsigned long, char*);
void* fn_8018D3F0(void*, const char*);
void* GetResMat__Q34nw4r3g3d6ResMdlCFPCc(void*, const char*);
void fn_800B7224(void*, unsigned long, const char*, void*);
void OSReport(const char*, ...);
}
struct Data {
char pad[8];
unsigned long textures[69];
void* models[1];
};
struct Obj { char pad[64]; Data* data; };
static inline void impl(void* selfArg, void* manager, unsigned short* input, unsigned int countArg) {
char name[32];
int loaded = 0;
const char* material = lbl_2_data_D10;
unsigned int count = countArg;
Obj* self = (Obj*)selfArg;
unsigned long id;
unsigned long* tex;
int i = 0;
int offset = 0;
unsigned short* ids = input;
for(; i<(int)count; ++i) {
id = *ids;
unsigned long idx = getBilTexFileIdx__20tyFigListDataManagerFUl(manager,id);
tex = &self->data->textures[idx];
if (*tex) {
getBilTexName__20tyFigListDataManagerFUlPc(manager,id,name);
if(fn_8018D3F0(tex,name)) {
void* model = *(void**)((char*)self->data + 0x11c + offset);
void* mat = GetResMat__Q34nw4r3g3d6ResMdlCFPCc((char*)model+8,material);
fn_800B7224(model,*(unsigned long*)((char*)mat+12),name,tex);
++loaded;
}
}
++ids;
offset += 4;
}
OSReport(lbl_2_data_D1C,loaded);
}
extern "C" void fn_2_6CBC(void* self, void* manager, unsigned short* ids, int count) {
impl(self,manager,ids,count);
}
