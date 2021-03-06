/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 19302 2010-08-13 12:19:42Z dts12 $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

#include "bs_modules.h"
#include "all_cfg.h"
#include "all_cmn.h"
#include "tlv_enc_dec.h"

#include "sih.h"
#include "syslog.h"
#include "moduleLogFileStatus.h"

/* function declarations */
Netsnmp_Node_Handler moduleLogFileStatusTable_handler;
Netsnmp_First_Data_Point  moduleLogFileStatusTable_get_first_data_point;
Netsnmp_Next_Data_Point   moduleLogFileStatusTable_get_next_data_point;

/* globals */
struct moduleLogFileStatusTable_entry  *moduleLogFileStatusTable_head = NULL;
static TBOOL g_sihModuleLogFileStatusGetReqProcessed = FALSE;
static UINT32 g_prevModuleLogFileStatusReqCount = 0;
static UINT32 g_moduleLogFileStatusFirstCall = 0;

/* free_moduleLogFileStatusTable */
/**
* @details 
*          This is the routine which frees the module log file status entry.
*/
void free_moduleLogFileStatusTable(void)
{
  moduleLogFileStatusTableEntry  * current = moduleLogFileStatusTable_head;
  moduleLogFileStatusTableEntry  * temp  = NULL;

  if(current)
  {
    while(current->next != NULL)
    {
        temp = current->next;
        SNMP_FREE( current );
        current = temp;
    }

    SNMP_FREE( current );
    moduleLogFileStatusTable_head = NULL;
  }
  return;
}


/**
* @details 
*          This is the routine which handles get response from SIH Get Processor
*          and prepare the SNMP GET response for EMS.
* @param tlvArray contains pointer to TLV array.
*/
TBOOL sendModuleLogFileStatusSnmpGetResponse (
  IO TlvArray    *tlvArray
  )
{
  int  totalNumRow, totalNumCol, i=0, colmn=0, pos = 0;
  moduleLogFileStatusTableEntry * prevPtr = NULL;

  printTLV(tlvArray);

  /* Total no. of Colmns */
  totalNumCol = MODULE_LOG_FILE_STATUS_MAX_COL;
  /* Total no. of Row = (No. of TLV)/(No. of Columns) */
  totalNumRow = tlvArray->numTlvs/totalNumCol;

  logInfo("Total No. of Row %d & Col %d", totalNumRow, totalNumCol);
  for (i=1;  i <= totalNumRow;  i++)
      {
      moduleLogFileStatusTableEntry *ptr=(moduleLogFileStatusTableEntry *)malloc(sizeof(moduleLogFileStatusTableEntry));

      clearBytes (ptr, sizeof(moduleLogFileStatusTableEntry));

      /* Fill Data in TLV */
      for(colmn = 1 ; colmn <= totalNumCol ; colmn++, pos++)
        {
        if (colmn EQ COLUMN_MODULE_LOG_FILE_STATUS_INDEX)
           {
            ptr->index =  getUint32FromArray(tlvArray->tlvInfo[pos].data);
            continue;
           }
        if (colmn EQ COLUMN_MODULE_LOG_FILE_STATUS_FILENAME)
           {
            clearBytes (ptr->fileName, MODULE_LOG_FILE_STATUS_NAME_MAX_BUF_LEN);
            copyBytes (tlvArray->tlvInfo[pos].data, tlvArray->tlvInfo[pos].len, ptr->fileName);
            ptr->fileName_len = strlen(ptr->fileName);
            continue;
           }
        if (colmn EQ COLUMN_MODULE_LOG_FILE_STATUS_FILESIZEINKB)
           {
            ptr->fileSizeInKB =  getUint32FromArray(tlvArray->tlvInfo[pos].data);
            continue;
           }
        if (colmn EQ COLUMN_MODULE_LOG_FILE_STATUS_OPENEDAT)
           {
            clearBytes (ptr->openedAt, MODULE_LOG_FILE_STATUS_TIME_MAX_BUF_LEN);
            copyBytes (tlvArray->tlvInfo[pos].data, tlvArray->tlvInfo[pos].len, ptr->openedAt);
            ptr->openedAt_len = strlen(ptr->openedAt);
            continue;
           }
        if (colmn EQ COLUMN_MODULE_LOG_FILE_STATUS_CLOSEDAT)
           {
            clearBytes (ptr->closedAt, MODULE_LOG_FILE_STATUS_TIME_MAX_BUF_LEN);
            copyBytes (tlvArray->tlvInfo[pos].data, tlvArray->tlvInfo[pos].len, ptr->closedAt);
            ptr->closedAt_len = strlen(ptr->closedAt);
            continue;
           }
        }

       ptr->next = NULL;

      if (prevPtr == NULL) {
           moduleLogFileStatusTable_head =  prevPtr = ptr;
       }

      prevPtr->next = ptr;
      prevPtr = ptr;
     }
    prevPtr->next = NULL;

    if (moduleLogFileStatusTable_head)
        return TRUE;
    else
        return FALSE;
}

