/*Copyright (C) Kristian Hart 2009*/
typedef struct
{
    unsigned short version_id; //allow for reading different versions of the filesystem
    unsigned short system_id;//id that an operating system can use to know what os the filesystem originated on
    unsigned short m_ownerid;//the id of the person who is admin of the filesystem
    unsigned short sector_size;// size of a sector in bytes
    unsigned short  blocksize;//the size of a block in the fs in number of sectors
    unsigned int   blocksections;//number of block sections
    unsigned int   num_file_entry_sectors;
    unsigned int   num_dir_struct_entry_sectors;
    unsigned int   num_free_block_sectors;
    unsigned int   num_sec;//number of sectors in the last blocksection
}FS_DESCRIPTOR;//structure that defines a filesystems characteristics

typedef struct
{
    unsigned int idbase;//directory id base
    unsigned int idcalc;// a number to multiply the idbase by to get the actual id(usually 1 on small trees)
    unsigned int parent_idbase;
    unsigned int parent_idcalc;
    char         name[20];
}DS_ENTRY;//defines an entry in the directory tree

typedef struct
{
    unsigned int blocksection;
    unsigned int blockstart;// start block
    unsigned int blocks;//consecutive blocks in the block area
}BLOCK_ARRAY_ENTRY;//enty in a list of blocks

typedef struct
{
    char name[20];
    unsigned int owner_idbase;
    unsigned int owner_idcalc;  
    unsigned char system;//bits the system uses for characteristics
    unsigned int parent_idbase;//id base of the parent folder
    unsigned int parent_idcalc;//id calc of the parent folder
    unsigned int date;//last date edited in seconds past since (12PM Jan 1 2000)
    unsigned int num_barray_blks;// number of block entry array blocks (they are always consecutive)
    unsigned int blocksection;//the blocksection the array is in
    unsigned int blockstart;//first block in the array
}FD_ENTRY;//file descriptor entry

typedef struct
{
    unsigned int blocksection;
    unsigned int blockstart;// start block
    unsigned int blocks;//consecutive blocks in the array entry

}FREE_BLOCKS_ENTRY;
