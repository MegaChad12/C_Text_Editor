#ifndef Types
#define Types
#define BufferSize 256
#define ReaderBuffer 1024
#define UwUTime 3

typedef enum CommandTypes{
    UwU,
    Read,
    Write,
    Append,
    Exit,
    Remove,
    Timer,
    None,
} CommandTypes;


#endif
