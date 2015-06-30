#ifndef DECOMPRESSION_H
#define DECOMPRESSION_H

#include "base.h"
#include "model.h"
#include "data_io.h"

#include <fstream>
#include <string>
#include <memory>
#include <vector>

namespace db_compress {

class Decompressor {
  private:
    ByteReader byte_reader_;
    size_t implicit_length_;
    Schema schema_;
    std::vector< std::unique_ptr<Model> > model_;
    std::vector<size_t> attr_order_;
  public:
    Decompressor(const char* compressedFileName, const Schema& schema);
    void Init();
    void ReadNextTuple(Tuple* tuple);
    bool HasNext() const;
};

}  // namespace db_compress

#endif
