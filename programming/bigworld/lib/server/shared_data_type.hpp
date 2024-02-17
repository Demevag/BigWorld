#ifndef SHARED_DATA_TYPE_HPP
#define SHARED_DATA_TYPE_HPP

BW_BEGIN_NAMESPACE

typedef uint8        SharedDataType;
const SharedDataType SHARED_DATA_TYPE_CELL_APP             = 1;
const SharedDataType SHARED_DATA_TYPE_BASE_APP             = 2;
const SharedDataType SHARED_DATA_TYPE_GLOBAL               = 3;
const SharedDataType SHARED_DATA_TYPE_GLOBAL_FROM_BASE_APP = 4;

BW_END_NAMESPACE

#endif // SHARED_DATA_TYPE_HPP
