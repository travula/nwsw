/*******************************************************************************
 * Copyright: (C) 2009 Polaris Networks. All Rights Reserved.                  *
 *    No part of this source code may be reproduced, transmitted, transcribed  *
 *    or translated into any language without the written permission of        *
 *    Polaris Networks or its suppliers or affiliate companies. To obtain this *
 *    permission write to the attention of Legal counsel, Polaris Networks,    *
 *    75 Robbins Road, MA 02421 United States.                                 *
 ******************************************************************************/


#ifndef __PN_LOGGER_H__
#define __PN_LOGGER_H__

/**********************************************************************************/
/* Forward declarations.                                                          */
/**********************************************************************************/
typedef enum ELogLevel
{
    ELOG_LEVEL_ERROR,      /* error conditions such as fatal errors */
    ELOG_LEVEL_CRITICAL,   /* critical conditions */
    ELOG_LEVEL_WARNING,    /* warning conditions */
    ELOG_LEVEL_MESSAGE,    /* normal, but significant, condition */
    ELOG_LEVEL_INFO,       /* informational message */
    ELOG_LEVEL_DEBUG,      /* debug-level message */
    ELOG_LEVEL_DEVEL_DEBUG,/* debug-level used at the time of development */
    ELOG_LEVEL_MAX,

} ELogLevel;


/**********************************************************************************/
/* Macro definitions - these macros can be used to make the logging easier. If    */
/* these macros are used then code for writing the log message are adden in the   */
/* executible only if PN_LOGGING_DISABLED macro is not defined.                   */
/**********************************************************************************/
/* Initializes logger module */
#ifndef PN_LOGGING_DISABLED
#define LOG_INIT_MODULE( logFileName, logLevel, logTimeFormat ) LOGGERInitializeModule( logFileName, logLevel, logTimeFormat );
#else
#define LOG_INIT_MODULE( logFileName, logLevel, logTimeFormat )
#endif

/* Closes logger module */
#ifndef PN_LOGGING_DISABLED
#define LOG_CLOSE_MODULE() LOGGERCloseModule();
#else
#define LOG_CLOSE_MODULE()
#endif

/* For printing API Enrty information */
#ifndef PN_LOGGING_DISABLED
#define LOG_API_IN() LOGGERWriteLog( ELOG_LEVEL_DEVEL_DEBUG, __sModuleName__, __FILE__, __LINE__, ELOG_API_IN, __FUNCTION__ );
#else
#define LOG_API_IN()
#endif

/* For printing API Exit information */
#ifndef PN_LOGGING_DISABLED
#define LOG_API_OUT() LOGGERWriteLog( ELOG_LEVEL_DEVEL_DEBUG, __sModuleName__, __FILE__, __LINE__, ELOG_API_OUT, __FUNCTION__ );
#else
#define LOG_API_OUT()
#endif

/* For printing INFO log messages */
#ifndef PN_LOGGING_DISABLED
#define LOG_INFO( msgId, ... ) LOGGERWriteLog( ELOG_LEVEL_INFO, __sModuleName__, __FILE__, __LINE__, msgId, ##__VA_ARGS__ );
#else
#define LOG_INFO( msgId, ... )
#endif

/* For printing WARNING log messages */
#ifndef PN_LOGGING_DISABLED
#define LOG_WARNING( msgId, ... ) LOGGERWriteLog( ELOG_LEVEL_WARNING, __sModuleName__, __FILE__, __LINE__, msgId, ##__VA_ARGS__ );
#else
#define LOG_WARNING( msgId, ... )
#endif

/* For printing ERROR log messages */
#ifndef PN_LOGGING_DISABLED
#define LOG_ERROR( msgId, ... ) LOGGERWriteLog( ELOG_LEVEL_ERROR, __sModuleName__, __FILE__, __LINE__, msgId, ##__VA_ARGS__ );
#else
#define LOG_ERROR( msgId, ... )
#endif

/* For printing DEBUG log messages */
#ifndef PN_LOGGING_DISABLED
#define LOG_DEBUG( msgId, ... ) LOGGERWriteLog( ELOG_LEVEL_DEBUG, __sModuleName__, __FILE__, __LINE__, msgId, ##__VA_ARGS__ );
#else
#define LOG_DEBUG( msgId, ... )
#endif

/* For printing DEVELOPMENT log messages */
#ifndef PN_LOGGING_DISABLED
#define LOG_DEVEL( msgId, ... ) LOGGERWriteLog( ELOG_LEVEL_DEVEL_DEBUG, __sModuleName__, __FILE__, __LINE__, msgId, ##__VA_ARGS__ );
#else
#define LOG_DEVEL( msgId, ... )
#endif

#ifdef WIN32
#define PN_LOGGER_API __declspec( dllexport )
#else
#define PN_LOGGER_API
#endif


