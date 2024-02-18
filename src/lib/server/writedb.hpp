#ifndef SERVER_WRITEDB_HPP
#define SERVER_WRITEDB_HPP

BW_BEGIN_NAMESPACE

// flags for a writeToDB operation
enum WriteDBFlag
{
    WRITE_LOG_OFF             = 1,
    WRITE_EXPLICIT            = 2,
    WRITE_BASE_DATA           = 4,
    WRITE_CELL_DATA           = 8,
    WRITE_BASE_CELL_DATA      = WRITE_BASE_DATA | WRITE_CELL_DATA,
    WRITE_DELETE_FROM_DB      = 16,
    WRITE_AUTO_LOAD_YES       = 32,
    WRITE_AUTO_LOAD_NO        = 64,
    WRITE_AUTO_LOAD_MASK      = WRITE_AUTO_LOAD_YES | WRITE_AUTO_LOAD_NO,
    WRITE_TO_PRIMARY_DATABASE = 128,
    WRITE_EXPLICIT_DBID       = 256
};

typedef uint16 WriteDBFlags;

BW_END_NAMESPACE

#endif // SERVER_WRITEDB_HPP
