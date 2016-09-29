#include "pst_events.h"
#include "ccpu_cmn.h"
#include "cmn_types.h"
#include "sfi.h"

typedef struct s_EventName
{
  UINT32 id;
  String50 name;
} EventName;

const EventName c_evtNameTab[] =
{
  { (EVT_START_QUERY - PWAV_START_EVENT),                     "EVT_START_QUERY"},
  { (EVT_START_IND - PWAV_START_EVENT),                       "EVT_START_IND"},

  { (EVT_HELLO - PWAV_START_EVENT),                           "EVT_HELLO"},
  { (EVT_HELLO_ACK - PWAV_START_EVENT),                       "EVT_HELLO_ACK"},

  { (EVT_EXIT - PWAV_START_EVENT),                            "EVT_EXIT"},

  { (EVT_BSM_CEM_OPSTART - PWAV_START_EVENT),                 "EVT_BSM_CEM_OPSTART"},
  { (EVT_CEM_BSM_OPSTART_SUCC - PWAV_START_EVENT),            "EVT_CEM_BSM_OPSTART_SUCC"},
  { (EVT_CEM_BSM_OPSTART_FAIL - PWAV_START_EVENT),            "EVT_CEM_BSM_OPSTART_FAIL"},

  { (EVT_BSM_CEM_OPSTOP_CMD - PWAV_START_EVENT),              "EVT_BSM_CEM_OPSTOP_CMD"},
  { (EVT_CEM_BSM_OPSTOP_CMPL - PWAV_START_EVENT),             "EVT_CEM_BSM_OPSTOP_CMPL"},

  { (EVT_BSM_CEM_CFG_REQ - PWAV_START_EVENT),                 "EVT_BSM_CEM_CFG_REQ"},
  { (EVT_CEM_BSM_CFG_SUCC - PWAV_START_EVENT),                "EVT_CEM_BSM_CFG_SUCC"},
  { (EVT_CEM_BSM_CFG_FAIL - PWAV_START_EVENT),                "EVT_CEM_BSM_CFG_FAIL"},

  { (EVT_BSM_S1M_CFG_REQ - PWAV_START_EVENT),                 "EVT_BSM_S1M_CFG_REQ"},
  { (EVT_S1M_BSM_CFG_SUCC - PWAV_START_EVENT),                "EVT_S1M_BSM_CFG_SUCC"},
  { (EVT_S1M_BSM_CFG_FAIL - PWAV_START_EVENT),                "EVT_S1M_BSM_CFG_FAIL"},

  { (EVT_BSM_S1M_OPSTART - PWAV_START_EVENT),                 "EVT_BSM_S1M_OPSTART"},
  { (EVT_S1M_BSM_OPSTART_SUCC - PWAV_START_EVENT),            "EVT_S1M_BSM_OPSTART_SUCC"},
  { (EVT_S1M_BSM_OPSTART_FAIL - PWAV_START_EVENT),            "EVT_S1M_BSM_OPSTART_FAIL"},

  { (EVT_BSM_S1M_OPSTOP_CMD - PWAV_START_EVENT),              "EVT_BSM_S1M_OPSTOP_CMD"},
  { (EVT_S1M_BSM_OPSTOP_CMPL - PWAV_START_EVENT),             "EVT_S1M_BSM_OPSTOP_CMPL"},

  { (EVT_S1M_LINK_UP_IND - PWAV_START_EVENT),                 "EVT_S1M_LINK_UP_IND"},
  { (EVT_S1M_LINK_DOWN_IND - PWAV_START_EVENT),               "EVT_S1M_LINK_DOWN_IND"},
  { (EVT_S1M_LINK_CLOSED_IND - PWAV_START_EVENT),             "EVT_S1M_LINK_CLOSED_IND"},

  { (EVT_BSM_UEH_ACTIVE_UE_STATUS_REQ - PWAV_START_EVENT),    "EVT_BSM_UEH_ACTIVE_UE_STATUS_REQ"},
  { (EVT_UEH_BSM_ACTIVE_UE_STATUS_RSP - PWAV_START_EVENT),    "EVT_UEH_BSM_ACTIVE_UE_STATUS_RSP"},

  { (EVT_BSM_UDH_ACTIVE_RAB_STATUS_REQ - PWAV_START_EVENT),   "EVT_BSM_UDH_ACTIVE_RAB_STATUS_REQ"},
  { (EVT_UDH_BSM_ACTIVE_RAB_STATUS_RSP - PWAV_START_EVENT),   "EVT_UDH_BSM_ACTIVE_RAB_STATUS_RSP"},

  { (EVT_S1M_RESET_IND - PWAV_START_EVENT),                   "EVT_S1M_RESET_IND"},

  { (EVT_BSM_SM_S1AP_CFG_REQ - PWAV_START_EVENT),             "EVT_BSM_SM_S1AP_CFG_REQ"},
  { (EVT_SM_BSM_S1AP_CFG_SUCC - PWAV_START_EVENT),            "EVT_SM_BSM_S1AP_CFG_SUCC"},
  { (EVT_SM_BSM_S1AP_CFG_FAIL - PWAV_START_EVENT),            "EVT_SM_BSM_S1AP_CFG_FAIL"},

  { (EVT_BSM_SM_SCTP_CFG_REQ - PWAV_START_EVENT),             "EVT_BSM_SM_SCTP_CFG_REQ"},
  { (EVT_SM_BSM_SCTP_CFG_SUCC - PWAV_START_EVENT),            "EVT_SM_BSM_SCTP_CFG_SUCC"},
  { (EVT_SM_BSM_SCTP_CFG_FAIL - PWAV_START_EVENT),            "EVT_SM_BSM_SCTP_CFG_FAIL"},

  { (EVT_BSM_SM_EGTP_CFG_REQ - PWAV_START_EVENT),             "EVT_BSM_SM_EGTP_CFG_REQ"},
  { (EVT_SM_BSM_EGTP_CFG_SUCC - PWAV_START_EVENT),            "EVT_SM_BSM_EGTP_CFG_SUCC"},
  { (EVT_SM_BSM_EGTP_CFG_FAIL - PWAV_START_EVENT),            "EVT_SM_BSM_EGTP_CFG_FAIL"},

  { (EVT_SM_LTH_TRC_IND - PWAV_START_EVENT),                "EVT_SM_LTH_TRC_IND"},

  { (EVT_LTH_SM_TRC_START_REQ - PWAV_START_EVENT),             "EVT_LTH_SM_TRC_START_REQ"},
  { (EVT_SM_LTH_TRC_START_SUCC - PWAV_START_EVENT),             "EVT_SM_LTH_TRC_START_SUCC"},
  { (EVT_SM_LTH_TRC_START_FAIL - PWAV_START_EVENT),             "EVT_SM_LTH_TRC_START_FAIL"},
  { (EVT_LTH_SM_TRC_STOP_REQ - PWAV_START_EVENT),             "EVT_LTH_SM_TRC_STOP_REQ"},
  { (EVT_SM_LTH_TRC_STOP_SUCC - PWAV_START_EVENT),             "EVT_SM_LTH_TRC_STOP_SUCC"},
  { (EVT_SM_LTH_TRC_STOP_FAIL - PWAV_START_EVENT),             "EVT_SM_LTH_TRC_STOP_FAIL"},

  { (EVT_BSM_UDH_CFG_REQ - PWAV_START_EVENT),                   "EVT_BSM_UDH_CFG_REQ"},
  { (EVT_UDH_BSM_CFG_SUCC - PWAV_START_EVENT),                  "EVT_UDH_BSM_CFG_SUCC"},
  { (EVT_UDH_BSM_CFG_FAIL - PWAV_START_EVENT),                  "EVT_UDH_BSM_CFG_FAIL"},

  { (EVT_BSM_UDH_OPSTART - PWAV_START_EVENT),                   "EVT_BSM_UDH_OPSTART"},
  { (EVT_UDH_BSM_OPSTART_SUCC - PWAV_START_EVENT),              "EVT_UDH_BSM_OPSTART_SUCC"},
  { (EVT_UDH_BSM_OPSTART_FAIL - PWAV_START_EVENT),              "EVT_UDH_BSM_OPSTART_FAIL"},

  { (EVT_BSM_UDH_OPSTOP_CMD - PWAV_START_EVENT),                "EVT_BSM_UDH_OPSTOP_CMD"},
  { (EVT_UDH_BSM_OPSTOP_CMPL - PWAV_START_EVENT),               "EVT_UDH_BSM_OPSTOP_CMPL"},

  { (EVT_PMH_SM_PDCP_GEN_STAT_REQ - PWAV_START_EVENT),          "EVT_PMH_SM_PDCP_GEN_STAT_REQ"},
  { (EVT_PMH_SM_PDCP_UPLANE_STAT_REQ - PWAV_START_EVENT),       "EVT_PMH_SM_PDCP_UPLANE_STAT_REQ"},

  { (EVT_PMH_SM_SCTP_GEN_STAT_REQ - PWAV_START_EVENT),          "EVT_PMH_SM_SCTP_GEN_STAT_REQ"},
  { (EVT_PMH_SM_GTP_GEN_STAT_REQ - PWAV_START_EVENT),           "EVT_PMH_SM_GTP_GEN_STAT_REQ"},
  { (EVT_PMH_SM_RLC_GEN_STAT_REQ - PWAV_START_EVENT),           "EVT_PMH_SM_RLC_GEN_STAT_REQ"},

  { (EVT_PMH_SM_RRC_GEN_STAT_REQ - PWAV_START_EVENT),           "EVT_PMH_SM_RRC_GEN_STAT_REQ"},
  { (EVT_PMH_SM_RRC_CELL_STAT_REQ - PWAV_START_EVENT),          "EVT_PMH_SM_RRC_CELL_STAT_REQ"},

  { (EVT_PMH_SM_S1AP_GEN_STAT_REQ - PWAV_START_EVENT),          "EVT_PMH_SM_S1AP_GEN_STAT_REQ"},
  { (EVT_PMH_SM_S1AP_PEER_NODE_STAT_REQ - PWAV_START_EVENT),    "EVT_PMH_SM_S1AP_PEER_NODE_STAT_REQ"},

  { (EVT_PMH_SM_MAC_GEN_STAT_REQ - PWAV_START_EVENT),           "EVT_PMH_SM_MAC_GEN_STAT_REQ"},
  { (EVT_PMH_SM_MAC_RLCSAP_STAT_REQ - PWAV_START_EVENT),        "EVT_PMH_SM_MAC_RLCSAP_STAT_REQ"},
  { (EVT_PMH_SM_MAC_PHYSAP_STAT_REQ - PWAV_START_EVENT),        "EVT_PMH_SM_MAC_PHYSAP_STAT_REQ"},

  { (EVT_SM_PMH_PDCP_GEN_STAT_RSP - PWAV_START_EVENT),          "EVT_SM_PMH_PDCP_GEN_STAT_RSP"},
  { (EVT_SM_PMH_PDCP_UPLANE_STAT_RSP - PWAV_START_EVENT),       "EVT_SM_PMH_PDCP_UPLANE_STAT_RSP"},

  { (EVT_SM_PMH_SCTP_GEN_STAT_RSP - PWAV_START_EVENT),          "EVT_SM_PMH_SCTP_GEN_STAT_RSP"},
  { (EVT_SM_PMH_GTP_GEN_STAT_RSP - PWAV_START_EVENT),           "EVT_SM_PMH_GTP_GEN_STAT_RSP"},
  { (EVT_SM_PMH_RLC_GEN_STAT_RSP - PWAV_START_EVENT),           "EVT_SM_PMH_RLC_GEN_STAT_RSP"},

  { (EVT_SM_PMH_RRC_GEN_STAT_RSP - PWAV_START_EVENT),           "EVT_SM_PMH_RRC_GEN_STAT_RSP"},
  { (EVT_SM_PMH_RRC_CELL_STAT_RSP - PWAV_START_EVENT),          "EVT_SM_PMH_RRC_CELL_STAT_RSP"},

  { (EVT_SM_PMH_S1AP_GEN_STAT_RSP - PWAV_START_EVENT),          "EVT_SM_PMH_S1AP_GEN_STAT_RSP"},
  { (EVT_SM_PMH_S1AP_PEER_NODE_STAT_RSP - PWAV_START_EVENT),    "EVT_SM_PMH_S1AP_PEER_NODE_STAT_RSP"},

  { (EVT_SM_PMH_MAC_GEN_STAT_RSP - PWAV_START_EVENT),           "EVT_SM_PMH_MAC_GEN_STAT_RSP"},
  { (EVT_SM_PMH_MAC_RLCSAP_STAT_RSP - PWAV_START_EVENT),        "EVT_SM_PMH_MAC_RLCSAP_STAT_RSP"},
  { (EVT_SM_PMH_MAC_PHYSAP_STAT_RSP - PWAV_START_EVENT),        "EVT_SM_PMH_MAC_PHYSAP_STAT_RSP"},

  { (EVT_BSM_UEH_MOD_STATE_REQ - PWAV_START_EVENT),              "EVT_BSM_UEH_MOD_STATE_REQ"},
  { (EVT_UEH_BSM_MOD_STATE_RSP - PWAV_START_EVENT),              "EVT_BSM_UEH_MOD_STATE_RSP"},

  { (EVT_BSM_UDH_MOD_STATE_REQ - PWAV_START_EVENT),              "EVT_BSM_UDH_MOD_STATE_REQ"},
  { (EVT_UDH_BSM_MOD_STATE_RSP - PWAV_START_EVENT),              "EVT_BSM_UDH_MOD_STATE_RSP"},
  
  { (EVT_BSM_UEH_UE_EVENT_HISTORY_REQ - PWAV_START_EVENT),      "EVT_BSM_UEH_UE_EVENT_HISTORY_REQ"},
  { (EVT_UEH_BSM_UE_EVENT_HISTORY_RSP - PWAV_START_EVENT),      "EVT_UEH_BSM_UE_EVENT_HISTORY_RES"},

  { (EVT_BSM_UDH_RAB_HISTORY_REQ - PWAV_START_EVENT),   "EVT_BSM_UDH_RAB_HISTORY_REQ"},
  { (EVT_UDH_BSM_RAB_HISTORY_RSP - PWAV_START_EVENT),   "EVT_UDH_BSM_RAB_HISTORY_RSP"},
  // RRM Changes
  { (EVT_PMH_UEH_RRM_CELL_STAT_REQ - PWAV_START_EVENT),    "EVT_PMH_UEH_RRM_CELL_STAT_REQ"},
  { (EVT_UEH_PMH_RRM_CELL_STAT_RSP - PWAV_START_EVENT),    "EVT_UEH_PMH_RRM_CELL_STAT_RSP"},
  { (EVT_UEH_BSM_UNKWN_ENB_UE_ID_IND - PWAV_START_EVENT),   "EVT_UEH_BSM_UNKWN_ENB_UE_ID_IND"}, 
  { (EVT_BSM_SM_SET_LOG_CFG - PWAV_START_EVENT),   "EVT_BSM_SM_SET_LOG_CFG"},
  { (EVT_PMH_TFU_DSTATS_CFG_REQ - PWAV_START_EVENT), "EVT_PMH_TFU_DSTATS_CFG_REQ"},
  { (EVT_TFU_PMH_DSTATS_IND - PWAV_START_EVENT), "EVT_TFU_PMH_DSTATS_IND"},

  { (EVT_PMH_UDH_DSTAT_REQ - PWAV_START_EVENT), "EVT_PMH_UDH_DSTAT_REQ"},
  { (EVT_UDH_PMH_DSTAT_RSP - PWAV_START_EVENT), "EVT_UDH_PMH_DSTAT_RSP"},
  { (EVT_BSM_UEH_UEEVENTHISTORYLOG_CONFIG_REQ - PWAV_START_EVENT), "EVT_BSM_UEH_UEEVENTHISTORYLOG_CONFIG_REQ"},
  { (EVT_UEH_BSM_UEEVENTHISTORYLOG_CONFIG_SUCC - PWAV_START_EVENT), "EVT_UEH_BSM_UEEVENTHISTORYLOG_CONFIG_SUCC"},
  { (EVT_UEH_BSM_UEEVENTHISTORYLOG_CONFIG_FAIL - PWAV_START_EVENT), "EVT_UEH_BSM_UEEVENTHISTORYLOG_CONFIG_FAIL"},
  // Done
  //BS-1799 Cell barring procedure
  { (EVT_BSM_CEM_CELL_BAR_REQ - PWAV_START_EVENT),    "EVT_BSM_CEM_CELL_BAR_REQ"},
  { (EVT_BSM_CEM_CELL_UNBAR_REQ - PWAV_START_EVENT),    "EVT_BSM_CEM_CELL_UNBAR_REQ"},
  { (EVT_CEM_BSM_CELL_BAR_SUCC - PWAV_START_EVENT),   "EVT_CEM_BSM_CELL_BAR_SUCC"}, 
  { (EVT_CEM_BSM_CELL_UNBAR_SUCC - PWAV_START_EVENT),   "EVT_CEM_BSM_CELL_UNBAR_SUCC"},

  { (EVT_UEH_PMH_COUNTER_START_SUCC - PWAV_START_EVENT),   "EVT_UEH_PMH_COUNTER_START_SUCC"},
  { (EVT_UEH_PMH_COUNTER_START_FAIL - PWAV_START_EVENT),   "EVT_UEH_PMH_COUNTER_START_FAIL"},
  { (EVT_UEH_PMH_COUNTER_STOP_SUCC - PWAV_START_EVENT),   "EVT_UEH_PMH_COUNTER_STOP_SUCC"},
  { (EVT_UEH_PMH_COUNTER_REPORT_IND - PWAV_START_EVENT),   "EVT_UEH_PMH_COUNTER_REPORT_IND"},
  { (EVT_UEH_PMH_COUNTER_STOP_IND - PWAV_START_EVENT),   "EVT_UEH_PMH_COUNTER_STOP_IND"},
  {0,                             ""}
};

char* getEventName(U32 evtId)
{
  if (evtId < PWAV_START_EVENT)
  {
	  return "UNKNOWN";
  }
  if (evtId > MAX_PWAV_EVENT)
  {
	  return "TOO-LARGE";
  }
  return &(c_evtNameTab[(evtId - PWAV_START_EVENT)].name[0]);
}