/** Initializes the moduleLogFileStatus module */
void
init_moduleLogFileStatus(void)
{
  /* here we initialize all the tables we're planning on supporting */
    initialize_table_moduleLogFileStatusTable();
}

/* Determine the first/last column names */

/** Initialize the moduleLogFileStatusTable table by defining its contents and how it's structured */
void
initialize_table_moduleLogFileStatusTable(void)
{
    const oid moduleLogFileStatusTable_oid[] = {1,3,6,1,4,1,9344,501,MODULELOGFILESTATUS,1};
    const size_t moduleLogFileStatusTable_oid_len   = OID_LENGTH(moduleLogFileStatusTable_oid);
    netsnmp_handler_registration    *reg;
    netsnmp_iterator_info           *iinfo;
    netsnmp_table_registration_info *table_info;

    DEBUGMSGTL(("moduleLogFileStatus:init", "initializing table moduleLogFileStatusTable\n"));

    reg = netsnmp_create_handler_registration(
              "moduleLogFileStatusTable",     moduleLogFileStatusTable_handler,
              moduleLogFileStatusTable_oid, moduleLogFileStatusTable_oid_len,
              HANDLER_CAN_RONLY
              );

    table_info = SNMP_MALLOC_TYPEDEF( netsnmp_table_registration_info );
    netsnmp_table_helper_add_indexes(table_info,
                           ASN_UNSIGNED,  /* index: index */
                           0);
    table_info->min_column = COLUMN_MODULE_LOG_FILE_STATUS_INDEX;
    table_info->max_column = COLUMN_MODULE_LOG_FILE_STATUS_CLOSEDAT;
    
    iinfo = SNMP_MALLOC_TYPEDEF( netsnmp_iterator_info );
    iinfo->get_first_data_point = moduleLogFileStatusTable_get_first_data_point;
    iinfo->get_next_data_point  = moduleLogFileStatusTable_get_next_data_point;
    iinfo->table_reginfo        = table_info;
    
    netsnmp_register_table_iterator( reg, iinfo );

    /* Initialise the contents of the table here */
}


#ifndef PWAV_SIH
/* create a new row in the (unsorted) table */
struct moduleLogFileStatusTable_entry *
moduleLogFileStatusTable_createEntry(
                 u_long  index,
                ) {
    struct moduleLogFileStatusTable_entry *entry;

    entry = SNMP_MALLOC_TYPEDEF(struct moduleLogFileStatusTable_entry);
    if (!entry)
        return NULL;

    entry->index = index;
    entry->next = moduleLogFileStatusTable_head;
    moduleLogFileStatusTable_head = entry;
    return entry;
}

