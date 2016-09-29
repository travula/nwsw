/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 19302 2010-08-13 12:19:42Z dts12 $
 */
#ifndef SCTPGENCOUNTERS_H
#define SCTPGENCOUNTERS_H

/* function declarations */
void init_sctpGenCounters(void);
void initialize_table_sctpGenCountersTable(void);
Netsnmp_Node_Handler sctpGenCountersTable_handler;
Netsnmp_First_Data_Point  sctpGenCountersTable_get_first_data_point;
Netsnmp_Next_Data_Point   sctpGenCountersTable_get_next_data_point;

/* column number definitions for table sctpGenCountersTable */
       #define COLUMN_SCTP_GEN_COUNTERS_INDEX		1
       #define COLUMN_NOINITTX				2
       #define COLUMN_NOINITRETX			3
       #define COLUMN_NOINITRX				4
       #define COLUMN_NOIACKTX				5
       #define COLUMN_NOIACKRX				6
       #define COLUMN_NOSHDWNTX				7
       #define COLUMN_NOSHDWNRETX			8
       #define COLUMN_NOSHDWNRX				9
       #define COLUMN_NOSHDWNACKTX			10
       #define COLUMN_NOSHDWNACKRETX			11
       #define COLUMN_NOSHDWNACKRX			12
       #define COLUMN_NOCOOKIETX			13
       #define COLUMN_NOCOOKIERETX			14
       #define COLUMN_NOCOOKIERX			15
       #define COLUMN_NOCKACKTX				16
       #define COLUMN_NOCKACKRX				17
       #define COLUMN_NODATATX				18
       #define COLUMN_NODATARETX			19
       #define COLUMN_NODATARX				20
       #define COLUMN_NODACKTX				21
       #define COLUMN_NODACKRX				22
       #define COLUMN_NOSHDWNCMPLTTX			23
       #define COLUMN_NOSHDWNCMPLTRX			24
       #define COLUMN_NOHBEATTX				25
       #define COLUMN_NOHBEATRX				26
       #define COLUMN_NOHBACKTX				27
       #define COLUMN_NOHBACKRX				28
       #define COLUMN_NOABORTTX				29
       #define COLUMN_NOABORTRX				30
       #define COLUMN_NOERRORTX				31
       #define COLUMN_NOERRORRX				32
       #define COLUMN_NOECNETX				33
       #define COLUMN_NOECNERETX			34
       #define COLUMN_NOECNERX				35
       #define COLUMN_NOCWRTX				36
       #define COLUMN_NOCWRRX				37
       #define COLUMN_NOQUERYTX				38
       #define COLUMN_NOQUERYRETX			39
       #define COLUMN_NOQUERYRSPRX			40
       #define COLUMN_SCTP_GEN_COUNTERS_LASTCOLLECTEDAT 41 

#define SCTP_GEN_COUNTERS_MAX_COL   COLUMN_SCTP_GEN_COUNTERS_LASTCOLLECTEDAT

#define SCTP_GEN_COUNTERS_LCOLLECT_BUF_LEN_MAX 18


    /* Typical data structure for a row entry */
typedef struct sctpGenCountersTable_entry {
    /* Index values */
    unsigned int index;

    /* Column values */
    unsigned int noInitTx;
    unsigned int noInitReTx;
    unsigned int noInitRx;
    unsigned int noIAckTx;
    unsigned int noIAckRx;
    unsigned int noShDwnTx;
    unsigned int noShDwnReTx;
    unsigned int noShDwnRx;
    unsigned int noShDwnAckTx;
    unsigned int noShDwnAckReTx;
    unsigned int noShDwnAckRx;
    unsigned int noCookieTx;
    unsigned int noCookieReTx;
    unsigned int noCookieRx;
    unsigned int noCkAckTx;
    unsigned int noCkAckRx;
    unsigned int noDataTx;
    unsigned int noDataReTx;
    unsigned int noDataRx;
    unsigned int noDAckTx;
    unsigned int noDAckRx;
    unsigned int noShDwnCmpltTx;
    unsigned int noShDwnCmpltRx;
    unsigned int noHBeatTx;
    unsigned int noHBeatRx;
    unsigned int noHBAckTx;
    unsigned int noHBAckRx;
    unsigned int noAbortTx;
    unsigned int noAbortRx;
    unsigned int noErrorTx;
    unsigned int noErrorRx;
    unsigned int noEcneTx;
    unsigned int noEcneReTx;
    unsigned int noEcneRx;
    unsigned int noCwrTx;
    unsigned int noCwrRx;
    unsigned int noQueryTx;
    unsigned int noQueryReTx;
    unsigned int noQueryRspRx;
    char lastCollectedAt[SCTP_GEN_COUNTERS_LCOLLECT_BUF_LEN_MAX];
    size_t lastCollectedAt_len;

    /* Illustrate using a simple linked list */
    int   valid;
    struct sctpGenCountersTable_entry *next;
}sctpGenCountersTableEntry;

#endif /* SCTPGENCOUNTERS_H */