/***********************************************************************************/
/* Enumerations.                                                                   */
/***********************************************************************************/
typedef enum ELogTimeFormat
{
    ELOG_TIME_FORMAT_NONE,      /* Time information is not displayed in log file. */
    ELOG_TIME_FORMAT_TIME_ONLY, /* Only time information is displayed in log, no date info is added. */
    ELOG_TIME_FORMAT_DATE_TIME, /* Date and time information are added in log messages. */
    ELOG_TIME_FORMAT_MAX

} ELogTimeFormat;


typedef enum ELogMessageID
{
    ELOG_NO_MESSAGE,
    ELOG_MESSAGE,

    /* API Entry and Exit */
    ELOG_API_IN,
    ELOG_API_OUT,

    /* Emulator Version*/
    ELOG_EMULATOR_VERSION,
    ELOG_EMULATOR_SVN_REVISION,

    /* Table related */
    E_TABLE_IS_NOT_CREATED,
    E_TABLE_OPEN_SUCCESSFUL,
    E_TABLE_OPEN_FAILED,
    E_TABLE_CLOSE_SUCCESSFUL,
    E_ENTRY_EXISTS_IN_TABLE,
    E_ENTRY_DOESNT_EXIST,
    E_FAILED_TO_ADD_ENTRY_IN_TABLE,

    /* File I/O */
    ELOGGER_INIT_SUCCESS,
    ELOG_FOPEN_FAILED,
    ELOG_FWRITE_FAILED,
    ELOG_FREAD_FAILED,
    ELOGGER_PRINT_LOG_LEVEL,

    /* Socket */
    ESOCKET_CREATION_FAILED, 
    ESOCKET_BIND_FAILED,  

    /* Memory Allocation */
    ELOG_MALLOC_FAILED,
    ELOG_CALLOC_FAILED,
    ELOG_REALLOC_FAILED,
    ELOG_FREE_FAILED,
    ELOG_RELEASE_RESOURCE_FAILED,
    ELOG_ILLEGAL_LOG_LEVEL,
    ELOG_ILLEGAL_TIME_FORMAT,
    ELOG_MEM_DEBUG_MESSAGE, 

    /* Message Queue */
    EMQ_CREATE_FAILED, 
    EMQ_OPEN_FAILED, 
    EMQ_CREATE_SUCCESSFUL,
    EMQ_OPEN_SUCCESSFUL,
    EMQ_DELETE_FAILED, 
    EMQ_CLOSE_FAILED,  
    EMQ_SEND_FAILED, 
    EMQ_RECEIVE_FAILED, 
    EEQ_CREATE_SUCCESSFUL,
    EMQ_SEND_SUCCESS,
    EMQ_RECV_SUCCESS,
    EMQ_FD_RX_READY,

    /* Timer */
    ETM_ADDED_TIMER,
    ETM_REMOVED_TIMER,
    ETM_REGISTERED_TIMER,
    ETM_DEREGISTERED_TIMER,
    ETM_STARTED_TIMER,
    ETM_STOPPED_TIMER,
    ETM_INVOKED_TIMER_CB,
    ETM_INVOKED_CLEANUP_CB,

    /* S1AP */
    ES1AP_INIT_SUCCESS,
    ES1AP_INIT_FAILURE,
    ES1AP_RX_PACKET,
    ES1AP_INFO_MESSAGE,
    ES1AP_DEBUG_MSG_WITH_INT_VALUE,
    ES1AP_MME_TX_ENB_MESSAGE_INFO,
    ES1AP_MME_TX_ENB_MESSAGE_FAIL,
    ES1AP_ENB_TX_MME_MESSAGE_INFO,
    ES1AP_ENB_TX_MME_MESSAGE_FAIL,
    ES1AP_MME_TX_ENB_UE_ASSOC_MESSAGE_INFO,
    ES1AP_MME_TX_ENB_UE_ASSOC_MESSAGE_FAIL,
    ES1AP_ENB_TX_MME_UE_ASSOC_MESSAGE_INFO,
    ES1AP_ENB_TX_MME_UE_ASSOC_MESSAGE_FAIL,
    ES1AP_MME_RX_ENB_MESSAGE_INFO,
    ES1AP_ENB_RX_MME_MESSAGE_INFO,
    ES1AP_MME_RX_ENB_UE_ASSOC_MESSAGE_INFO,
    ES1AP_ENB_RX_MME_UE_ASSOC_MESSAGE_INFO,
    ES1AP_DEBUG_MESSAGE,
    ES1AP_BIND_TO_SOCKET_FAILED,
    ES1AP_HANDLE_RRC_MESSAGE,
    ES1AP_HANDLE_NAS_MESSAGE,
    ES1AP_PACKET_INFO,
    ES1AP_ENODEB_INFO,
    ES1AP_MME_INFO,
    ES1AP_S1_CONNECTION_ESTABLISHED,
    ES1AP_S1_CONNECTION_FAILURE,
    ES1AP_UNEXPECTED_PACKET,
    ES1AP_CONNECTION_FAILURE, 
    ES1AP_DUPLICATE_UE,
    ES1AP_NODE_NOT_FOUND,
    ES1AP_TA_DB_OPENING_FAILED,
    ES1AP_CELL_DB_OPENING_FAILED,
    ES1AP_UEID_TO_UE_CONTEXT_MAPPING_TABLE_OPENING_FAILED,
    ES1AP_INTERFACE_IP_ADDRESS_ERROR,
    ES1AP_GARBLED_MME_NODE,
    ES1AP_GARBLED_ENB_NODE,
    ES1AP_GARBLED_NODE,
    ES1AP_ILLEGAL_SOCKET_ID,
    ES1AP_ILLEGAL_MME_CONNECTION_STATE,
    ES1AP_UE_CONTEXT_ADDITION_IN_MME_FAILED,
    ES1AP_UE_CONTEXT_ADDITION_IN_ENB_FAILED,
    ES1AP_UE_CONTEXT_IN_MME_UNAVAILABLE,
    ES1AP_UE_CONTEXT_IN_ENB_UNAVAILABLE,
    ES1AP_API_NAME,
    ES1AP_MME_EVENT_INFO,
    ES1AP_SERVED_PLMN_INFO,
    ES1AP_PARSING_FAILURE_MESSAGE,
    ES1AP_BUILDING_FAILURE_MESSAGE,
    ES1AP_ENB_ID_MISMATCH,
    ES1AP_MME_ID_MISMATCH,
    ES1AP_CALLBACK_FAILED,
    ES1AP_CALLBACK_INVALID,
    ES1AP_TRIGGERED_HANDLER,
    ES1AP_TRIGGERED_UE_ASSOC_HANDLER,
    ES1AP_TRIGGERED_NAS_PDU_RECV_HANDLER,
    ES1AP_MME_NONEXISTENT_LOGICAL_S1_CONNECTION,
    ES1AP_MME_UE_CONTEXT_REMOVED,
    ES1AP_ENB_UE_CONTEXT_REMOVED,
    ES1AP_ENB_NONEXISTENT_LOGICAL_S1_CONNECTION_TX,
    ES1AP_ENB_NONEXISTENT_LOGICAL_S1_CONNECTION_RX,
    ES1AP_MSG_PROCESSING_FAILED,
    ES1AP_UE_INSERTED_IN_ENODEB_ENTITY_DB,  
    ES1AP_UE_DELETED_FROM_ENODEB_ENTITY_DB, 
    ES1AP_MME_SELECTION_FAILURE,
    ES1AP_POLICY_MSG_DROP,
    ES1AP_POLICY_MSG_SEND_ERR_IND,
    ES1AP_GLOBAL_ENB_ID_MISMATCH,

    /* SCTP */
    ESCTP_INIT_SUCCESS,
    ESCTP_INIT_FAILURE,
    ESCTP_INFO_MESSAGE, 
    ESCTP_CONNECTION_INFO,
    ESCTP_NEW_CONNECTION_INFO,
    ESCTP_DATA_RECEIVE_INFO,
    ESCTP_NOTIFICATION_INFO,
    ESCTP_DEBUG_MESSAGE,
    ESCTP_SOCKET_CREATION_FAILED,
    ESCTP_BIND_FAILED,
    ESCTP_OPEN_FAILED,
    ESCTP_CONNECT_FAILED,
    ESCTP_SEND_FAILED,
    ESCTP_TX_INFO,
    ESCTP_TX_DEBUG,

    /* TCL */
    ETCL_INTERPRETER_STATUS,
    ETCL_CMD_MESSAGE,
    ETCL_CREATE_NETWORK_MESSAGE,
    ETCL_DELETE_NETWORK_MESSAGE,
    ETCL_LTE_CREATE_TA_MESSAGE,
    ETCL_LTE_DELETE_TA_MESSAGE,
    ETCL_ENODEB_CREATE_CELL_MESSAGE,
    ETCL_ENODEB_DELETE_CELL_MESSAGE,
    ETCL_LTE_CREATE_ENB_MESSAGE,
    ETCL_LTE_CREATE_MME_MESSAGE,
    ETCL_LTE_ASOCIATE_ENB_TO_MME_MESSAGE,
    ETCL_LTE_SET_LOG_FILE,
    ETCL_LTE_SET_LOG_LEVEL,
    ETCL_DEBUG_MESSAGE,

    /* NAS */
    ENAS_INIT_MODULE_FAILED,
    ENAS_INIT_THREAD_FAILED,
    ENAS_INIT_THREAD_SUCCESS,
    ENAS_CLOSE_LIBRARY_SUCCESS,
    ENAS_POPULATE_MME_PARAMS_FAILED,
    ENAS_CREATE_MME_SUCCESS,
    ENAS_POPULATE_UE_PARAMS_FAILED,
    ENAS_CREATE_UE_SUCCESS,
    ENAS_DELETE_MME_FAILED,
    ENAS_DELETE_MME_SUCCESS,
    ENAS_DELETE_UE_FAILED,
    ENAS_DELETE_UE_SUCCESS,
    ENAS_MODULE_INIT_FAILED,
    ENAS_EVENT_PROC_STARTED,
    ENAS_EVENT_PROC_STOPPED,
    ENAS_INIT_EVT_PROC_QUEUE_FAILED,
    ENAS_CLOSE_EVT_PROC_QUEUE_FAILED,
    ENAS_INIT_SUCCESS,
    ENAS_RCVD_MESSAGE,
    EMMENAS_RCVD_FROM_MSGQ,
    EMMENAS_RCVD_ATTACH_COMPLETE,
    EMMENAS_INTEGRITY_FAILED,
    EUENAS_INTEGRITY_FAILED,
    ENAS_GENERIC_EVENT,
    ENAS_EVENT_RCVD_MSG,
    EMMENAS_RETRANSMIT_PDU,
    EMMENAS_PROCESS_EMM_EVT,
    EMMENAS_TIMER_UE_STATE_CHANGE,
    ENAS_POLICY_MSG_DROP,
    ENAS_POLICY_MSG_RSP_WITH_STATUS,
    
    /* GTP-C */
    EGTP_LIB_ALREADY_INIT,
    EGTP_LIB_INIT_SUCESS,
    EGTP_LIB_INIT_FAIL,
    EGTP_RCVD_DATA,
    EGTP_SENT_DATA,
    EGTP_DATA_SEND_FAILED,
    EGTPV2C_POLICY_MSG_DROP,
    EGTPV2C_POLICY_MSG_CTRL_RSP,

    /* GTP-u */
    EGTPU_DL_DATA_INFO,
    EGTPU_DL_DATA_SENT,

    /* SGW Emulator */
    ESGW_SGW_INVALID_SESSION_HANDLE,
    ESGW_SGW_INVALID_SGW_HANDLE,
    ESGW_GTPV1U_TUNNEL_CREATE_SUCCESS,
    ESGW_GTPV2C_SESSION_CREATE_SUCCESS,
    ESGW_GTPV1U_TUNNEL_MODIFY_SUCCESS,

    ESGW_GTPV2C_INVOKED_GTPC_CREATE_BEARER_REQ,
    ESGW_GTPV2C_INVOKED_GTPC_UPDATE_BEARER_REQ,
    ESGW_GTPV2C_INVOKED_GTPC_DELETE_BEARER_REQ,

    ESGW_GTPV2C_RCVD_CREATE_BEARER_RESPONSE,
    ESGW_GTPV2C_BEARER_CREATED,
    ESGW_GTPV2C_RCVD_UPDATE_BEARER_RESPONSE,
    ESGW_GTPV2C_BEARER_UPDATED,
    ESGW_GTPV2C_RCVD_DELETE_BEARER_RESPONSE,
    ESGW_GTPV2C_BEARER_DELETED,

    ESGW_SGW_CREATE,
    ESGW_SGW_S11_SESSION_CREATE,
    ESGW_SGW_S11_SESSION_DELETE,
    ESGW_SGW_S1U_BEARER_CREATE,
    ESGW_SGW_S1U_BEARER_CREATE_REQUEST,
    ESGW_SGW_S1U_BEARER_DELETE,
    ESGW_SGW_S1U_BEARER_MODIFY,
    ESGW_SGW_S1U_BEARER_UPDATE,
    ESGW_SGW_S5C_SESSION_CREATE,
    ESGW_SGW_S5C_SESSION_DELETE, 
    ESGW_SGW_S5U_BEARER_CREATE,
    ESGW_SGW_S5U_BEARER_CREATE_REQUEST,
    ESGW_SGW_S5U_BEARER_DELETE,
    ESGW_SGW_S5U_BEARER_MODIFY,
    ESGW_SGW_S5U_BEARER_UPDATE,
    ESGW_SGW_DOWNLINK_DATA_NOTIFY,
    ESGW_SGW_PATH_FAILURE,

    /* MME Controller */
    EMMEC_CREATE_NETWORK_FAILED,
    EMMEC_DELETE_NETWORK_FAILED,
    EMMEC_HSS_UE_RETRIEVE_FAILED,
    EMMEC_HSS_UE_PURGE_FAILED,
    EMMEC_UE_IMSI_CONTEXT_RETRIEVE_FAILED,
    EMMEC_UE_ID_CONTEXT_RETRIEVE_FAILED,
    EMMEC_RCVD_NAS_DUPLICATE_UE,
    EMMEC_RECVD_INVALID_EBI,
    EMMEC_RECEIVED_NAS_CREATE_PDN_CONN_EVENT,
    EMMEC_INVOKED_GTPC_CREATE_SESSION_REQ,
    EMMEC_RCVD_GTPC_CREATE_SESSION_RSP,
    EMMEC_TRIGGERED_NAS_CREATE_SESSION_RSP,
    EMMEC_RCVD_S1AP_INITIAL_UE,
    EMMEC_ADDED_INIT_UE_IN_CONTEXT_TABLE,
    EMMEC_ADDED_UE_IN_CONTEXT_TABLE,
    EMMEC_DUPLICATE_UE_CONTEXT_ID,
    EMMEC_DUPLICATE_UE_CONTEXT_IMSI,
    EMMEC_EXISTING_UE_CONTEXT_IMSI,
    EMMEC_EBI_RETRIEVE_FAILED,
    EMMEC_UE_MM_STATE_CHANGED,
    EMMEC_UE_MM_STATE_UNCHANGED,
    EMMEC_REGISTERED_STMSI,
    EMMEC_REGISTERED_GUTI,
    EMMEC_DEREGISTERED_GUTI,
    EMMEC_GUTI_RETRIEVE_FAILED,
    EMMEC_UE_CONTEXT_NAS_BEARER_MISMATCH,
    EMMEC_UE_CONTEXT_NAS_BEARER_EXCEEDS_MAX,
    EMMEC_RCVD_NAS_UE_CONTEXT_CREATE,
    EMMEC_RCVD_NAS_UE_INITIATED_SERVICE_REQ,
    EMMEC_TRIGGERED_S1AP_ENB_UE_CONTEXT_CREATE,
    EMMEC_TRIGGERED_NAS_UE_SIG_CREATE_COMPLETE,

    EMMEC_INVOKED_GTPC_MODIFY_BEARER_REQ,
    EMMEC_RCVD_GTPC_MODIFY_BEARER_RSP,

    EMMEC_GTPC_INVALID_CREATE_BEARER_REQ,
    EMMEC_INVOKED_CREATE_BEARER_SETUP_TO_NAS_FAILED,

    EMMEC_INVOKED_GTPC_CREATE_BEARER_REQ_RESPONSE,
    EMMEC_INVOKED_GTPC_UPDATE_BEARER_REQ_RESPONSE,
    EMMEC_INVOKED_GTPC_DELETE_BEARER_REQ_RESPONSE,

    EMMEC_RCVD_S1AP_CREATE_BEARER_RESPONSE,
    EMMEC_RCVD_S1AP_UPDTAE_BEARER_RESPONSE,
    EMMEC_RCVD_S1AP_RELEASE_BEARER_RESPONSE,

    EMMEC_RCVD_GTPC_CREATE_BEARER_REQ,
    EMMEC_RCVD_GTPC_UPDATE_BEARER_REQ,
    EMMEC_RCVD_GTPC_DELETE_BEARER_REQ,

    EMMEC_INVOKED_GTPC_CREATE_BEARER_REQ,
    EMMEC_INVOKED_GTPC_UPDATE_BEARER_REQ,
    EMMEC_INVOKED_GTPC_DELETE_BEARER_REQ,

    EMMEC_RCVD_GTPC_DL_DATA_NOTIFICATION,

    EMMEC_INVOKED_GTPC_INDIRECT_DATA_FWD_TUNNEL_REQ,
    EMMEC_RCVD_GTPC_INDIRECT_DATA_FWD_TUNNEL_RESP,

    EMMEC_RECEIVED_NAS_DELETE_SESSION_REQ_EVENT,
    EMMEC_INVOKED_GTPC_DELETE_SESSION_REQ,
    EMMEC_RCVD_GTPC_DELETE_SESSION_RSP,
    EMMEC_TRIGGERED_NAS_DELETE_SESSION_RSP,
    EMMEC_FAILED_TO_PROC_DELETE_SESSION_RSP,
    EMMEC_RCVD_S1AP_CREATE_ENB_UE_CONTEXT_RSP,
    EMMEC_RCVD_S1AP_RELEASE_ENB_UE_CONTEXT,
    EMMEC_RCVD_S1AP_RELEASE_ENB_UE_CONTEXT_RSP,
    EMMEC_RCVD_NAS_RELEASE_UE_CONTEXT,
    EMMEC_TRIGGERED_S1AP_RELEASE_UE_CONTEXT,
    EMMEC_TRIGGERED_NAS_DELETE_UE_CONTEXT,
    EMMEC_TRIGGERED_S1AP_DELETE_UE_CONTEXT,
    EMMEC_TRIGGERED_NAS_START_PAGING,
    EMMEC_RCVD_NAS_PAGING_ACK,
    EMMEC_DEFAULT_BEARER_NOT_SET,

    EMMEC_INVOKED_NAS_CREATE_BEARER_REQ,

    EMMEC_INVOKED_GTPC_RELEASE_ACCESS_BEARERS_REQ,
    EMMEC_RCVD_GTPC_RELEASE_ACCESS_BEARERS_RSP,
    EMMEC_FAILED_TO_PROC_RELEASE_ACCESS_BEARERS_RSP,

    EMMEC_MODIFIED_DL_TNL_EBI,
    EMMEC_ADDED_DONE_EBI,
    EMMEC_REMOVED_DONE_EBI,
    EMMEC_ADDED_TO_BE_DONE_EBI,
    EMMEC_REMOVED_TO_BE_DONE_EBI,
    EMMEC_CHANGED_UE_ECM_STATE,

    EMMEC_FREED_UE_CONTEXT,
    EMMEC_RECEIVED_NAS_UE_CONTEXT_RELEASE_EVENT,

    EMMEC_RCVD_S1AP_RESET,
    EMMEC_RCVD_NAS_CURRENT_PROC,
    EMMEC_TRIGGERED_S1AP_SET_UE_HOME_PLMN,
    EMMEC_RCVD_S1AP_REGISTERED_TA_LIST,
    EMMEC_RCVD_S1AP_REGISTERED_TA_LIST_FOR_ALL_UE,
    EMMEC_RCVD_S1AP_HO_NOTIFY,
    EMMEC_RCVD_S1AP_HO_PREP,
    EMMEC_TRIGGERED_S1AP_HO_REQ,
    EMMEC_RCVD_S1AP_HO_REQ_ACK,
    EMMEC_TRIGGERED_S1AP_HO_CMD,
    EMMEC_RCVD_S1AP_LOC_REP_CNTRL,
    EMMEC_TRIGGERED_S1AP_LOC_REP,

    EMMEC_RCVD_NAS_FWD_PDU,
    EMMEC_RCVD_S1AP_FWD_NAS_PDU,
    EMMEC_SESSION_ALREADY_DELETED,
    EMMEC_RESET_ALREADY_STARTED,
    EMMEC_HANDOVER_FAILED,
    EMMEC_GTPC_PACKET_SENDING_FAILED,
    EMMEC_EIR_UE_RETRIEVE_FAILED,
    EMMEC_EIR_VALIDATE_IMEI,
    EMMEC_RCVD_GTPC_BEARER_RES_FAIL_IND, 

    /* HSS Simulator */
    EHSS_NODE_CREATING,
    EHSS_UE_REGISTERED,

    /* SGSN Emulator */
    ESGSN_CREATE_NETWORK_FAILED,
    ESGSN_DELETE_NETWORK_FAILED,
    ESGSN_SGSN_CREATE_SUCCESS,
    ESGSN_SGSN_DESTROY_SUCCESS,
    ESGSN_SGSN_INVALID_SGSN_HANDLE,
    ESGSN_SGSN_INVALID_SESSION_HANDLE,
    
    /* S6a */
    ES6A_INIT_THREAD_SUCCESS,
    ES6A_INIT_MODULE_FAILED,
    ES6A_CLOSE_LIBRARY_SUCCESS,
    ES6A_RECVD_NULL_PKT,
    ES6A_ERROR_MEM_ALLOCATION,
    ES6A_INVALID_ANSWER_PACKET,
    ES6A_INVALID_PKT_CMD,
    ES6A_RECVD_PKT,
    ES6A_PKT_MANDATORY_AVP_MISSING,
    ES6A_RECVD_USERNAME_AVP,
    ES6A_RECVD_VPLMNID_AVP,
    ES6A_RECVD_RESULT_CODE,
    ES6A_RECVD_AUTH_SESSION_STATE,
    ES6A_RECVD_RAND_CHALLANGE,
    ES6A_RECVD_XRES,
    ES6A_RECVD_AUTN,
    ES6A_RECVD_KASME,
    ES6A_RECVD_ULRFLAG,
    ES6A_RECVD_RAT_TYPE,
    ES6A_RECVD_ULAFLAG,
    ES6A_RECVD_MSISDN,
    ES6A_RECVD_SUBS_DATA,
    ES6A_RECVD_APN_CONFIG_PROFILE,
    ES6A_RECVD_APN_CONFIG,
    ES6A_RECVD_AMBR,
    ES6A_RECVD_MAX_UL_AMBR,
    ES6A_RECVD_AUTH_INFO,
    ES6A_RECVD_EUTRAN_VECTOR,
    ES6A_RECVD_PDN_TYPE,
    ES6A_RECVD_MAX_DL_AMBR,
    ES6A_RECVD_SERVICE_SEL,
    ES6A_RECVD_UE_IP,
    ES6A_RECVD_MIP6_AGENT_INFO,
    ES6A_RECVD_MIP_HOME_AGENT_ADDRESS,
    ES6A_RECVD_CANCELLATION_TYPE,
    ES6A_RECVD_REQUESTED_EUTRAN_AUTH_INFO,
    EDIAMETER_INIT_EVT_PROC_QUEUE_FAILED,
    ES6A_UNKNOWN_APPLICATION,
    ES6A_UNKNOWN_COMMAND,
    ES6A_UNKNOWN_AVP,
    ES6A_UNKNOWN_ENUM,
    ES6A_AVP_CONFLICT,
    ES6A_CMD_EXISTS,
    ES6A_READ_ERROR,
    ES6A_OPEN_ERROR,
    ES6A_UE_CONTEXT_UPDATED,
    ES6A_UE_AUTHENTICATED,
    ES6A_RCVD_FROM_MSGQ,
    ES6A_RECVD_ALLAPNCONFIG,
    ES6A_RECVD_IDAFLAG,
    ES6A_RECVD_IDRFLAG,
    ES6A_RECVD_DSAFLAG,
    ES6A_RECVD_DSRFLAG,
    ES6A_RECVD_CONTEXTID,
    ES6A_FAILED_AUTH_REQUEST,
    ES6A_SUCCESS_AUTH_REQUEST,
    ES6A_UE_ALREADY_AUTHENTICATED,
    ES6A_FAILED_UPDATE_REQUEST,
    ES6A_SUCCESS_UPDATE_REQUEST,
    ES6A_UE_ALREADY_UPDATED,
    ES6A_FAILED_NOTIFY_HSS,
    ES6A_SUCCESS_NOTIFY_HSS,
    ES6A_UE_ALREADY_NOTIFIED,
    ES13_SUCCESS_MEIDENTITY_CHECK_EIR,
    ES13_FAILED_MEIDENTITY_CHECK_EIR,
    ES6A_PURGE_UE_SUCCESS,
    ES6A_PURGE_UE_FAILED,
    ES6A_CANCEL_LOCATION_ANSWER_SUCCESS,
    ES6A_CANCEL_LOCATION_ANSWER_FAILED,
    ES6A_INSERT_SUBSCRIBER_DATA_ANSWER_SUCCESS,
    ES6A_INSERT_SUBSCRIBER_DATA_ANSWER_FAILED,
    ES6A_DELETE_SUBSCRIBER_DATA_ANSWER_SUCCESS,
    ES6A_DELETE_SUBSCRIBER_DATA_ANSWER_FAILED,
    ES6A_UPDATE_LOCATION_ANSWER_RECEIVED,
    ES6A_AUTHENTICATION_INFORMATION_ANSWER_RECEIVED,
    ES6A_CANCEL_LOCATION_REQUEST_RECEIVED,
    ES6A_INTERNAL_HSS_UPDATE_LOCATION_REQUEST,
    ES6A_INTERNAL_HSS_AUTHENTICATION_INFORMATION_REQUEST,
    ES6A_PURGE_UE_ANSWER_RECEIVED,
    ES6A_INSERT_SUBSCRIBER_DATA_REQUEST_RECEIVED,
    ES6A_DELETE_SUBSCRIBER_DATA_REQUEST_RECEIVED,
    ES6A_NOTIFY_ANSWER_RECEIVED,
    ES13_MOBILE_EQUIPMENT_IDENTITY_CHECK_ANSWER_RECEIVED,
    EDIAMETER_INVALID_USERNAME_RECEIVED,
    EDIAMETER_INVALID_PACKET_RECEIVED,
    EDIAMETER_SENDING_ANSWER,

    /*Improved Log Messages*/
    EMMEC_IMP_NETWORK_CREATION,
    EMMEC_IMP_MME_CREATION,
    EMMEC_IMP_MME_DESTROY,
    EMMEC_IMP_MME_S1_MME_CONNECTION_SETUP,
    EMMEC_IMP_MME_S1_MME_CONNECTION_CLOSE,
    EMMEC_IMP_MME_S1_MME_CONNECTION_RESET,
    EMMEC_IMP_MME_UE_CONNECTION_STATE_CHANGED,
    EMMEC_IMP_MME_UE_INITIAL_ATTACH_REQUST,
    EMMEC_IMP_MME_UE_ATTACH_COMPLETE,
    EMMEC_IMP_MME_TRACKING_AREA_UPDATE,
    EMMEC_IMP_MME_UE_HANDOVER_INITIATED,
    EMMEC_IMP_MME_UE_HANDOVER_COMPLETED,
    EMMEC_IMP_MME_PAGING,
    EMMEC_IMP_MME_DEDICATED_S1U_BEARER_MODIFICATION,
    EMMEC_IMP_MME_DEDICATED_S1U_BEARER_DELETION,
    EMMEC_IMP_MME_DEDICATED_S1U_BEARER_CREATION,
    EMMEC_IMP_MME_S11_SESSION_DELETION,
    EMMEC_IMP_MME_S11_SESSION_CREATION,
    EMMEC_IMP_MME_UE_DETACH,
    EMMEC_IMP_MME_UE_MOBILITY_STATE_CHANGE,
    EMMEC_IMP_MME_UE_AUTHENTICATION_STATUS_UPDATE,
    EMMEC_IMP_MME_UE_AUTHENTICATION_VECTOR_UPDATE,
    EMMEC_IMP_MME_UE_MOBILE_EQUIPMENT_IDENTITY_VALIDATION_STATUS,
    EMMEC_IMP_MME_UE_SUSBCRIPTION_VALIDATION_STATUS_UPDATE,
    EHSSSiM_SUBSCRIBER_PROFILE,
    EHSSSiM_UE_REGISTER,

    /*EnodeB Improved Log Messages */
    EENBC_IMP_NETWORK_CREATION,
    EENBC_IMP_ENB_CREATION,
    EENBC_IMP_CELL_CREATION,
    EENBC_IMP_ENB_DESTROY,
    EENBC_IMP_ENB_S1_MME_CONNECTION_SETUP,
    EENBC_IMP_ENB_S1_MME_CONNECTION_CLOSE,
    EENBC_IMP_ENB_S1_MME_CONNECTION_RESET,
    EENBC_IMP_ENB_CONFIGURATION_UPDATE,
    EENBC_IMP_ENB_UE_CONNECTION_STATE_CHANGE,
    EENBC_IMP_UE_CONTEXT_CREATION,
    EENBC_IMP_UE_CONTEXT_DELETION,
    EENBC_IMP_UE_HANDOVER_INITIATED,
    EENBC_IMP_UE_HANDOVER_COMPLETE,
    EENBC_IMP_UE_PAGING,
    EENBC_IMP_ERAB_CREATION,
    EENBC_IMP_ERAB_DELETION,
    EENBC_IMP_ERAB_MODIFICATION,
    EUESIM_IMP_UE_CREATION,
    EUESIM_IMP_UE_ATTACH,
    EUESIM_IMP_UE_CONNECTION_STATE_CHANGE,
    EUESIM_IMP_UE_MOBILITY_STATE_CHANGE,
    EUESIM_IMP_UE_DETACH,
    EUESIM_IMP_UE_PAGING_INDICATION,
    EUESIM_IMP_UE_SERVICE_REQUEST,
    EUESIM_IMP_UE_TRACKING_AREA_UPDATE,
    EUESIM_IMP_UE_CELL_CHANGE,
    EUESIM_IMP_UE_DEDICATED_BEARER_CREATION,
    EUESIM_IMP_UE_DEDICATED_BEARER_DELETION,
    EUESIM_IMP_UE_DEDICATED_BEARER_MODIFICATION,

    /*  PGW Improved Log Messages  */
    EPGW_IMP_S5C_SESSION_CREATION,
    EPGW_IMP_S5C_SESSION_DELETION,
    EPGW_IMP_S5U_DEFAULT_BEARER_CREATION,
    EPGW_IMP_S5U_DEFAULT_BEARER_DELETION,
    EPGW_IMP_S5U_DEDICATED_BEARER_CREATION,
    EPGW_IMP_S5U_DEDICATED_BEARER_UPDATION,
    EPGW_IMP_S5U_DEDICATED_BEARER_DELETION,
    EPGW_IMP_S5U_PATH_FAILURE,
    EPGW_IMP_S5C_PATH_FAILURE,


    /* PAL related log messages */
    EPAL_INITIALIZE,
    EPAL_REGISTERED_PEER,
    EPAL_SEND_DATA_TO_PEER,
    EPAL_FAILED_SEND_DATA_UNKNOWN_PEER,
    EPAL_LOG_MESSAGE,

    /* RLC log messages */
    ERLC_INIT_MAC,
    ERLC_RX_CCCH,

    /* This should be the last line of the enum */
    ELOG_MAX_MSGID

} ELogMessageID;