/* remove a row from the table */
void
moduleLogFileStatusTable_removeEntry( struct moduleLogFileStatusTable_entry *entry ) {
    struct moduleLogFileStatusTable_entry *ptr, *prev;

    if (!entry)
        return;    /* Nothing to remove */

    for ( ptr  = moduleLogFileStatusTable_head, prev = NULL;
          ptr != NULL;
          prev = ptr, ptr = ptr->next ) {
        if ( ptr == entry )
            break;
    }
    if ( !ptr )
        return;    /* Can't find it */

    if ( prev == NULL )
        moduleLogFileStatusTable_head = ptr->next;
    else
        prev->next = ptr->next;

    SNMP_FREE( entry );   /* XXX - release any other internal resources */
}
#endif /* PWAV_SIH */


/* Example iterator hook routines - using 'get_next' to do most of the work */
netsnmp_variable_list *
moduleLogFileStatusTable_get_first_data_point(void **my_loop_context,
                          void **my_data_context,
                          netsnmp_variable_list *put_index_data,
                          netsnmp_iterator_info *mydata)
{
    TagInfo sihTagInfo;
    TBOOL status = FALSE;


    if (g_sihModuleLogFileStatusGetReqProcessed EQ FALSE)
        {
        /* Set SIH Get Request Tag Info */
        sihTagInfo.tableId = MODULELOGFILESTATUS;
        sihTagInfo.rowId = CONFIG_ROW_ID_NONE;
        sihTagInfo.colId = CONFIG_COL_ID_NONE;

        status = sihGetProcessor (sihTagInfo);
        if ( status EQ TRUE )
            {
            logInfo("%s","Get Processor Succedded");
            if (moduleLogFileStatusTable_head)
                {
		g_moduleLogFileStatusFirstCall = 1;
                g_sihModuleLogFileStatusGetReqProcessed = TRUE;
                }
            }
        else
            logInfo("%s","Get Processor Failed");
        }

    *my_loop_context = moduleLogFileStatusTable_head;
    return moduleLogFileStatusTable_get_next_data_point(my_loop_context, my_data_context,
                                    put_index_data,  mydata );
}

netsnmp_variable_list *
moduleLogFileStatusTable_get_next_data_point(void **my_loop_context,
                          void **my_data_context,
                          netsnmp_variable_list *put_index_data,
                          netsnmp_iterator_info *mydata)
{
    struct moduleLogFileStatusTable_entry *entry = (struct moduleLogFileStatusTable_entry *)*my_loop_context;
    netsnmp_variable_list *idx = put_index_data;

    if ( entry ) {
        snmp_set_var_typed_integer( idx, ASN_UNSIGNED, entry->index );
        idx = idx->next_variable;
        *my_data_context = (void *)entry;
        *my_loop_context = (void *)entry->next;
        return put_index_data;
    } else {
        return NULL;
    }
}


