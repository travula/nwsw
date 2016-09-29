/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 19302 2010-08-13 12:19:42Z dts12 $
 */
#ifndef COMPONENTSTATUS_H
#define COMPONENTSTATUS_H

/* function declarations */
void init_componentStatus(void);
void initialize_table_componentStatusTable(void);

/* column number definitions for table componentStatusTable */
       #define COLUMN_COMPONENT_STATUS_INDEX		1
       #define COLUMN_COMPONENTTYPE		2
       #define COLUMN_COMPONENTVERSION		3
       #define COLUMN_COMPONENTINSTANCE		4
       #define COLUMN_COMPONENTOPERATIONALSTATE		5
       #define COLUMN_INFOSTRING		6
       #define COLUMN_ERRORSTRING		7

#define COMPONENT_STATUS_MAX_COL	COLUMN_ERRORSTRING
#define COMPONENT_STATUS_VERSION_BUFFER_LEN_MAX   20
#define COMPONENT_STATUS_INFO_BUFFER_LEN_MAX   33
#define COMPONENT_STATUS_ERROR_BUFFER_LEN_MAX   33

    /* Typical data structure for a row entry */
struct componentStatusTable_entry {
    /* Index values */
    unsigned int index;

    /* Column values */
    unsigned int componentType;
    char componentVersion[COMPONENT_STATUS_VERSION_BUFFER_LEN_MAX];
    size_t componentVersion_len;
    unsigned char componentInstance;
    unsigned int  componentOperationalState;
    char infoString[COMPONENT_STATUS_INFO_BUFFER_LEN_MAX];
    size_t infoString_len;
    char errorString[COMPONENT_STATUS_ERROR_BUFFER_LEN_MAX];
    size_t errorString_len;

    /* Illustrate using a simple linked list */
    int   valid;
    struct componentStatusTable_entry *next;
};

#endif /* COMPONENTSTATUS_H */