#ifdef __cplusplus
extern "C" {
#endif 


/**********************************************************************************/
/* Exposed APIs.                                                                  */
/**********************************************************************************/
PN_LOGGER_API
void LOGGERInitializeModule
(
    const char*    in_kpszLogFileName,
    ELogLevel      in_eLogLevel,
    ELogTimeFormat in_eLogTimeFormat
);

PN_LOGGER_API
void LOGGERCloseModule( void );

PN_LOGGER_API
void LOGGERSetLogLevel( ELogLevel in_eLogLevel );

PN_LOGGER_API
ELogLevel LOGGERGetLogLevel();

PN_LOGGER_API
void LOGGERSetLogTimeFormat( ELogTimeFormat in_eLogTimeFormat );

PN_LOGGER_API
void LOGGERSetLogFileName( const char* in_kpcLogFileName );

#ifndef PN_LOGGING_DISABLED
PN_LOGGER_API
void LOGGERWriteLog
(
    ELogLevel     in_eLogLevel,
    const char*   in_kpszModuleName,
    const char*   in_kpcFile, 
    int           in_iLine,
    ELogMessageID in_eMsgID,
    ...
);
#else
#define LOGGERWriteLog
#endif

#ifndef PN_LOGGING_DISABLED
#define LOG(l,m,...) LOGGERWriteLog(l, __sModuleName__, __FILE__, __LINE__, m, __VA_ARGS__)
#else
#define LOG
#endif

#ifdef __cplusplus
       } /* extern "C" */
#endif


#endif /* __PN_LOGGER_H__ */