/** handles requests for the moduleLogFileStatusTable table */
int
moduleLogFileStatusTable_handler(
    netsnmp_mib_handler               *handler,
    netsnmp_handler_registration      *reginfo,
    netsnmp_agent_request_info        *reqinfo,
    netsnmp_request_info              *requests) {

    netsnmp_request_info       *request = NULL;
    netsnmp_table_request_info *table_info = NULL;
    struct moduleLogFileStatusTable_entry          *table_entry = NULL;
    int loopCount = 0;

    DEBUGMSGTL(("moduleLogFileStatus:handler", "Processing request (%d)\n", reqinfo->mode));

    switch (reqinfo->mode) {
        /*
         * Read-support (also covers GetNext requests)
         */
    case MODE_GET:
        for (request=requests; request; request=request->next) {

            loopCount++;
            if (request->processed != 0) /*Processed all requests, rows and colmns */
                {
		g_prevModuleLogFileStatusReqCount = 0;
                g_sihModuleLogFileStatusGetReqProcessed = FALSE;
                /* free the resources */
                free_moduleLogFileStatusTable();
                /* Here loopCount is decremented, Due to calling of free function two times in SNMP-GETNEXT
                 * on single parameter -- 20/07/11 */
                loopCount--;
                continue;
                }

            /* perform anything here that you need to do before each
               request is processed. */

            /* the following extracts the my_data_context pointer set in
               the loop functions above.  You can then use the results to
               help return data for the columns of the moduleLogFileStatusTable table
               in question */

            table_entry = (struct moduleLogFileStatusTable_entry *)
                              netsnmp_extract_iterator_context(request);

            if ( table_entry == NULL) {
                if (reqinfo->mode == MODE_GET) {
                    netsnmp_set_request_error(reqinfo, request,SNMP_NOSUCHINSTANCE);
                    continue;
                }
                /* XXX: no row existed, if you support creation and this is a
                   set, start dealing with it here, else continue */
            }

            table_info  =     netsnmp_extract_table_info(      request);

            /* table_info->colnum contains the column number requested */
            /* table_info->indexes contains a linked list of snmp variable
               bindings for the indexes of the table.  Values in the list
               have been set corresponding to the indexes of the
               request */
            if (table_info==NULL) {
                continue;
            }
      
            switch (table_info->colnum) {
            case COLUMN_MODULE_LOG_FILE_STATUS_INDEX:
                if ( !table_entry ) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer( request->requestvb, ASN_UNSIGNED,
                                            table_entry->index);
                break;
            case COLUMN_MODULE_LOG_FILE_STATUS_FILENAME:
                if ( !table_entry ) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_value( request->requestvb, ASN_OCTET_STR,
                                          table_entry->fileName,
                                          table_entry->fileName_len);
                break;
            case COLUMN_MODULE_LOG_FILE_STATUS_FILESIZEINKB:
                if ( !table_entry ) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer( request->requestvb, ASN_UNSIGNED,
                                            table_entry->fileSizeInKB);
                break;
            case COLUMN_MODULE_LOG_FILE_STATUS_OPENEDAT:
                if ( !table_entry ) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_value( request->requestvb, ASN_OCTET_STR,
                                          table_entry->openedAt,
                                          table_entry->openedAt_len);
                break;
            case COLUMN_MODULE_LOG_FILE_STATUS_CLOSEDAT:
                if ( !table_entry ) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_value( request->requestvb, ASN_OCTET_STR,
                                          table_entry->closedAt,
                                          table_entry->closedAt_len);
                break;
            default:
                netsnmp_set_request_error(reqinfo, request,
                                          SNMP_NOSUCHOBJECT);
                break;
            }
        }
	if(g_moduleLogFileStatusFirstCall EQ 1)
         {
            g_moduleLogFileStatusFirstCall = 0;
            g_prevModuleLogFileStatusReqCount = loopCount;
            // This will occur in case of, when SNMP-GET or SNMP-GETNEXT of Single Parameter occurred.
            // In the first call itself loopCount becomes one.
            // In General Case, the loopCount will be always > 1 because every table contains 
            // index column to fetch the row and remaining columns contain table attributes.
            if(loopCount EQ 1)
            {
               //Setting it to false in case of SNMP-GET request for single parameter.
               g_sihModuleLogFileStatusGetReqProcessed = FALSE;
               // Free all resources.
               free_moduleLogFileStatusTable();
            }
         }
         else if(loopCount > 1 || g_prevModuleLogFileStatusReqCount > 1)
         {
            //update g_prevReqCount with current loopCount for next call of Table_handler
            g_prevModuleLogFileStatusReqCount = loopCount;
         }
         else if(loopCount EQ 1)
         {
            //Setting it to false in case of SNMP-GET request for single parameter.
            g_sihModuleLogFileStatusGetReqProcessed = FALSE;
            // Free all resources.
            free_moduleLogFileStatusTable();
         }
        break;

    }
    return SNMP_ERR_NOERROR;
}
