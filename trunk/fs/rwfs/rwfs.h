/*Copyright (C) Kristian Hart 2009*/

typedef struct
{
    unsigned short version_id; //allow for reading different versions of the filesystem
    unsigned short system_id;//id that an operating system can use to know what os the filesystem originated on
    unsigned short m_ownerid;//the id of the person who is admin of the filesystem
    unsigned short sector_size;// size of a sector in bytes
    unsigned short  blocksize;//the size of a block in the fs in number of sectors
    unsigned int   blocksections;//number of block sections
    unsigned int   num_file_entry_blocks;
} rwfs_fs_descriptor;//structure that defines a filesystems characteristics

typedef struct
{
    unsigned int idbase;//directory id base
    unsigned int idcalc;// a number to multiply the idbase by to get the actual id(usually 1 on small trees)
    unsigned int parent_idbase;
    unsigned int parent_idcalc;
    char         name[20];
} rwfs_ds_dentry;//defines an entry in the directory tree

typedef struct
{
    unsigned int blocksection;
    unsigned int blockstart;// start block
    unsigned int blocks;//consecutive blocks in the array entry
} rwfs_block_array_entry;//enty in a list of blocks

typedef struct
{
    unsigned char system;//bits the system uses for characteristics
    char name[20];
    unsigned int parent_idbase;//id base of the parent folder
    unsigned int parent_idcalc;//id calc of the parent folder
    unsigned int num_barray_blks;// number of block entry array blocks (they are always consecutive)
    unsigned int blocksection;//the blocksection the array is in
    unsigned int blockstart;//first block in the array
} rwfs_fd_entry;//file descriptor entry