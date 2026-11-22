#include <nw4r/snd/snd_SoundArchiveFile.h>
#pragma force_active on
using namespace nw4r::snd::detail;

inline const void* GetPtrConst(const void* pBase, u32 offset) {
    if (offset == 0) return 0;
    return nw4r::ut::AddOffsetToPtr(pBase, offset);
}

extern "C" void fn_801C71E0(SoundArchiveFileReader* self, const SoundArchiveFile::SymbolBlock* block)
{
    u32 v0 = block->stringBlock.stringChunk.tableOffset;
    const SoundArchiveFile::StringChunk* p = &block->stringBlock.stringChunk;
    self->mStringBase = p;
    const void* x = GetPtrConst(p, v0);
    u32 v;
    v = p->soundTreeOffset; self->mStringTable = (const SoundArchiveFile::StringTable*)x; x = GetPtrConst(self->mStringBase, v);
    v = p->playerTreeOffset; self->mStringTreeSound = (const SoundArchiveFile::StringTree*)x; x = GetPtrConst(self->mStringBase, v);
    v = p->groupTreeOffset; self->mStringTreePlayer = (const SoundArchiveFile::StringTree*)x; x = GetPtrConst(self->mStringBase, v);
    v = p->bankTreeOffset; self->mStringTreeGroup = (const SoundArchiveFile::StringTree*)x; x = GetPtrConst(self->mStringBase, v);
    self->mStringTreeBank = (const SoundArchiveFile::StringTree*)x;
}