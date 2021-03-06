#pragma once

#include "BitStream.h"
#include <vector>
#include <memory>

struct OggVorbis_File;

namespace dictlsd {

class OggReader {
    std::unique_ptr<OggVorbis_File> _vfile;
    int _vbitstream;
public:
    OggReader(IRandomAccessStream* bstr);
    // little endian signed mono
    void readSamples(unsigned count, std::vector<short>& vec);
    uint64_t totalSamples();
    ~OggReader();
};

}
